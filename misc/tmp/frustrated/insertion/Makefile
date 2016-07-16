CC = gcc
CFLAGS = -Wall -g
SRCS = insertion.c
OBJS = $(SRCS:.c=.o)
TARGET = insertion_sort

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	$(RM) $(TARGET) $(OBJS)
