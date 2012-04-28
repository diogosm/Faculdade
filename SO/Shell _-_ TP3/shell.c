/*
	Terceiro Trabalho Prático de SO
	Alunos:
		Cassio de Paula
		Diogo Soares
		Paulo Leite Jr. 
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <regex.h>		/*biblioteca de erros*/
#include <string.h>		
#include <readline/readline.h>	/*lib de*/ 
#include <sys/wait.h>
#include <errno.h>

#include "parse.h"

#define CHEU_PROMPT	"[%d]shell> "

pid_t interpreta_comando(const char *linha_cmd, int *fds, int pipe_lr, FILE *fp) {
	regmatch_t *match1/*, *match2*/;
	char *str1/*, *str2*/;
	char **args;
	char nome[1000];
	char *redir_file_str;
	int redir_rw = -1; /* flag que indica redirecionamento de entrada (0) ou saida (1) */

	if ((match1 = match_redir(linha_cmd))) {
		/* comando com redirecionamento */
		/* obtem comando + argumentos */
		str1 = get_match(linha_cmd, match1, 1);
		if (str1) {
			/* faz o parsing dos argumentos */
			args = parse_cmd(str1);
			if (!args) {
				free(str1);
				free(match1);
				return 0;
			}
			free(str1);
		}
		/* obtem nome do arquivo para redirecionamento */
		str1 = get_match(linha_cmd, match1, 2);	
		if (str1) {
			redir_file_str = str1;
			if (strchr(linha_cmd, '>')) {
				/* redirecionamento de saída */
				printf("*** Redirecionando saída para %s\n", str1);
				redir_rw = 1;
			} else {
				/* redirecionamento de entrada */
				printf("*** Redirecionando entrada de %s\n", str1);
				redir_rw = 0;
			}
		}
		free(match1);
	} else if ((match1 = match_cmd(linha_cmd))) {
		/* comando simples (sem redirecionamento ou pipe) */
		fprintf(fp, "\nExecutando o processo [%s]", linha_cmd);
		free(match1);
		args = parse_cmd(linha_cmd);
		if (!args) {
			return 0;
		}
	} else {
		printf("Erro de sintaxe na linha de comando!\n");
		return 0;
	}

	/* executa o comando */
	if (!strcmp(args[0], "cd")) {
		/* se cd nao tiver nenhum argumento, mudar para o HOME
		 * do usuário (comportamento do bash) */
		if (strcmp("~", args[1]) == 0 ) {
			printf("pooo22");
			chdir("/home/diogo");
		}		
		if (!args[1]) {
			args[1] = getenv("HOME");
		}
		if (chdir(args[1])) {
			perror("cd");
		}
		
	} else if (!strcmp(args[0], "pwd")) {
		char *cur_dir = getcwd(NULL, 0);
		if (!cur_dir) {
			perror("pwd");
		}
		printf("%s\n", cur_dir);
		free(cur_dir);
	} else if (!strcmp(args[0], "exit")) {
		exit(0);
	} else if (!strcmp(args[0], "ajuda")) {
		printf("SHELL de SO \nComandos nativos: cd pwd exit ajuda\n");
	} else {
		/* comando não nativo: executar binário do sistema */
		pid_t pid;

		/*printf("*** Execução do programa \"%s\"\n", args[0]);*/
		/* faz o fork do processo do shell */
		pid = fork();
		if (pid == 0) { /* processo-filho */
			FILE *redir_file;

			if (redir_rw == 0) {
				redir_file = freopen(redir_file_str, "r", stdin);
			} else if (redir_rw == 1) {
				redir_file = freopen(redir_file_str, "w", stdout);
			}
			if (!redir_file) {
				printf("*** %s: %s\n", redir_file_str, strerror(errno));
				exit(1);
			}
			if (pipe_lr == 0) {
				/* lado esquerdo do pipe */
				close(fds[0]); /* fecha descritor de leitura */
				dup2(fds[1], fileno(stdout));
				close(fds[1]);
			} else if (pipe_lr == 1) {
				/* lado direito do pipe */
				close(fds[1]); /* fecha descritor de escrita */
				dup2(fds[0], fileno(stdin));
				close(fds[0]);
			}
			if (execvp(args[0], args) == -1) {
				if (errno == ENOENT) {
					printf("Erro: %s: comando não encontrado\n", args[0]);
				} else {
					/* erro desconhecido */
					perror("execvp");
				}
				exit(1);
			}
		} else if (pid > 0) { /* processo-pai */
			free(args);
			return pid;
		} else {
			perror("fork");
			return 0;
		}
	}
	return 0;
}

int main(int argc, char **argv) {


	FILE *fp = fopen("in.txt", "w");
	while (1) {
		char *linha_cmd, *cmd1, *cmd2;
		char prompt[100];
		regmatch_t *match;

		/* coloca PID do processo do shell no prompt (para diferenciar
		 * shells aninhados) */
		snprintf(prompt, 100, CHEU_PROMPT, getpid());

		/* obtém linha de comando do usuário */
		linha_cmd = readline(prompt);
		if (!linha_cmd) {
			fprintf(fp, "\n*** Cheu interrompido ***\n");
			printf("\n*** Cheu interrompido ***\n");
			exit(1);
		}
		/* nenhum comando digitado */
		if (!strlen(linha_cmd)) {
			free(linha_cmd);
			continue;
		}
		if ((match = match_pipe(linha_cmd))) {
			/* comandos em pipe */
			cmd1 = get_match(linha_cmd, match, 1);		/*retorna o valor escrito para cmd*/
			cmd2 = get_match(linha_cmd, match, 4);
			/*printf("*** Execução em pipe: cmd1 = \"%s\", cmd2 = \"%s\"\n", cmd1, cmd2);*/
			if (cmd1 && cmd2) {
				fprintf(fp, "\nIniciando um pipe [%s] [%s]", cmd1, cmd2);
				int fds[2], status;
				pid_t pid1, pid2;

				/* abre um pipe para leitura/escrita */

				pipe(fds);
				/* executa processo leitor (que ficará
				 * esperando o processo escritor escrever no
				 * pipe) */
				pid1 = interpreta_comando(cmd2, fds, 1, fp);
				/* executa leitor do pipe */
				pid2 = interpreta_comando(cmd1, fds, 0, fp);
				/* fecha pipe */
				close(fds[0]);
				close(fds[1]);
				if (!pid1 || !pid2) {
					continue;
				}
				/* espera pelo término do processo leitor */
				while (wait(&status) != pid2) ;
				free(cmd1);
				free(cmd2);
			}
			free(match);
		} else {
			fprintf(fp, "\nIniciando um comando unico [%s]", linha_cmd);
			int status;
			pid_t pid;

			pid = interpreta_comando(linha_cmd, NULL, -1, fp);
			if (!pid) {
				continue;
			}
			while (wait(&status) != pid) ;
		}
		free(linha_cmd);
	}
	fclose(fp);
	return 0;
}
