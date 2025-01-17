# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -g -Wall -Werror

# Executable name
EXEC = testcase

# Source files
SRCS = testcase.cc ../rawMaterials.cc

# Header files
HDRS = ../rawMaterials.hh

# Object files
OBJS = $(SRCS:.cc=.o)

# Default target
all: $(EXEC)

# Link the executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files into object files
%.o: %.cc $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -I..

# Clean up build files
clean:
	rm -f $(OBJS) $(EXEC)

# Run the test case
run: $(EXEC)
	./$(EXEC)

.PHONY: all clean run