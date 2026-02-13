CXX = g++
CXXFLAGS = -I. -std=c++20 -Wall -Wextra -pedantic

BUILD_DIR = build
BIN_DIR = bin

TARGET = option
BIN = $(BIN_DIR)/$(TARGET)
OBJ = $(BUILD_DIR)/option.o

option: $(BIN)

$(BIN): $(OBJ) | $(BIN_DIR)
	$(CXX) $^ -o $@

$(BUILD_DIR)/option.o: test/option.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

