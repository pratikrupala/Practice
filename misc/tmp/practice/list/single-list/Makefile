CC = gcc
CFLAGS = -Wall -g
SRCS = slist.c
OBJS = $(SRCS:.c=.o)
TARGET = slist

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	$(RM) $(TARGET) $(OBJS)
