CC = gcc
CFLAGS = -Wall -Wextra -std=c99


TARGET = main


SRC = main.c list.c sort.c search.c
OBJ = $(SRC:.c=.o)


all: $(TARGET)


$(TARGET): $(OBJ)
	$(CC) -o $@ $^


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJ) $(TARGET)