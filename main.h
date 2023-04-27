#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

/* for read/write buffers */
#define BUF_SIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a\"

/* Point to array of pointer to strings called environment */
extern char **environ;

/**
 *struct - data that contain all needed data at runtime
 *@argv: an arg vector
 *@argc: the argument count
 *@input: the command line written by the user
 *@statu: the previous status of the shell
 *@counter: line counter
 *@environ: environment variable
 */
typedef struct data
{
	char **av;
	char *insert;
	char **args;
	int status;
	int counter;
	char **_environ;
	int env_changed;
	char *pid;

} data_shell;

/**
*struct_sep_list_s - single linked list
*seperator : ; & | 
*next: next node
*description: single linked list that store seperator
*/
typedef struct sepe_list_s
{
char seperator;
struct sepe_list *next;
} sepe_list;

typedef struct lin_list_s
{
	char *lin;
	struct lin_list_s *next;
} lin_list;
	
/**
*struct r_vari_list - single linked list
*@leng_var:leng of variable
*@val: variable value 
*@leng_val: value's length
*@next: next node
*@desc: Single linked lists to store variable
*/
typedef struct r_vari_lists
{
	int leng_var;
	char *val;
	int leng_val;
	struct r_vari_list *next;
} r_vari;


/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command name like cd, exit, env
 *@func: the function datatype of pointer
 */
typedef struct builtin
{
	char *type;
	int (*func)(data_shell *datsh);
} builtin_table;

/* toem_lists.c */
sepe_list *add_node(sepe_list **head,  char sepe);
void free_sepe_list(sepe_list **head);
lin_list *add_node_end(lin_list **head, char lin);
void free_list(lin_list **head);

/* toem_lists1.c */
r_vari *add_rvar_node(r_vari **head, int var1, char *vari, int val1);
void free_rvari_list(r_vari **head);

/*aux_str functions */
char *_strcat(char *desti, const char *sour);
char *_strcpy(char *desti, char *sour);
int _strcmp(char *st1, char *st2);
char *_strchr(char *str, char c);
int _strspn(char *str, char *acept);

/* aux_mem.c */
void _memcpy(void *newpt, const void *pt, unsigned int siz);
void *_realloc(void *pt, unsigned int old1_siz, unsigned int new1_siz);
char **_reallocdp(char **pt, unsigned int old1_siz, unsigned int new1_siz);

/*aux_str1.c */
char *_strdup(const char *str);
int _strleng(const char *str);
int cmp_chars(char str1[], const char *delimt);
char *_strtok(char str1[], const char *delimt);
int _isdigit(const char *str);


/* aux_str2.c */
void rev_string(char *str);

/* check_syntax_error.c */
int repeated_char(char *insert, int a);
int eror_sep_op(char *insert, int *a);
int first_char(char *insert int *a);
void print_syntax_eror(data_shell *datsh, char *insert, int a, int bool);
int check_syntax_eror(data_shell *datsh, char *insert);

/* shell_loop */
char *without_comment(char *inn);
void shell_loop(data_shell *datsh);

/* read_line.c */
char *read_line(int *i_eof);

/* split.c */
char *swap_char(char *insert, int bool);
void sum_nodes(sepe_list **head_s, lin_list **head_1, char *insert);
void go_nex(sepe_list **list_s, lin_list **list_2, data_shell *datsh);
int divide_commands(data_shell *datsh, char *insert);
char **divide_line(char *insert);

/* rep_var.c */
void chek_env( r_vari **h, char *inn, data_shell *data);
int chek_vars(r_vari **h, char *inn, char *st, data_shell *data);
char *replaced_insert(r_vari **head, char *insert, char *new_insert1, int nleng);
char *rep_var(char *insert, data_shell *dats);

/* get_line.c */
void bring_line(char **linpt, size_t *num, char *buffer, size_t b);
ssize_t get_line(char **linpt, size_t *num, FILE *stream);

/* exec_line.c */
int exec_line(data_shell *datsh);

/* cmd_exec.c */
int is_cdire(char *path, int *a);
char *_whic(char *cmd, char **_environ);
int is_exetable(data_shell *datsh);
int chek_eror_cmd(char *dire, data_shell *datsh);
int cmd_exe(data_shell *datsh);

/* env1.c */
char *_getenv(const char *type, char **_environ);
int _env(data_shell *datash);

/* env2.c */
char *cpy_infor(char *type, char *val);
void set_envn(char *type, char *val, data_shell *datsh);
int _setenv(data_shell *datsh);
int _unsetenv(data_shell *datsh);

/*cd.c */
void cd_dot(data_shell *datsh);
void cd_to(data_shell *datsh);
void cd_prev(data_shell *datsh);
void cd_to_hom(data_shell *datsh);

/* cd_shell.c */
int cd_shel(data_shell *datsh);

/* get_builtin */
int (*get_builtin(char *cmd))(data_shell *datsh);

/* _exit.c */
int exit_shell(data_shell *datash);

/* aux_stilib.c */
int get_leng(int num);
char *aux_itoa(int num);
int _atoi(char *str);

/* aux_error1.c */
char *strcat_cd(data_shell *, char *, char *, char *);
char *eror_get_cd(data_shell *datsh);
char *eror_not_fond(data_shell *datsh;
char *eror_exit_shel(data_shell *datsh;

/* aux_eror2.c */
char *eror_get_alias(char **args);
char *eror_env(data_shell *datsh);
char *eror_syntax(char **args);
char *eror_permis(char **args);
char *eror_path_125(data_shell *datsh);

/* get_error.c */
int get_eror(data_shell *datsh, int evalu);

/* get_sigint.c */
void get_signit(int sign);

/* aux_help.c */
void aux_help_env(void);
void aux_help_setenv(void);
void aux_help_unsetenv(void);
void aux_help_general(void);
void aux_help_cd(void);

/* aux_help2.c */
void aux_help(void);
void aux_help_alias(void);
void aux_help_cd(void);

/* get_help.c */
int get_help(data_shell *datsh);

#endif
