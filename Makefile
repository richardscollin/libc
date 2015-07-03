
objects = \
	  crt1.o \
	  libc.o \
	  ctype.o \
	  exit.o \
	  string.o \
	  syscall.o \

CC = cc
C_INCLUDE_PATH = /home/collin/code/libc/include
CFLAGS = -g -ansi -I$(C_INCLUDE_PATH) -nostdlib
VPATH = src/
DESTDIR = target/
MACHINE = x86_64
LIBNAME = libc.a

all: test stats

test: lib
	$(CC) $(CFLAGS) test.c $(LIBNAME) -o a.out

lib: $(addprefix $(DESTDIR), $(objects)) 
	$(AR) -rcs $(LIBNAME) $^

.PHONY: stats
stats: lib
	wc -l src/string.c
	du -h libc.a


.PHONY: dir
dir:
	mkdir -p $(DESTDIR)

%crt1.o: dir
	as crt/$(MACHINE)/crt1.s -o $(DESTDIR)crt1.o

%syscall.o: dir
	as crt/$(MACHINE)/syscall.s -o $(DESTDIR)syscall.o

$(DESTDIR)%.o: %.c dir
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(DESTDIR)
