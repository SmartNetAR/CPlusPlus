BIN := bin
SRC := src
SRC_TEST := src/test
OBJ := obj
CFLAGS := -std=c++11 -Wall

INCLUDE := -I../

SOURCES_TEST := $(wildcard src/test/*.cpp)
SOURCES_SRC := $(wildcard src/*.cpp)
SOURCES := $(SOURCES_SRC) $(SOURCES_TEST)

OBJ_SRC := $(subst .cpp,.o,$(SOURCES_SRC))
OBJ_SRC := $(subst src/,obj/,$(OBJ_SRC))
OBJ_TEST := $(subst .cpp,.o,$(SOURCES_TEST))
OBJ_TEST := $(subst src/test/,obj/,$(OBJ_TEST))
OBJECTS_ALL := $(OBJ_SRC) $(OBJ_TEST)


test: $(OBJ_TEST)
	g++ $(CFLAGS) -o $(BIN)/$@.out $^ $(INCLUDE)
	$(RM) $(OBJ)/queueTest.o #/*lo borro porque sino no recomila Stack.cpp*/
	./$(BIN)/$@.out --reporter compact --success

# $(OBJ)/%.o: $(SRC)/%.cpp
# 	g++ $(CFLAGS) -o $@ -c $^ $(INCLUDE)

$(OBJ)/%.o: $(SRC_TEST)/%.cpp
	g++ $(CFLAGS) -o $@ -c $^ $(INCLUDE)

# out: $(OBJECTS_ALL)
	# g++ -o $(BIN)/$@ $(CFLAGS) $^ && ./bin/main.out

$(OBJ)/%.o: $(SRC)/%.cpp
	g++ $(CFLAGS) -o $@ -c $^

info:
	$(info $(SOURCES))
	$(info $(OBJECTS_ALL))

clean:
	$(RM) $(OBJ)/*.o $(BIN)/test.out core