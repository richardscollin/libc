
objects = \
	  __syscall.o \
	  crt1.o \
	  libc.o \
	  ctype.o \
	  exit.o \
	  string.o \
	  syscall.o \
	  unistd.o \

CC = gcc
C_INCLUDE_PATH = /home/collin/code/libc/include
CFLAGS = -g -std=c89 -Wall -Wextra -Wpedantic -I$(C_INCLUDE_PATH) -nostdlib
VPATH = src/
DESTDIR = target/
MACHINE = x86_64
LIBNAME = libc.a

all: test stats

test: lib
	$(CC) $(CFLAGS) test_string.c $(LIBNAME) -o a.out

lib: $(addprefix $(DESTDIR), $(objects)) 
	$(AR) -rcs $(LIBNAME) $^ lib/unistd.a

.PHONY: stats
stats: lib
	wc -l src/string.c > info
	du -h libc.a >> info
	cat info


.PHONY: dir
dir:
	mkdir -p $(DESTDIR)

%crt1.o: dir
	as crt/$(MACHINE)/crt1.s -o $(DESTDIR)crt1.o

%__syscall.o: dir
	as crt/$(MACHINE)/__syscall.s -o $(DESTDIR)__syscall.o

$(DESTDIR)%.o: %.c dir
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(DESTDIR)
