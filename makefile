CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Directories
INCLUDE_DIR = include
SRC_DIR = src
TEST_DIR = tests

# Files
SRC_FILES = $(SRC_DIR)/BigInt.cpp $(SRC_DIR)/main.cpp
TEST_FILES = $(SRC_DIR)/BigInt.cpp $(TEST_DIR)/test_bigint.cpp

# Targets
EXECUTABLE = bigint
TEST_EXECUTABLE = test_bigint

# Build main executable
$(EXECUTABLE): $(SRC_FILES)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -o $@ $^

# Build test executable
$(TEST_EXECUTABLE): $(TEST_FILES)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -o $@ $^

# Clean
clean:
	rm -f $(EXECUTABLE) $(TEST_EXECUTABLE)
