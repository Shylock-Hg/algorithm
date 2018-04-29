CC = gcc
CFLAGS = -std=c99 -Wall -g

DIR_BUILD = ./build

DIR_SOURCE = .

C_SOURCE = $(wildcard *.c)

OBJECTS = $(addprefix $(DIR_BUILD)/, $(patsubst %.c, %.o, $(C_SOURCE)))

#OBJECTS = $(DIR_BUILD)/search_linear.o $(DIR_BUILD)/test.o

all : $(DIR_BUILD)/test

$(DIR_BUILD)/test : $(OBJECTS) output
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

$(DIR_BUILD)/%.o : %.c output
	$(CC) $(CFLAGS) -c $< -o $@

output :
	mkdir -p ./build

clean : $(DIR_BUILD)
	rm -rf $(DIR_BUILD)

