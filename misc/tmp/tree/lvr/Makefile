CC = gcc
CFLAGS = -Wall -g
SRCS = lvr.c
OBJS = $(SRCS:.c=.o)
TARGET = lvr

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	$(RM) $(TARGET) $(OBJS)
