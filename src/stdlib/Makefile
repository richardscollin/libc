CFLAGS=-Wall -nostdlib

stdlib.a: stdlib.o
	$(AR) rcs $@ $^

stdlib.o: stdlib.c
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm stdlib.a stdlib.o

