CC = gcc
CFLAGS = -Wall -g
SRCS = selection_sort.c
TARGET = selection_sort
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	$(RM) $(TARGET) $(OBJS)
