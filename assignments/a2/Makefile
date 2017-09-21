SOURCES=main.cpp model.cpp
OBJECTS=$(SOURCES:.cpp=.o)
HEADERS=$(SOURCES:.cpp=.h)
PROGRAM=a.out
DFILERULES=-MMD -MP
CFLAGS=-lm -pedantic -Wall -std=c++14 $(DFILERULES)
LDFLAGS=$(CFLAGS)
CC=g++


all: $(PROGRAM)

%.o: %.cpp #$(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(PROGRAM): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

-include $(SOURCES:.cpp=.d)
.PHONY:clean archive debug rebuild

debug:all
debug:CFLAGS+= -fsanitize=address -g
debug:LDFLAGS+= -fsanitize=address -g

clean:
	rm $(PROGRAM) $(OBJECTS)

archive:
	zip $(USER)-a2 $(SOURCES) $(HEADERS) Makefile

rebuild: clean
	make

