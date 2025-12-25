CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -g

SRC = \
    engine/core/Engine.cpp \
    game/main.cpp

OBJ = $(SRC:.cpp=.o)

engine: $(OBJ)
	$(CXX) $(OBJ) -o game_engine

clean:
	rm -f $(OBJ) game_engine
.PHONY: clean