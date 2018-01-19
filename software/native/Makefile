CC=gcc
INCLUDE=-I. -I../../
CFLAGS=$(INCLUDE)


main.o: ../main.c hal.h ../../address_map.h
	$(CC) -c $(CFLAGS) ../main.c -o main.o

.PHONY: clean realclean
clean:
	$(RM) main.o

realclean: clean
	-$(RM) *~
