CC = gcc
CFLAGS = -Wall -g
SRCS = selection.c
OBJS = $(SRCS:.c=.o)
TARGET = selection

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	$(RM) $(TARGET) $(OBJS)
