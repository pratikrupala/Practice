CC = gcc
CFLAGS = -Wall -g
SRCS = src.c
OBJS = $(SRCS:.c=.o)
TARGET = insertion

default: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	$(RM) $(OBJS) $(TARGET)
