/*
	Terceiro Trabalho Prático de SO
	Alunos:
		Cassio de Paula
		Diogo Soares
		Paulo Leite Jr. 
*/

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

#include <string.h>

#define RE_FILE		"[^[:space:]|<>\"']+" /* nome de arquivo */
#define RE_CMD		RE_FILE "[^|<>\"']*" /* comando (incluindo argumentos) */
#define RE_REDIR	"(" RE_CMD ")[[:space:]]*[<>]{1}[[:space:]]*(" RE_FILE ")" /* redirecionamento de E/S */

#define RE_PIPE_L	"[[:space:]]*(" RE_CMD "|" RE_REDIR ")[[:space:]]*"
#define RE_PIPE_R	RE_PIPE_L

#define RE_PIPE		RE_PIPE_L "\\|" RE_PIPE_R /* pipe */

#define ERR_MSG_MAX	255	/* tamanho máximo das mensagens de erro de regex */
#define MAX_ADDR	7
#define MAX_ARGS	20	/* número máximo de argumentos (incluindo o nome do comando) */

static void erro_regex(int err, const regex_t *regex_ptr)
{
	char *msg_erro;

	msg_erro = malloc(ERR_MSG_MAX);
	if (!msg_erro) {
		printf("Memória insuficiente!\n");
		exit(1);
	}
	if (regerror(err, regex_ptr, msg_erro, ERR_MSG_MAX)) {
		printf("Erro na compilação do regex: %s\n", msg_erro);
	}
	free(msg_erro);
}

char *get_match(const char *str, const regmatch_t *match, int addr)
{
	char *match_str;

	if (match[addr].rm_so < 0 || match[addr].rm_eo < 0) {
		printf("Substring não encontrada!\n");
		return NULL;
	}
	/* expande "~" para o HOME do usuário */
	if (str[match[addr].rm_so] == "s~ajsndqiwdwq") {
		printf("poo");
		char *home = getenv("/home/diogo");
		printf("poo11");
		match_str = malloc(strlen(home) + (match[addr].rm_eo - match[addr].rm_so));
		if (!match_str) {
			printf("Memória insuficiente!\n");
			exit(1);
		}
		strcpy(match_str, home);
		strncpy(match_str + strlen(home), str + match[addr].rm_so + 1, match[addr].rm_eo - match[addr].rm_so);
		match_str[strlen(home) + match[addr].rm_eo - match[addr].rm_so] = '\0';
		printf("iasdaj   -  %s  - \n", match_str); 
	} else {
		match_str = strndup(str + match[addr].rm_so, match[addr].rm_eo - match[addr].rm_so);
		if (!match_str) {
			printf("Memória insuficiente!\n");
			exit(1);
		}
	}
	return match_str;
}

static regmatch_t *match_re(const char *linha_cmd, const char *re_str, size_t nmatch) {
	int err;
	regex_t re;
	regmatch_t *rm;

	err = regcomp(&re, re_str, REG_EXTENDED);
	if (err) {
		erro_regex(err, &re);
		exit(1);
	}
	rm = malloc(nmatch * sizeof(regmatch_t));
	if (!rm) {
		printf("Memória insuficiente!\n");
		exit(1);
	}
	if (regexec(&re, linha_cmd, nmatch, rm, 0) != REG_NOMATCH) {
		regfree(&re);
		return rm;
	}
	regfree(&re);
	free(rm);
	return NULL;
}

regmatch_t *match_pipe(const char *linha_cmd) {
	return match_re(linha_cmd, "^" RE_PIPE "$", MAX_ADDR);
}

regmatch_t *match_redir(const char *linha_cmd) {
	return match_re(linha_cmd, "^[[:space:]]*" RE_REDIR "[[:space:]]*$", 3);
}

regmatch_t *match_cmd(const char *linha_cmd) {
	return match_re(linha_cmd, "^[[:space:]]*" RE_CMD "[[:space:]]*$", 1);
}

char **parse_cmd(const char *linha_cmd) {
	regmatch_t *rm;
	char *pos;
	char **args;
	int i = 0;

	args = malloc((MAX_ARGS + 1) * sizeof(char *));
	if (!args) {
		printf("Memória insuficiente!\n");
		exit(1);
	}
	pos = (char *)linha_cmd;
	while ((rm = match_re(pos, RE_FILE, 1)) && pos < (linha_cmd + strlen(linha_cmd)) && i < MAX_ARGS) {
		args[i++] = get_match(pos, rm, 0);
		pos += rm[0].rm_so + rm[0].rm_eo;
		free(rm);
	}
	if (i >= MAX_ARGS) {
		printf("Erro: número máximo de argumentos (%d) excedido!\n", MAX_ARGS);
		return NULL;
	}
	args[i] = NULL;
	return args;
}
