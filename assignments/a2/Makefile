MODELFILES=model/model.cpp model/coordinate.cpp model/player.cpp model/game_piece.cpp
NCFILES=ncview/add_player_window.cpp ncview/game_window.cpp ncview/main_menu.cpp ncview/menu.cpp ncview/player_selection_window.cpp ncview/ui.cpp ncview/window.cpp 
CONTFILES=nc_controller/command.cpp nc_controller/controller.cpp

SOURCES=main_noncurses.cpp $(NCFILES) $(CONTFILES) $(MODELFILES)
OBJECTS=$(SOURCES:.cpp=.o)
HEADERS=$(SOURCES:.cpp=.h) direction.h
DFILES=$(SOURCES:.cpp=.d)
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

-include $(DFILES)
.PHONY:clean archive debug rebuild

debug:all
debug:CFLAGS+= -fsanitize=address -g
debug:LDFLAGS+= -fsanitize=address -g

clean:
	rm $(PROGRAM) $(OBJECTS) $(DFILES)

archive:
	zip $(USER)-a2 $(SOURCES) $(HEADERS) Makefile

rebuild: clean
	make

