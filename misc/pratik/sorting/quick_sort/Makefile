CC = gcc
CFLAGS = -Wall -g
SRCS = quick_sort.c
OBJS = $(SRCS:.c=.o)
TARGET = quick_sort

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	$(RM) $(TARGET) $(OBJS)
