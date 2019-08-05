BIN := bin
SRC := src
OBJ := obj
CFLAGS := -Wall -std=c++14

INCLUDE := -I./include

SOURCES := $(wildcard src/*.cpp)

OBJECTS := $(subst .cpp,.o,$(SOURCES))
OBJECTS := $(subst src/,obj/,$(OBJECTS))

ejecutable: $(OBJECTS)  # utilizando una variable
	g++ -o $(BIN)/$@ $(CFLAGS) $^ $(INCLUDE)

$(OBJ)/%.o: $(SRC)/%.cpp
	g++ $(CFLAGS) -o $@ -c $^ $(INCLUDE)

info:
	$(info $(SOURCES))
	$(info $(OBJECTS))

clean:
	$(RM) $(OBJ)/*.o $(BIN)/ejecutable core