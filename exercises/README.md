# Exercise descriptions

Note: All prototypes in `exercise.h`

## 0.getppid

Write a program that prints the PID of the parent process.
\
Run your program several times within the same shell.
\
It should be the same. Does echo $$ print the same value? Why?

```txt
files involved: 0-getpid.c

Echo prints the same value because the parent process is the shell itself.
Since that doesn't change, the ppid doesn't change.
```

## 1. /proc/sys/kernel/pid_max

Write a shell script that prints the maximum value a process ID can be.

```txt
files involved: max-pid.sh
```

## 0. av

Write a program that prints all the arguments, without using ac.

- av is a NULL terminated array of strings
- ac is the number of items in av

```txt
files involved: 0-av.c, _putchar.c
compilation used to test: gcc -Wall -Werror -Wextra -pedantic -std=gnu89 0-av.c _putchar.c
```

## 1. Read line

Write a program that prints "$ ", wait for the user to enter a command, prints
\
it on the next line.

```txt
compilation used: gcc -Wall -Werror -Wextra -pedantic -std=gnu89 1-readline.c _puts.c _strlen.c _putchar.c
```

## 2. command line to av

Write a function that splits a string and returns an array of each word of the string.
\
man `strtok`

```txt
compilation used:
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 main_str_split.c _str_split.c _puts.c _putchar.c _strlen.c
```

**main_str_split.c** (test file)

```c
#include "exercise.h"
#include <stddef.h>
#include <stdlib.h>

int main(void)
{
	char **split_words;
	char **wordsPtr;

	split_words = _str_split("My name is Fin B. Chile  !");
	wordsPtr = split_words;

	/* print words individually separated by a space */
	while(*wordsPtr != NULL)
	{
		_puts(*wordsPtr);
		if (*(wordsPtr + 1) != NULL) /* Dont put a space after the last word */
			_putchar(' ');

		wordsPtr++;
	}

	_putchar('\n');

	/*free allocated memory */
	free(split_words);

	return (0);
}
```

## Creating processes (in standalone)

```txt
*compilation was done one level outside the standalone folder

compilations used: 
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 standalone/fork.c
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 standalone/parent-child.c
```

## Wait (in standalone)

```txt
*compilation was done one level outside the standalone folder

compilation used:
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 standalone/wait.c 
```

## fork + wait + execve (in standalone)

```txt
compilation used:
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 standalone/fork-wait-execve.c
```
