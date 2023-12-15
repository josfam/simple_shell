#ifndef SHELL_HEADER
#define SHELL_HEADER

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

/* Returns the argument count for the program/command entered. */
int _argc(char **argv);

/* Returns an array of tokens got by splitting up the provided string */
/* using the given delimiter/delimiters. */
char **_get_tokens(char *str, char *delims);

/* Checks if the provided character is a delimiter. */
int _is_delim(char ch, char *delims);

/* Checks if a string is composed of only delimiters */
int _has_only_delims(char *str, char *delims);

/* Shows a prompt, and gets terminal inputs provided at said prompt. */
char *_get_prompt_input(int is_interactive);

/* Executes a program/command, inside of a child process. */
int _exec_in_child(char **args, char **argv, char **env);

/* Executes a program/command, inside of a child process. */
int _execvp(char *command, char **args, char **argv, char **env);

/* Checks if the command is a call to the exit command. */
int _is_exit_call(char **command);

/* Exits the shell program. */
void __exit(void);

/* Frees all memory locations provided. */
void _free_all(int how_many, ...);

char *_strcat(char *dest, char *src);

char *_strcpy(char *dest, const char *src);

char *concatenate_strings(char *str1, char *str2);

char *_strchr(const char *s, int c);

int _strcmpr(const char *str1, const char *str2, int n);

char *_strncpy(char *dest, const char *src, int n);

char *get_path();

char *find_executable(char *command, char *directories);

int is_executable(char *path);
#endif
