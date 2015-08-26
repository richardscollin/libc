
This is my attempt at writing libc in as little lines of C as possible.
Please forgive the very terse code.

Some patterns that I've found useful to reduce the number of lines of code.

```
while (test) {
    code1;
    code2;
}
```

can be converted to:

```
for (; test; code1, code2);
```

You can use a variable from the argument list instead of declaring a new
variable to save an extra line.

```
if (cond)
    code;
```

can be converted to:

```
cond && code
```

The issue with this is that the compiler may issue a warning about not
using the result of the expression. So I might not convert these and
just put it on the same line anyway.

Progress:

- [X] assert
- [X] ctype
- [] errno
- [] float
- [] limits
- [] locale
- [] math
- [] setjmp
- [] signal
- [] stdarg
- [] stdef
- [] stdio
- [] stdlib
- [X] string
- [] time

Note: This will probably never be finished.

THANKS:
To the PDCLib project and Musl libc projects. I've used pieces of code that
is in the public domain from both of these projects.

