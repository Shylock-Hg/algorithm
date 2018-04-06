CC = gcc
CCFLAGS = -std=c99 -Wall
BUILD = ./build
OBJECTS = $(BUILD)/test.o $(BUILD)/sort_insert.o $(BUILD)/sort_common.o

vpath %.o ./build # add objects directory

.PHONY : output all clean


all : test

test : $(OBJECTS) output
	$(CC) $(CCFLAGS) -o $(BUILD)/$@ $(OBJECTS)

test.o : test.c output
	$(CC) $(CCFLAGS) -c $< -o $(BUILD)/$@

sort_insert.o : sort_insert.c output
	$(CC) $(CCFLAGS) -c $< -o $(BUILD)/$@

sort_common.o : sort_common.c output
	$(CC) $(CCFLAGS) -c $< -o $(BUILD)/$@

output :
	mkdir -p ./build

clean : output
	rm $(BUILD)/test $(OBJECTS)

