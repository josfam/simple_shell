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

/* Return a duplicate of the provided string. */
char *_strdup(char *str);

/* Compares two strings. */
int _strcmp(char *s1, char *s2);

/* Returns the argument count for the program/command entered. */
int _argc(char **argv);

/* Returns an array of tokens got by splitting up the provided string */
/* using the given delimiter/delimiters. */
char **_get_tokens(char *str, char *delims);

/* Shows a prompt, and gets terminal inputs provided at said prompt. */
char *_get_prompt_input(void);

/* Executes a program/command, inside of a child process. */
int _exec_in_child(char **args, char **argv);

/* Checks if the command is a call to the exit command. */
int _is_exit_call(char **command);

/* Exits the shell program. */
void __exit(void);

#endif
