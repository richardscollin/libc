
objects = \
	  crt1.o \
	  libc.o \
	  ctype.o \
	  exit.o \
	  string.o \
	  syscall.o \

VPATH = src/
DESTDIR = target/
MACHINE = x86_64

all: $(addprefix $(DESTDIR), $(objects))
	cc -g -c test.c
	ld $^ test.o

dir:
	mkdir -p $(DESTDIR)

%crt1.o:
	as crt/$(MACHINE)/crt1.s -o $(DESTDIR)crt1.o

%syscall.o:
	as crt/$(MACHINE)/syscall.s -o $(DESTDIR)syscall.o

$(DESTDIR)%.o: %.c dir
	cc -g -c $< -o $@

clean:
	rm -rf $(DESTDIR)
