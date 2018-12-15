CC = gcc
TARGET = sic_xe.out
CFLAGS = -g -Wall
SRC_FILES = $(wildcard *.c)
OBJS = ${SRC_FILES:.c=.o}

all:
	$(CC) $(CFLAGS) -c $(SRC_FILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
clean:
	$(RM) $(OBJS)
	$(RM) $(TARGET)

