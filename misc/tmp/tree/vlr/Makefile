CC = gcc
CFLAGS = -Wall -g
SRCS = vlr.c
OBJS = $(SRCS:.c=.o)
TARGET = vlr

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	$(RM) $(TARGET) $(OBJS)
