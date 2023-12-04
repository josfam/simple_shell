#ifndef EXERCISE_HEADER
#define EXERCISE_HEADER
#include <sys/types.h>

/* Returns the PID of the parent process */
pid_t _getpid(void);

/* Prints command-line arguments */
int main(int ac, char **av);

/* Writes a character to standard out */
void _putchar(char ch);

#endif
