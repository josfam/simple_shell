# tests

To show how the test files were compiled, and the output of those tests.
\
\
`Note`: All compilation was done one level outside the tests folder.

## str-duplicate.c

```sh
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 _copying.c _strlen.c tests/str-duplicate.c
$ ./a.out
Hello, there!
$
```

## get-tokens.c

```sh
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 _strdup.c _strlen.c get_tokens.c tests/get-tokens.c
$ ./a.out
Marie
Jordan
Andre
----------------
----------------
----------------
ab
c
----------------
Half-remembered-dream
----------------
----------------
$
```

## str-compare.c

```sh
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 _strlen.c _comparing.c tests/str-compare.c
$ ./a.out
ABC = ABC
abc > ab
aba < abz
abj > abc
 = 
 < a
$
```

## str-to-int.c

```sh
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 _strcmp.c _strlen.c _atoi.c _isdigit.c tests/str-to-int.c
$ ./a.out
_atoi   | atoi

0       | 0
10      | 10
---------------

_atoi   | atoi

0       | 0
10      | 10
---------------

_atoi   | atoi

2       | 2
12      | 12
---------------

_atoi   | atoi

500     | 500
510     | 510
---------------

_atoi   | atoi

-800    | -800
-790    | -790
---------------

_atoi   | atoi

0       | 0
10      | 10
---------------
```

## concat-three.c

```sh
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 _copying.c _strcat.c _strlen.c _concatenate.c _comparing.c tests/concat-three.c
$ ./a.out
Jordan Moreau Li
Jordan Moreau

```
