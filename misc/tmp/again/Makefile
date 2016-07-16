CC = gcc
CFLAGS = -Wall -g
SRCS = src.c
OBJS = $(SRCS:.c=.o)
TARGET =

default: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	$(RM) $(OBJS) $(TARGET)
