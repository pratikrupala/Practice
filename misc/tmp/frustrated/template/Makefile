CC = gcc
CFLAGS = -Wall -g
SRCS = template.c
OBJS = $(SRCS:.c=.o)
TARGET = template

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	$(RM) $(TARGET) $(OBJS)
