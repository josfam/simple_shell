#ifndef SHELL_HEADER
#define SHELL_HEADER

/* Delimiters with which to tokenize inputs */
#define DELIMS " \n"

#define MAX_MEMPOOL_SIZE 50

/* struct to hold malloced memory locations that are tricky to free directly */
typedef struct memPool {
	char *memArray[MAX_MEMPOOL_SIZE];
	int nextFreeIndex;
} memPool;

/* Creates a mem pool, that stores memory locations */
memPool *create_mem_pool();

/* Adds a memory location to the memory pool. */
int append_memory(memPool *pool, char *memory);

/* Frees all memory locations in the memory pool. */
void free_mem_pool(memPool *pool);

/* Writes a character to standard out. */
int _putchar(char ch);

/* Prints a string to standard out. */
int _puts(char *str);

/* _atoi - Converts a string to an int. */
int _atoi(char *str);

/* Checks if a character is a digit. */
int _isdigit(int c);

/* Checks if the given string represents a number. */
int _is_number(char *str);

/* Returns the length of a null-terminated string. */
int _strlen(char *str);

/* Remove whitespace from both ends of a string. */
char *_strip(char *str);

/* Return a duplicate of the provided string. */
char *_strdup(char *str);

/* Compares two strings. */
int _strcmp(char *s1, char *s2);

/* Checks if string, s1 starts with another string, s2. */
int starts_with(char *s1, char *s2);

/* Checks if string s1 is the same as the command, s2. */
int is_same(char *s1, char *s2);

/* Returns the argument count for the program/command entered. */
int _argc(char **argv);

/* Returns the length of an array of pointers. */
int len_arr(char **arr);

/* Returns an array of tokens got by splitting up the provided string */
/* using the given delimiter/delimiters. */
char **get_tokens(char *str, char *delims);

/* Counts the number of tokens, separated by the given delimiters. */
int count_tokens(char *str, char *delims);

/* Checks if the provided character is a delimiter. */
int is_delim(char ch, char *delims);

/* Checks if a string is composed of only delimiters */
int has_only_delims(char *str, char *delims);

/* Shows a prompt, and gets terminal inputs provided at said prompt. */
char *get_prompt_input(int is_interactive);

/* Executes a program/command, inside of a child process. */
int _exec_in_child(char **args, char **argv, char **env);

/* Executes a program/command, inside of a child process. */
int _execvp(char *command, char **args, char **argv, char **env);

/* Checks if the command is a call to the exit command. */
int _is_exit(char **args);

/* Exits the shell program. */
void __exit(void);

/* Prints the current environment. */
void print_env(char **env);

/* Change or add an environment variable. */
int _setenv(char *key, char *value, char **env, memPool *pool);

/* Checks if an environment variable with a given key exists. */
int key_exists(char *key, char **env, int *index);

/* Frees all memory locations provided. */
void free_all(int how_many, ...);

/* Frees memory allocated in an array of pointers. */
void free_arr(char **arr);

char *_strcat(char *dest, char *src);

char *_strcpy(char *dest, const char *src);

char *concat_strs(char *str1, char *str2);

/* Concatenates three strings together. */
char *concat_three(char *s1, char *s2, char *s3);

char *_strchr(const char *s, int c);

int _strcmpr(const char *str1, const char *str2, int n);

char *_strncpy(char *dest, const char *src, int n);

char *get_path();

char *find_executable(char *command, char *directories);

int is_executable(char *path);
#endif
