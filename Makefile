CXX = g++
CXXFLAGS = -I.

TARGET = main

BUILD_DIR = build
BIN_DIR = bin

SRC = main.cpp
OBJ = $(BUILD_DIR)/main.o
BIN = $(BIN_DIR)/$(TARGET)

all: $(BIN)

$(BIN): $(OBJ) | $(BIN_DIR)
	$(CXX) $^ -o $@

$(BUILD_DIR)/main.o: main.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -rf build bin

