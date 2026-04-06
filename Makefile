######################################################## DIRECTORIOS

SRC = src
OBJ = obj
INC = include
LIB = lib
TEST_INC = include/tests
TEST_SRC = src/tests
TEST_OBJ = obj/tests

######################################################## MACROS

EXE = castle
CC = gcc
LDFLAGS = -L$(LIB) -lscreen
CFLAGS = -Wall -ansi -pedantic -I$(INC) -I$(TEST_INC)

OBJECTS = $(OBJ)/character.o $(OBJ)/command.o $(OBJ)/game_actions.o \
          $(OBJ)/game_loop.o $(OBJ)/game_reader.o $(OBJ)/game.o \
          $(OBJ)/graphic_engine.o $(OBJ)/inventory.o $(OBJ)/link.o \
          $(OBJ)/object.o $(OBJ)/player.o $(OBJ)/set.o $(OBJ)/space.o

TEST = character_test inventory_test link_test object_test \
             player_test set_test space_test

######################################################## MAIN

$(EXE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LDFLAGS)

$(OBJ)/character.o: $(SRC)/character.c $(INC)/character.h $(INC)/types.h | $(OBJ)
	$(CC) $(CFLAGS) -c $(SRC)/character.c -o $(OBJ)/character.o

$(OBJ)/command.o: $(SRC)/command.c $(INC)/command.h $(INC)/types.h | $(OBJ)
	$(CC) $(CFLAGS) -c $(SRC)/command.c -o $(OBJ)/command.o

$(OBJ)/game_actions.o: $(SRC)/game_actions.c $(INC)/game_actions.h $(INC)/command.h $(INC)/types.h $(INC)/game.h $(INC)/player.h $(INC)/object.h $(INC)/space.h $(INC)/set.h $(INC)/character.h | $(OBJ)
	$(CC) $(CFLAGS) -c $(SRC)/game_actions.c -o $(OBJ)/game_actions.o

$(OBJ)/game_loop.o: $(SRC)/game_loop.c $(INC)/command.h $(INC)/types.h $(INC)/game.h $(INC)/player.h $(INC)/object.h $(INC)/space.h $(INC)/set.h $(INC)/character.h $(INC)/game_reader.h $(INC)/game_actions.h $(INC)/graphic_engine.h | $(OBJ)
	$(CC) $(CFLAGS) -c $(SRC)/game_loop.c -o $(OBJ)/game_loop.o

$(OBJ)/game_reader.o: $(SRC)/game_reader.c $(INC)/game_reader.h $(INC)/command.h $(INC)/types.h $(INC)/game.h $(INC)/player.h $(INC)/object.h $(INC)/space.h $(INC)/set.h $(INC)/character.h | $(OBJ)
	$(CC) $(CFLAGS) -c $(SRC)/game_reader.c -o $(OBJ)/game_reader.o

$(OBJ)/game.o: $(SRC)/game.c $(INC)/game.h $(INC)/command.h $(INC)/types.h $(INC)/player.h $(INC)/object.h $(INC)/space.h $(INC)/set.h $(INC)/character.h $(INC)/game_reader.h $(SRC)/link.c $(INC)/link.h | $(OBJ)
	$(CC) $(CFLAGS) -c $(SRC)/game.c -o $(OBJ)/game.o

$(OBJ)/graphic_engine.o: $(SRC)/graphic_engine.c $(INC)/graphic_engine.h $(INC)/game.h $(INC)/command.h $(INC)/types.h $(INC)/player.h $(INC)/object.h $(INC)/space.h $(INC)/set.h $(INC)/character.h $(INC)/libscreen.h | $(OBJ)
	$(CC) $(CFLAGS) -c $(SRC)/graphic_engine.c -o $(OBJ)/graphic_engine.o

$(OBJ)/inventory.o: $(SRC)/inventory.c $(INC)/inventory.h $(INC)/types.h $(INC)/object.h $(INC)/set.h | $(OBJ)
	$(CC) $(CFLAGS) -c $(SRC)/inventory.c -o $(OBJ)/inventory.o

$(OBJ)/link.o: $(SRC)/link.c $(INC)/link.h $(INC)/types.h | $(OBJ)
	$(CC) $(CFLAGS) -c $(SRC)/link.c -o $(OBJ)/link.o

$(OBJ)/object.o: $(SRC)/object.c $(INC)/object.h $(INC)/types.h | $(OBJ)
	$(CC) $(CFLAGS) -c $(SRC)/object.c -o $(OBJ)/object.o

$(OBJ)/player.o: $(SRC)/player.c $(INC)/player.h $(INC)/inventory.h $(INC)/object.h $(INC)/set.h $(INC)/types.h | $(OBJ)
	$(CC) $(CFLAGS) -c $(SRC)/player.c -o $(OBJ)/player.o

$(OBJ)/set.o: $(SRC)/set.c $(INC)/set.h $(INC)/types.h | $(OBJ)
	$(CC) $(CFLAGS) -c $(SRC)/set.c -o $(OBJ)/set.o

$(OBJ)/space.o: $(SRC)/space.c $(INC)/space.h $(INC)/types.h $(INC)/object.h $(INC)/set.h | $(OBJ)
	$(CC) $(CFLAGS) -c $(SRC)/space.c -o $(OBJ)/space.o

######################################################## CARPETAS OBJ

$(OBJ):
	mkdir -p $(OBJ)

$(TEST_OBJ):
	mkdir -p $(TEST_OBJ)

######################################################## CHARACTER_TEST, INVENTORY_TEST, LINK_TEST, OBJECT_TEST, PLAYER_TEST, SET_TEST, SPACE_TEST (TESTS)

$(TEST_OBJ)/character_test.o: $(TEST_SRC)/character_test.c $(TEST_INC)/character_test.h $(SRC)/character.c $(INC)/character.h $(INC)/types.h $(INC)/test.h | $(TEST_OBJ)
	$(CC) $(CFLAGS) -c $(TEST_SRC)/character_test.c -o $(TEST_OBJ)/character_test.o

character_test: $(TEST_OBJ)/character_test.o $(OBJ)/character.o $(OBJ)/set.o
	$(CC) $(CFLAGS) -o character_test $(TEST_OBJ)/character_test.o $(OBJ)/character.o $(OBJ)/set.o

$(TEST_OBJ)/inventory_test.o: $(TEST_SRC)/inventory_test.c $(TEST_INC)/inventory_test.h $(SRC)/inventory.c $(INC)/inventory.h $(INC)/types.h $(INC)/test.h | $(TEST_OBJ)
	$(CC) $(CFLAGS) -c $(TEST_SRC)/inventory_test.c -o $(TEST_OBJ)/inventory_test.o

inventory_test: $(TEST_OBJ)/inventory_test.o $(OBJ)/inventory.o $(OBJ)/set.o
	$(CC) $(CFLAGS) -o inventory_test $(TEST_OBJ)/inventory_test.o $(OBJ)/inventory.o $(OBJ)/set.o

$(TEST_OBJ)/link_test.o: $(TEST_SRC)/link_test.c $(TEST_INC)/link_test.h $(SRC)/link.c $(INC)/link.h $(INC)/types.h $(INC)/test.h | $(TEST_OBJ)
	$(CC) $(CFLAGS) -c $(TEST_SRC)/link_test.c -o $(TEST_OBJ)/link_test.o

link_test: $(TEST_OBJ)/link_test.o $(OBJ)/link.o $(OBJ)/set.o
	$(CC) $(CFLAGS) -o link_test $(TEST_OBJ)/link_test.o $(OBJ)/link.o $(OBJ)/set.o

$(TEST_OBJ)/object_test.o: $(TEST_SRC)/object_test.c $(TEST_INC)/object_test.h $(SRC)/object.c $(INC)/object.h $(INC)/types.h $(INC)/test.h | $(TEST_OBJ)
	$(CC) $(CFLAGS) -c $(TEST_SRC)/object_test.c -o $(TEST_OBJ)/object_test.o

object_test: $(TEST_OBJ)/object_test.o $(OBJ)/object.o $(OBJ)/set.o
	$(CC) $(CFLAGS) -o object_test $(TEST_OBJ)/object_test.o $(OBJ)/object.o $(OBJ)/set.o

$(TEST_OBJ)/player_test.o: $(TEST_SRC)/player_test.c $(TEST_INC)/player_test.h $(INC)/player.h $(INC)/inventory.h $(INC)/object.h $(INC)/set.h $(INC)/test.h $(INC)/types.h | $(TEST_OBJ)
	$(CC) $(CFLAGS) -c $(TEST_SRC)/player_test.c -o $(TEST_OBJ)/player_test.o

player_test: $(TEST_OBJ)/player_test.o $(OBJ)/player.o $(OBJ)/inventory.o $(OBJ)/set.o
	$(CC) $(CFLAGS) -o player_test $(TEST_OBJ)/player_test.o $(OBJ)/player.o $(OBJ)/inventory.o $(OBJ)/set.o

$(TEST_OBJ)/set_test.o: $(TEST_SRC)/set_test.c $(TEST_INC)/set_test.h $(INC)/set.h $(INC)/types.h $(INC)/test.h | $(TEST_OBJ)
	$(CC) $(CFLAGS) -c $(TEST_SRC)/set_test.c -o $(TEST_OBJ)/set_test.o

set_test: $(TEST_OBJ)/set_test.o $(OBJ)/set.o
	$(CC) $(CFLAGS) -o set_test $(TEST_OBJ)/set_test.o $(OBJ)/set.o

$(TEST_OBJ)/space_test.o: $(TEST_SRC)/space_test.c $(TEST_INC)/space_test.h $(SRC)/space.c $(INC)/space.h $(INC)/types.h $(INC)/test.h | $(TEST_OBJ)
	$(CC) $(CFLAGS) -c $(TEST_SRC)/space_test.c -o $(TEST_OBJ)/space_test.o

space_test: $(TEST_OBJ)/space_test.o $(OBJ)/space.o $(OBJ)/set.o
	$(CC) $(CFLAGS) -o space_test $(TEST_OBJ)/space_test.o $(OBJ)/space.o $(OBJ)/set.o

######################################################## CLEAN, RUN, LOG, RUNV, TEST, DOXY (TOOLS)

.PHONY: clean run obj_clean run_log runv test test_clean doc doc_clean

clean:
	@echo ">>>>>> Deleting projects files"
	rm -rf $(TEST_OBJ) $(TEST) $(OBJ) $(EXE)

run: $(EXE)
	@echo ">>>>>> Running project files"
	./$(EXE) castle.dat

obj_clean:
	@echo ">>>>>> Deleting main objects files"
	rm -rf $(OBJ) $(EXE)

run_log: $(EXE)
	@echo ">>>>>> Running project files with output log"
	./$(EXE) castle.dat -1 logFile 

log_clean:
	@echo ">>>>>> Deleting log file"
	rm -rf logFile

run_cmd: 
	@echo ">>>>>> Running project files with input commands and output log"
	$ ./ castle castle .dat -l output .log < game1.cmd

runv:
	@echo ">>>>>> Running castle.dat with valgrind"
	valgrind --leak-check=full ./$(EXE) castle.dat

test: $(TEST)
	@echo ">>>>>> Making test files"
	@for t in $(TEST); do \
		echo "Running $$t..."; \
		./$$t; \
	done

test_clean:
	@echo ">>>>>> Deleting tests files"
	rm -rf $(TEST_OBJ) $(TEST) $(OBJ) 

doc:
	@echo ">>>>>> Making documentation file"
	doxygen Doxyfile

doc_clean:
	@echo ">>>>>> Deleting documentation file"
	rm -rf ./doc