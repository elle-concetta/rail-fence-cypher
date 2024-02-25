CC=gcc
CFLAGS=-I. -g -w -lm
DEPS = railcipher.h
OBJ = railcipher.o encryption.o decryption.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
railcipher: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)