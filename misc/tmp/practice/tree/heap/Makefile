CC = gcc
CFLAGS = -Wall -g
SRCS = heap.c
OBJS = $(SRCS:.c=.o)
TARGET = heap

default: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	$(RM) $(TARGET) $(OBJS)
