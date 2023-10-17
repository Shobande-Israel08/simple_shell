#ifndef _SHELL_H_
#define _SHELL_H_


#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1


#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3


#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2


#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

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

extern char **environ;


/**
 * struct mystr - singly linked list
 * @num:the num field
 * @str:the string
 * @next:the next node pointer
 */
typedef struct mystr
{
	int num;
	char *str;
	struct mystr *next;
} my_list;

/**
 * struct passinfo - possess pseudo-arguements to pass into a function,
 * allowing uniform prototype for function pointer struct
 * @arg: a string generated from getline containing arguements
 * @argv:an array of strings generated from arg
 * @path: a string path for the current command
 * @argc: the argument count
 * @line_count: the error count
 * @err_num: exit()s error code
 * @linecount_flag: if on count this line of input
 * @fname: the filename program
 * @env: linked list local copy of environ
 * @environ: custom modified copy of environ from LL environ
 * @history: the node history
 * @alias: the alias node
 * @env_changed: on if environ was changed
 * @status: the return status of the last exec'd command
 * @cmd_buf: address of cmd_buf pointer, on if chaining
 * @cmd_buf_type: CMD_type ||, &&,;
 * @readfd: the fd from which to read line input
 * @histcount:the line number count history
 * by nexttosho
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
	my_list *env;
	my_list *history;
	my_list *alias;
	char **environ;
	int env_changed;
	int status;
	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_l;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

/**
 * struct builtin - contain the builtin string and related function
 * @type: the command flag builtin
 * @func: the function
 * by nexttosho
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_l *);
} builtin_table;


int hsh(info_l *, char **);
int find_builtin(info_l *);
void find_cmd(info_l *);
void fork_cmd(info_l *);

int i_cmd(info_l *, char *);
char *dap_chars(char *, int, int);
char *phind_path(info_l *, char *, char *);

int loophsh(char **);

void eputs1(char *);
int _eputcha1(char);
int _iput1fd(char c, int fd);
int _iput2fd(char *str, int fd);

int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

char *_strancpy(char *, char *, int);
char *_strancat(char *, char *, int);
char *_stranchr(char *, char);


char **strtow(char *, char *);
char **strtow2(char *, char);


char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);


int bfree(void **);


int interactive(info_l *);
int l_delim(char, char *);
int alpha1(int);
int inta(char *);


int _erra1(char *);
void outprint_error(info_l *, char *);
int print_p(int, int);
char *number_changer(long int, int, int);
void comments_removal(char *);


int _myquit(info_l *);
int _mydisk(info_l *);
int _myhelp(info_l *);


int histo1(info_l *);
int _newalias(info_l *);


ssize_t get_insert(info_l *);
int _getline1(info_l *, char **, size_t *);
void signintHandle(int);


void clear_info(info_l *);
void set_info(info_l *, char **);
void free_info(info_l *, int);


char *getenv1(info_l *, const char *);
int myenv1(info_l *);
int mysetenv1(info_l *);
int myunsetenv1(info_l *);
int populate_env_list(info_l *);


char **get_environ(info_l *);
int _unsetenv(info_l *, char *);
int _setenv(info_l *, char *, char *);


char *get_history_file(info_l *info);
int write_history(info_l *info);
int read_history(info_l *info);
int build_history_list(info_l *info, char *buf, int linecount);
int renumber_history(info_l *info);


my_list *add_node(my_list **, const char *, int);
my_list *add_node_end(my_list **, const char *, int);
size_t print_list_str(const my_list *);
int delete_node_at_index(my_list **, unsigned int);
void free_list(my_list **);


size_t list_len(const my_list *);
char **list_to_strings(my_list *);
size_t print_list(const my_list *);
my_list *node_starts_with(my_list *, char *, char);
ssize_t get_node_index(my_list *, my_list *);


int is_chain(info_l *, char *, size_t *);
void check_chain(info_l *, char *, size_t *, size_t, size_t);
int replace_alias(info_l *);
int replace_vars(info_l *);
int replace_string(char **, char *);

#endif
