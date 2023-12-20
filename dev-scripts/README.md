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

Compiles the program with the recommended gcc flags:

```sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

### ,run

Compiles the program with the recommended gcc flags, and runs the resulting
\
executable `hsh` file.

### ,valgrindrun

Compiles the program with the recommended gcc flags, and runs the resulting
\
executable `hsh` file, inside of a Valgrind environment
