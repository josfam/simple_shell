# tests

To show how the test files were compiled, and the output of those tests.
\
\
`Note`: All compilation was done one level outside the tests folder.

## str-duplicate.c

```sh
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 _strdup.c _strlen.c tests/str-duplicate.c
$ ./a.out
Hello, there!
$
```

## get-tokens.c

```sh
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 _strdup.c _strlen.c _get_tokens.c tests/get-tokens.c
$ ./a.out                                                                                            
Marie
Jordan
Andre
----------------
----------------
ab
c
----------------
```
