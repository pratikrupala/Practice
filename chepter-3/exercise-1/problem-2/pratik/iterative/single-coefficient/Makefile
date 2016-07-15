#declare a compiler
CC = gcc

#Declare compilation flags
CFALGS = -Wall -g

#Define the target
TARGET = binomial

#Define source files
SRCS = binomial.c

#Define object files
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	$(RM) $(TARGET) $(OBJS)
