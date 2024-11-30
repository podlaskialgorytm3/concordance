CC = gcc
TARGET = main
SRCS = main.c list.c sort.c search.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c $<

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean