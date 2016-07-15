#define a compiler
CC = gcc

#define compilation flags
CFALGS = -Wall -g

#define the target
TARGET = delete

#define the sources
SRCS = delete.c

#define the objects
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	$(RM) $(TARGET) $(OBJS)
