CC = gcc
CFLAGS = -Wall -g
SRCS = lrv.c
OBJS = $(SRCS:.c=.o)
TARGET = lrv

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	$(RM) $(TARGET) $(OBJS)
