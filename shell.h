#ifndef SHELL_HEADER
#define SHELL_HEADER

/* Writes a character to standard out. */
int _putchar(char ch);

/* Prints a string to standard out. */
int _puts(char *str);

/* Returns the length of a null-terminated string. */
int _strlen(char *str);

/* Return a duplicate of the provided string. */
char *_strdup(char *str);

/* Compares two strings. */
int _strcmp(char *s1, char *s2);

/* Returns an array of tokens got by splitting up the provided string */
/* using the given delimiter/delimiters. */
char **_get_tokens(char *str, char *delims);

/* Shows a prompt, and gets terminal inputs provided at said prompt. */
char *_get_prompt_input(void);

/* Executes a program/command, inside of a child process. */
int _exec_in_child(char *command, char **args);

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
