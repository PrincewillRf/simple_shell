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
	char *input;
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
struct sep_list *next;
} sepe_list;

typedef struct lin_list_s
{
char *line;
struct line_list_s *next;
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
	int (*func)(data_shell *datashell);
} builtin_table;

/* toem_lists.c */
sep_list *add_node(sep_list **head,  char sep);
line_list *add_node_end(line_list **head, char line);
void free_sep_list(sep_list **head);
void free_list(line_list **head);

/* toem_lists1.c */
r_vari *add_rvar_node(r_vari **head, int var1, char *vari, int val1);
void free_rvari_list(r_vari **head);

/*aux_str functions */
char *_strcat(char *desti, const char *sour);
char *_strcpy(char *desti, char *sour);
int _strcmp(char *str, char c);
char *_strchr(char *str, char c);
int _strspn(char *str, char *accep);

/* aux_mem.c */
void _memcpy(void *newpt, const void *pt, unsigned int size);
void *_realloc(void *pt, unsigned int old1_size, unsigbed int new1_size);
char **_reallocdp(char **pt, unsigned int old1_size, unsigned int new1_size0;

/*aux_str1.c */
char *_strdup(const char *str);
int _strlen(const char *str);
int cmp_chars(char str1[], const char *delimt);
char *_strtok(char str1[], const char *delimt);
int _isdigit(const char *str);


/* aux_str2.c */
void rev_string(char *str);

/* check_syntax_error.c */
int repeated_char(char *input, int a);
int error_sep_op(char *input, int *a);
int first_char(char *input, int *a);
void print_syntax_error(data_shell *datashell, char *input, int a, int bool);
int check_syntax_eror(data_shell *datashell, char *input);

/* read_line.c */
char *read_line(int *i_eof);

/* split.c */
char *swap_char(char *input, int bool);
void sum_nodes(sep_list **head_s, line_list **head_1, char *input);
void go_nex(sep_list **list_s, line_list **list_2, data_shell *datashell);
int divide_commands(data_shell *datashell, char *input);
char **divide_line(char *input);

/* rep_var.c */
void chek_env( r_vari **h, char *inn, data_shell *data);
int chek_vars(r_vari **h, char *inn, char *st, data_shell *data);
char *replaced_input(r_vari **head, char *input, char *new_input1, int nleng);
char *rep_var(char *input, data_shell *datashell);

/* exec_line.c */
int exec_line(data_shell *datashell);

/* cmd_exec.c */
int is_cdire(char *path, int *a);
char *_whic(char *cmd, char **_environ);
int is_exetable(data_shell *datashell);
int chek_eror_cmd(char *dire, data_shell *datashell);
int cmd_exe(data_shell *datashell);

/* env1.c */
char *_getenv(const char *name1, char **_environ);
int _env(data_shell *datashell);

/* env2.c */
char *cpy_infor(char *name1, char *val);
void set_envn(char *name1, char *val, data_shell *datashell);
int _setenv(data_shell *datashell);
int _unsetenv(data_shell *datashell);

/*cd.c */
void cd_dot(data_shell *datashell);
void cd_to(data_shell *datashell);
void cd_prev(data_shell *datashell);
void cd_to_hom(data_shell *datashell);
/* cd_shell.c */
int cd_shel(data_shell *datashell);

#endif
