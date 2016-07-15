CC = gcc
CFLAGS = -Wall -g
TARGET = pmult
SRCS = pmult.c
OBJS = $(SRCS:.c=.o)

default: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	$(RM) $(TARGET) $(OBJS)
