CC = gcc
CFLAGS = -Wall -g
SRCS = mirror.c
OBJS = $(SRCS:.c=.o)
TARGET = mirror

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	$(RM) $(TARGET) $(OBJS)
