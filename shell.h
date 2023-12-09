#ifndef SHELL_HEADER
#define SHELL_HEADER

/* Returns the length of a null-terminated string. */
int _strlen(char *str);

/* Return a duplicate of the provided string. */
char *_strdup(char *str);

/* Returns an array of tokens got by splitting up the provided string */
/* using the given delimiter/delimiters. */
char **_get_tokens(char *str, char *delims);

#endif
