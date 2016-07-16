CC = gcc
CFLAGS = -Wall -g
SRCS = basic.c
OBJS = $(SRCS:.c=.o)
TARGET = tree

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	$(RM) $(TARGET) $(OBJS)
