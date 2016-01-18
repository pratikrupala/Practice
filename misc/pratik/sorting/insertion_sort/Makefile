CC = gcc
CFLAGS = -Wall -g
SRCS = insert_sort.c
OBJS = $(SRCS:.c=.o)
TARGET = insertion_sort

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	$(RM) $(TARGET) $(OBJS)
