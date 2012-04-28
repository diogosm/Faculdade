/*
	Terceiro Trabalho Prático de SO
	Alunos:
		Cassio de Paula
		Diogo Soares
		Paulo Leite Jr. 
*/

#include <regex.h>

extern char *get_match(const char *str, const regmatch_t *match, int addr);
extern regmatch_t *match_pipe(const char *linha_cmd);
extern regmatch_t *match_redir(const char *linha_cmd);
extern regmatch_t *match_cmd(const char *linha_cmd);
extern char **parse_cmd(const char *linha_cmd);
