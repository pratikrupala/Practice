CC = gcc
CFLAGS = -Wall -g
TARGET = calc
SRCS = calc.c
OBJS = calc.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	$(RM) $(TARGET) $(OBJS)
