CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -g

INCLUDES = -Iengine -Ithirdparty/glad/include
INCLUDES += -Ithirdparty/glm
LIBS = -lglfw -lGL

SRC = \
    engine/core/Engine.cpp \
    engine/window/Window.cpp \
    thirdparty/glad/src/glad.c \
    game/main.cpp \
	engine/rendering/Shader.cpp \
	engine/rendering/Renderer.cpp \
	engine/rendering/Camera2D.cpp


OBJ = $(SRC:.cpp=.o)
OBJ := $(OBJ:.c=.o)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

%.o: %.c
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

game_engine: $(OBJ)
	$(CXX) $(OBJ) $(LIBS) -o game_engine

clean:
	rm -f $(OBJ) game_engine
