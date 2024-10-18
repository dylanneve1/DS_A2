CC = gcc

t1_test: t1_test.o t1.o
	$(CC) $(CFLAGS) -o t1_test t1_test.o t1.o

t1_test.o: t1_test.c t1.h
	$(CC) $(CFLAGS) -c t1_test.c

t1.o: t1.c t1.h
	$(CC) $(CFLAGS) -c t1.c

clean:
	rm -f *.o t1_test
