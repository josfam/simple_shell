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
compilation used: gcc -Wall -Werror -Wextra -pedantic -std=gnu89 0-readline.c _puts.c _strlen.c _putchar.c
```
