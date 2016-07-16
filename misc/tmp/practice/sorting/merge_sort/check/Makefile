CC = gcc
CFLAGS = -Wall -g
SRCS = merge.c
OBJS = $(SRCS:.c=.o)
TARGET = merge_sort

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	$(RM) $(TARGET) $(OBJS)
