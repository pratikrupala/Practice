CC = gcc
CFLAGS = -Wall -g
SRCS = threaded.c
OBJS = $(SRCS:.c=.o)
TARGET = threaded

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	$(RM) $(TARGET) $(OBJS)
