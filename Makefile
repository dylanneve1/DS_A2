###############################
#        DS_A2 21364333       #
#   Makefile for Assignment   #
###############################

# Compiler
CC = gcc
CFLAGS = -Wall -Wextra -O2

######################
#      TARGETS       #
######################

# Both targets with one command
all: t1_test t2_test

# Target for t1_test
t1_test: t1_test.o t1.o
	@echo "Linking t1_test..."
	$(CC) $(CFLAGS) -o t1_test t1_test.o t1.o

# Target for t2_test
t2_test: t2_test.o t2.o t1.o
	@echo "Linking t2_test..."
	$(CC) $(CFLAGS) -o t2_test t2_test.o t2.o t1.o

######################
#    BUILD RULES     #
######################

# Compile t1_test object
t1_test.o: t1_test.c t1.h
	@echo "Compiling t1_test.c..."
	$(CC) $(CFLAGS) -c t1_test.c

# Compile t2_test object
t2_test.o: t2_test.c t2.h t1.h
	@echo "Compiling t2_test.c..."
	$(CC) $(CFLAGS) -c t2_test.c

# Compile t1 object
t1.o: t1.c t1.h
	@echo "Compiling t1.c..."
	$(CC) $(CFLAGS) -c t1.c

# Compile t2 object
t2.o: t2.c t2.h
	@echo "Compiling t2.c..."
	$(CC) $(CFLAGS) -c t2.c

######################
#     CLEAN RULES    #
######################

# Clean up all object files and executables
clean:
	@echo "Cleaning up..."
	rm -f *.o t1_test t2_test

######################
#    PHONY TARGETS   #
######################

.PHONY: all clean
