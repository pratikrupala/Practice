CC = gcc
CFLAGS = -Wall -g
SRCS = bubble.c
OBJS = $(SRCS:.c=.o)
TARGET = bubble_sort

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	$(RM) $(TARGET) $(OBJS)
