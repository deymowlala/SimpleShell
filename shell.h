#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *					allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


/* hsh.c */  
int hshs(info_t *infor, char **ava);
int find_builtinoz(info_t *infor);
void find_cmdp(info_t *infor);
void fork_cmdp(info_t *info);

/* path.c */
int is_cmdo(info_t *infor, char *pather);
char *dp_char(char *strpaht, int srt, int end);
char *find_path(info_t *info, char *pathstr, char *cmd) 

/* loophsh.c */
int loophsh(char **);

/* err_string_functions.c */
void _eprints(char *strn);
int _ewchar(char chara);
int _putss(char cr, int fdr);
int _prints(char *strngo, int fdr);

/* string_functions.c */
int _strleno(char *str);
int _strcompy(char *strA, char *strB);
char *start_with(const char *haystacker, const char *needlez);
 char *_scat(char *destin, char *souc);

/* string_functions2.c */
char *_scpy(char *destin, char *souc);
char *_strduplo(const char *strg);
void _prs(char *strg);
int _putch(char chara);

/* string_functions3.c */
char *_strcp (char *destin, char *souc, int amo);
char *_strenocata(char *destin, char *souc, int amo);
char *_locha(char *sp, char cr);

/* string_functions4.c */
char **strtwp(char *stc, char *deli);
char **strtwp2(char *stc, char deli);

/* memory_functions */
char *_mset(char *sp, char bp, unsigned int un);
void ffre(char **pis);
void *_reocte(void *potry, unsigned int olsize, unsigned int nwsize);

/* memory_functions2.c */
int fpsn(void **ptf);

/* more_functions.c */
int interactiveto(info_t *infor);
int is_delimot(char cchek, char *delimot);
int _isalphat(int inpc);
int _acsi(char *srng);

/* more_functions2.c */
int _ertol(char *sc);
void print_errmsg(info_t *infor, char *errstr);
int print_dten(int inp, int fdw);
char *convt_num(long int numb, int bse, int flagor);
void rm_commn(char *badrs);

/* builtin_emulators.c */ //demola
int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);

/* builtin_emulators2.c */ //demola
int _myhistory(info_t *);
int _myalias(info_t *);

/* getline.c module */
ssize_t inputr_buff(info_t *infor, char **buff, size_t *lend);
ssize_t get_inputr(info_t *infor);
void sigintHan(__attribute__((unused))int sig_n);

/* info.c module */
void cles_info(info_t *infore);
void st_infor(info_t *infor, char **amv);
void fre_infor(info_t *infor, int allfre);

/* env.c module */
int _myent(info_t *infor);
char *_getent(info_t *infor, const char *nment);
int _mysetent(info_t *infor);
int _myunsetent(info_t *infor);
int populat_ent_lista(info_t *infor);

/* env2.c module */
char **get_envir(info_t *infor);
int _unsetent(info_t *infor, char *varprop);
int _setent(info_t *infor, char *varprop, char *valuevar);

/* file_io_functions.c */ //demola
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);

/* liststr.c module */
list_t *ad_nod(list_t **header, const char *stnod, int ndhis);
list_t *ad_nod_nd(list_t **header, const char *stnod, int ndhis);
size_t prin_list_strg(const list_t *pointer);
int delete_node_at_indexer(list_t **header, unsigned int indexer);
void frees_lista(list_t **head_ptrh);

/* liststr2.c module */
size_t lista_leng(const list_t *ponf);
char **lista_to_stringo(list_t *header);
size_t printo_lista(const list_t *hpx);
list_t *nodes_start_wz(list_t *nodez, char *prefixa, char chara);
ssize_t gota_nod_indexer(list_t *header, list_t *nodez);

/* chain.c */ //demola
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

#endif
