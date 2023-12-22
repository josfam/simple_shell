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
