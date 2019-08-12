BIN := bin
SRC := src
SRC_MAIN := src/main
SRC_TEST := src/test
OBJ := obj
CFLAGS := -std=c++14

INCLUDE := -I../

SOURCES_TEST := $(wildcard src/test/*.cpp)
SOURCES_SRC := $(wildcard src/*.cpp)
SOURCES_SRC_MAIN := $(wildcard src/main/*.cpp)
SOURCES := $(SOURCES_SRC) $(SOURCES_TEST)

OBJ_SRC := $(subst .cpp,.o,$(SOURCES_SRC))
OBJ_SRC := $(subst src/,obj/,$(OBJ_SRC))
OBJ_MAIN := $(subst .cpp,.o,$(SOURCES_SRC_MAIN))
OBJ_MAIN := $(subst src/main/,obj/,$(OBJ_MAIN))
OBJ_TEST := $(subst .cpp,.o,$(SOURCES_TEST))
OBJ_TEST := $(subst src/test/,obj/,$(OBJ_TEST))
OBJECTS_ALL := $(OBJ_SRC) $(OBJ_TEST)


test: $(OBJ_TEST)
	g++ $(CFLAGS) -o $(BIN)/$@.out $^ $(INCLUDE)
	$(RM) $(OBJ)/contarPalabras.o #/*lo borro porque sino no recomila contarPalabras.cpp*/
	./$(BIN)/$@.out --reporter compact --success

$(OBJ)/%.o: $(SRC_TEST)/%.cpp
	g++ $(CFLAGS) -o $@ -c $^ $(INCLUDE)

$(OBJ)/%.o: $(SRC)/%.cpp
	g++ $(CFLAGS) -o $@ -c $^

main: $(OBJ_MAIN)
	g++ $(CFLAGS) -o $(BIN)/$@.out $^
	# $(RM) $(OBJ)/contarPalabras.o #/*lo borro porque sino no recomila contarPalabras.cpp*/
	./$(BIN)/$@.out

$(OBJ)/%.o: $(SRC_MAIN)/%.cpp # g++ -std=c++14 -o bin/main.out src/main/main.cpp
	g++ $(CFLAGS) -o $@ -c $^ $(INCLUDE)
	# g++ -std=c++14 -o obj/main.o src/main.cpp

# $(OBJ)/%.o: $(SRC_TEST)/%.cpp
# 	g++ $(CFLAGS) -o $@ -c $^ $(INCLUDE)

# out: $(OBJECTS_ALL)
	# g++ -o $(BIN)/$@ $(CFLAGS) $^ && ./bin/main.out

# $(OBJ)/%.o: $(SRC)/%.cpp
# 	g++ $(CFLAGS) -o $@ -c $^

info:
	$(info $(SOURCES))
	$(info $(OBJECTS_ALL))

infoMain:
	$(info $(SOURCES_SRC))
	$(info $(OBJ_SRC))

clean:
	$(RM) $(OBJ)/*.o $(BIN)/test.out core
	$(RM) $(OBJ)/*.o $(BIN)/main.out core