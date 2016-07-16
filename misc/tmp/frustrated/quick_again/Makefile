CC = gcc
CFLAGS = -Wall -g
SRCS = quick_again.c
OBJS = $(SRCS:.c=.o)
TARGET = quick_sort

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	$(RM) $(TARGET) $(OBJS)
