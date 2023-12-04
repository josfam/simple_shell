#ifndef EXERCISE_HEADER
#define EXERCISE_HEADER
#include <sys/types.h>

/* Returns the PID of the parent process */
pid_t _getpid(void);

/* Writes a character to standard out */
void _putchar(char ch);

/* Prints a string to standard out. No newline added at the end. */
void _puts(char *str);

/* Return the length of a null-terminated string */
int _strlen(char *s);

#endif
