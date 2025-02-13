# Compiler
CXX = clang++
CXXFLAGS = -Wall -Wextra -std=c++11

# Find all .cpp files
SOURCES = $(shell find . -name '*.cpp')

# Create a list of output executables by replacing .cpp with .elf
EXECUTABLES = $(SOURCES:.cpp=.elf)

# Default target
all: $(EXECUTABLES)

# Rule to compile each .cpp file to an executable with .elf extension
%.elf: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# Clean target to remove executables
clean:
	rm -f $(EXECUTABLES)

.PHONY: all clean
