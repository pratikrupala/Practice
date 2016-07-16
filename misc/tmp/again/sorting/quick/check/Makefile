CC = gcc
CFLAGS = -Wall -g
TARGET = quick_sort
SRCS = quick.c
OBJS = $(SRCS:.c=.o)

default: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	$(RM) $(TARGET) $(OBJS)
