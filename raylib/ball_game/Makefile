CXX = g++
CXXFLAGS = -Wall -std=c++17
TARGET = game
SRCS = $(wildcard *.cpp)

ifeq ($(OS),Windows_NT)
    TARGET := $(TARGET).exe
    LIBS = -I C:/raylib/raylib/src -L C:/raylib/raylib/src -lraylib -lgdi32 -lwinmm -lopengl32
    CLEAN = del /Q $(TARGET) 2>nul
else
    LIBS = $(shell pkg-config --cflags --libs raylib)
    CLEAN = rm -f $(TARGET)
endif

all:
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET) $(LIBS)

clean:
	$(CLEAN)

.PHONY: all clean