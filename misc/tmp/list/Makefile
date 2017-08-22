CC = gcc
CFLAGS = -Wall -g
TARGET = mylist
SRCS = mylist.c
OBJS = $(.src=.o)
INCLUDEDIR = .
RM = rm

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(SRCS) $(OBJS) -I$(INCLUDEDIR)

clean:
	$(RM) $(TARGET) $(OBJS)
