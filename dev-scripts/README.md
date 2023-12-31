# dev-scripts

A collection of tooling scripts, that automate the routine building and running
\
of the shell program.

## A note on running scripts from PATH

If the `dev-scripts` folder is in your PATH, then the scripts can simply be run
\
by using the script name alone.

```sh
$ <script name>
```

Otherwise, the path to the script has to be specified.
\
If the current location is the `simple_shell` directory,
\
the compilation is:

```sh
$ ./dev-scripts/<script name>
```

## Scripts

### ,compile

Without any flags, `,compile` compiles the program with the ALX gcc flags.

```sh
$ ,compile
$ 
```

If the `-s` (or `--simple`) flag is used, the compilation will not use strict
\
flags, and will just use gcc.

```sh
$ ,compile -s
$ 
```

If the `-r` (or `--run`) flag is used, the program will be compiled and run.

```sh
$ ,compile -r
$ 
```

If the `-v` (or `--valgrind`) flag is used, the program will be run inside a
\
valgrind environment.

```sh
$ ,compile -v
$ 
```

Note: `-r` and `-v` flags cannot be combined, all other flags can.

```sh
$ ,compile -r -v
usage: ,compile [-h] [--simple] [--run | --valgrind]
,compile: error: argument --valgrind/-v: not allowed with argument --run/-r
```

```sh
$ ,compile -s -v
==102431== Memcheck, a memory error detector
==102431== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==102431== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==102431== Command: ./hsh
==102431== 
$ 
```

### ,nointeract

Runs the shell program in non-interactive mode, by echoing the command and piping
\
it into the hsh shell.
\
\
Simplest usage is: `,nointeract "<command to run>"`

```sh
$ ,nointeract "ls -h"   
a.out                 _env.c             _get_tokens.c   _putchar.c      _strcat.c        _strlen.c
_atoi.c               _execute.c         hsh             _puts.c         _strchr.c        _strncpy.c
AUTHORS               _execvp.c          _is_command.c   README.md       _str_clean_up.c  tests
callgrind.out.142952  exercises          _isdigit.c      _set.c          _strcmp.c
_concatenate.c        _exit.c            _lengths.c      shell.c         _strcmpr.c
_delimiting.c         find_executable.c  LICENSE         shell.h         _strcpy.c
dev-scripts           _freeing.c         _prompt_input.c _starts_with.c  _strdup.c
```

If the `-v` (or `--valgrind`) flag is used, a valgrind report is generated after
\
the program has been run.

```sh
$ ,nointeract "ls -h" -v
==767453== Memcheck, a memory error detector
==767453== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==767453== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==767453== Command: ./hsh
==767453== 
a.out                 _env.c             _get_tokens.c   _putchar.c      _strcat.c        _strlen.c
_atoi.c               _execute.c         hsh             _puts.c         _strchr.c        _strncpy.c
AUTHORS               _execvp.c          _is_command.c   README.md       _str_clean_up.c  tests
callgrind.out.142952  exercises          _isdigit.c      _set.c          _strcmp.c
_concatenate.c        _exit.c            _lengths.c      shell.c         _strcmpr.c
_delimiting.c         find_executable.c  LICENSE         shell.h         _strcpy.c
dev-scripts           _freeing.c         _prompt_input.c _starts_with.c  _strdup.c
==767453== 
==767453== HEAP SUMMARY:
==767453==     in use at exit: 0 bytes in 0 blocks
==767453==   total heap usage: 24 allocs, 24 frees, 6,583 bytes allocated
==767453== 
==767453== All heap blocks were freed -- no leaks are possible
==767453== 
==767453== For lists of detected and suppressed errors, rerun with: -s
==767453== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
