BIN := bin
SRC := src
OBJ := obj
CFLAGS := -std=c++14

INCLUDE := #-I./include #-I../../src

SOURCES := $(wildcard src/*.cpp)

OBJECTS := $(subst .cpp,.o,$(SOURCES))
OBJECTS := $(subst src/,obj/,$(OBJECTS))

test: $(OBJECTS)
	g++ -o $(BIN)/$@ $(CFLAGS) $^ && ./bin/test --reporter compact --success

$(OBJ)/%.o: $(SRC)/%.cpp
	g++ $(CFLAGS) -o $@ -c $^
info:
	$(info $(SOURCES))
	$(info $(OBJECTS))

clean:
	$(RM) $(OBJ)/*.o $(BIN)/test core