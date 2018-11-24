CC = gcc
TARGET = sic_xe
SRC_FILES = $(wildcard *.c)
OBJS = ${SRC_FILES:.c=.o}

all:
	$(CC) -c $(SRC_FILES)
	$(CC) -o $(TARGET) $(OBJS)
clean:
	$(RM) $(OBJS)
	$(RM) $(TARGET)

