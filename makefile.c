
CC = gcc
CFLAGS = -Wall -g

TARGET = student

SRC = main.c stud_add.c stud_del.c stud_modify.c stud_show.c stud_save.c stud_sort.c stud_rev.c deleteAll.c exit.c

OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
        $(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

%.o: %.c stu_header.h
        $(CC) $(CFLAGS) -c $< -o $@

clean:
        rm -f $(OBJ) $(TARGET)
