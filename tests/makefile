CXX      := g++
CXXFLAGS := -Wall -Wextra -std=c++20 -O3 -g -I../src
LDFLAGS  := 

TARGET   := run_tests
OBJ_DIR  := build

# 2. Get all test files in the current folder
TEST_SRCS := $(wildcard *.cpp)

# 3. Get ALL application files from the src folder (handles subfolders automatically)
APP_SRCS  := $(shell find ../src -name "*.cpp")

# 4. CRITICAL: Remove the real main.cpp from the list!
APP_SRCS  := $(filter-out ../src/Main.cpp, $(APP_SRCS))

# Combine them into one big list
SOURCES   := $(TEST_SRCS) $(APP_SRCS)

# 5. Makefile Magic: Extract all the unique folders and tell Make to look inside them
SOURCE_DIRS := $(sort $(dir $(SOURCES)))
VPATH       := $(SOURCE_DIRS)

# Flatten all .o files into the build/ folder
OBJECTS   := $(addprefix $(OBJ_DIR)/, $(notdir $(SOURCES:.cpp=.o)))
DEPS      := $(OBJECTS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo "Linking: $@"
	@$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling: $<"
	@$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

-include $(DEPS)

clean:
	@echo "Cleaning up..."
	@rm -rf $(OBJ_DIR) $(TARGET)

run: all
	./$(TARGET) -s

.PHONY: all clean run
