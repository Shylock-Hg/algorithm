CC = gcc
CCFLAGS = -std=c99 -Wall
BUILD = ./build
OBJECTS = $(BUILD)/test.o $(BUILD)/sort_insert.o $(BUILD)/sort_common.o \
	  $(BUILD)/sort_select.o $(BUILD)/sort_merge.o

vpath %.o $(BUILD) # add objects directory

.PHONY : output all clean

all : $(BUILD)/test

$(BUILD)/test : $(OBJECTS) output
	$(CC) $(CCFLAGS) -o $@ $(OBJECTS)

$(BUILD)/%.o : %.c output
	$(CC) $(CCFLAGS) -c $< -o $@

output :
	mkdir -p $(BUILD)

clean :
	rm -rf $(BUILD)

