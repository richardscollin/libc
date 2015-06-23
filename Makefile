
objects = \
	  crt1.o \
	  libc.o \
	  ctype.o \
	  exit.o \
	  string.o \

VPATH = src/
DESTDIR = target/
MACHINE = x86_64

all: $(addprefix $(DESTDIR), $(objects))
	cc -c main.c
	ld $^ main.o

dir:
	mkdir -p $(DESTDIR)

%crt1.o:
	as crt/$(MACHINE)/crt1.s -o $(DESTDIR)crt1.o

$(DESTDIR)%.o: %.c dir
	cc -c $< -o $@

clean:
	rm -rf $(DESTDIR)
