######################################################## MACROS
EXE=castle
TEST=character_test inventory_test link_test object_test player_test set_test space_test
CC=gcc
CFLAGS=-Wall -ansi -pedantic
OBJECTS=character.o command.o game_actions.o game_loop.o game_reader.o game.o graphic_engine.o inventory.o link.o object.o player.o set.o space.o

######################################################## MAIN
all: $(EXE) run

$(EXE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) -L. -lscreen

character.o: character.c character.h types.h
	$(CC) $(CFLAGS) -c character.c

command.o: command.c command.h types.h
	$(CC) $(CFLAGS) -c command.c

game_actions.o: game_actions.c game_actions.h command.h types.h game.h player.h object.h space.h set.h character.h
	$(CC) $(CFLAGS) -c game_actions.c

game_loop.o: game_loop.c command.h types.h game.h player.h object.h space.h set.h character.h game_reader.h game_actions.h graphic_engine.h
	$(CC) $(CFLAGS) -c game_loop.c

game_reader.o: game_reader.c game_reader.h command.h types.h game.h player.h object.h space.h set.h character.h
	$(CC) $(CFLAGS) -c game_reader.c

game.o: game.c game.h command.h types.h player.h object.h space.h set.h character.h game_reader.h link.c link.h
	$(CC) $(CFLAGS) -c game.c

graphic_engine.o: graphic_engine.c graphic_engine.h game.h command.h types.h player.h object.h space.h set.h character.h libscreen.h
	$(CC) $(CFLAGS) -c graphic_engine.c

inventory.o: inventory.c inventory.h types.h types.h object.h set.h
	$(CC) $(CFLAGS) -c inventory.c

link.o: link.c link.h types.h 
	$(CC) $(CFLAGS) -c link.c

object.o: object.c object.h types.h
	$(CC) $(CFLAGS) -c object.c

player.o: player.c player.h inventory.h object.h set.h types.h
	$(CC) $(CFLAGS) -c player.c

set.o: set.c set.h types.h
	$(CC) $(CFLAGS) -c set.c

space.o: space.c space.h types.h object.h set.h
	$(CC) $(CFLAGS) -c space.c

######################################################## CHARACTER_TEST, INVENTORY_TEST, LINK_TEST, OBJECT_TEST, PLAYER_TEST, SET_TEST, SPACE_TEST (TESTS)
character_test.o: character_test.c character_test.h  character.c character.h types.h test.h
	$(CC) $(CFLAGS) -c character_test.c

character_test: character_test.o character.o set.o
	$(CC) $(CFLAGS) -o character_test character_test.o character.o set.o

inventory_test.o: inventory_test.c inventory_test.h  inventory.c inventory.h types.h test.h
	$(CC) $(CFLAGS) -c inventory_test.c

inventory_test: inventory_test.o inventory.o set.o
	$(CC) $(CFLAGS) -o inventory_test inventory_test.o inventory.o set.o

link_test.o: link_test.c link_test.h  link.c link.h types.h test.h
	$(CC) $(CFLAGS) -c link_test.c

link_test: link_test.o link.o set.o
	$(CC) $(CFLAGS) -o link_test link_test.o link.o set.o

object_test.o: object_test.c object_test.h  object.c object.h types.h test.h
	$(CC) $(CFLAGS) -c object_test.c

object_test: object_test.o object.o set.o
	$(CC) $(CFLAGS) -o object_test object_test.o object.o set.o

player_test.o: player_test.c player_test.h player.h inventory.h object.h set.h test.h types.h
	$(CC) $(CFLAGS) -c player_test.c

player_test: player_test.o player.o inventory.o set.o
	$(CC) $(CFLAGS) -o player_test player_test.o player.o inventory.o set.o

set_test.o: set_test.c set_test.h set.h types.h test.h
	$(CC) $(CFLAGS) -c set_test.c

set_test: set_test.o set.o
	$(CC) $(CFLAGS) -o set_test set_test.o set.o

space_test.o: space_test.c space_test.h space.c space.h types.h test.h
	$(CC) $(CFLAGS) -c space_test.c

space_test: space_test.o space.o set.o
	$(CC) $(CFLAGS) -o space_test space_test.o space.o set.o

test_character: character_test
	./character_test

test_inventory: inventory_test
	./inventory_test

test_link: link_test
	./link_test

test_object: object_test
	./object_test

test_player: player_test
	./player_test

test_set: set_test
	./set_test

test_space: space_test
	./space_test

######################################################## RUN, LOG, RUNV, CLEAN, TEST, DOXY (TOOLS)
.PHONY: run runv clean test test_clean doc doc_clean

run: $(EXE)
	./$(EXE) castle.dat

run_log: $(EXE)
	./$(EXE) castle.dat -1 logFile

runv:
	@echo ">>>>>> Running castle.dat with valgrind"
	valgrind --leak-check=full  ./castle castle.dat

clean:
	@echo ">>>>>> Deleting project file"
	rm -f *.o $(EXE)

test: $(TEST)
	./$(TEST)

test_clean:
	@echo ">>>>>> Deleting tests file"
	rm -f *.o $(TEST)

doc:
	@echo ">>>>>> Making documentation file"
	doxygen Doxyfile

doc_clean:
	@echo ">>>>>> Deleting documentation file"
	rm -rf ./doc