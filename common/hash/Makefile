OBJECTS = test.o hash.o
CFLAGS = -std=c99 -Wall

.PHONY: all clean

all: test

test: $(OBJECTS)
	cc $(CFLAGS) -o $@ $(OBJECTS)

%.o : %.c 
	cc $(CFLAGS) -o $@  -c $<

clean : 
	rm test $(OBJECTS)
