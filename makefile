CC = gcc
CFLAGS = -Wall
TARGET = sic_xe
SRC_FILES = $(wildcard *.c)
OBJS = ${SRC_FILES:.c=.o}

all:
	$(CC) $(CFLAGS) -c $(SRC_FILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
clean:
	$(RM) $(OBJS)
	$(RM) $(TARGET)

