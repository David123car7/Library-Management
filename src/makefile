CXX      := g++
CXXFLAGS := -Wall -Wextra -std=c++20 -O3 -g
LDFLAGS  := 

TARGET   := program
SRC_DIR  := .
OBJ_DIR  := build

SOURCES  := $(shell find $(SRC_DIR) -name "*.cpp")
OBJECTS  := $(SOURCES:%.cpp=$(OBJ_DIR)/%.o)
DEPS     := $(OBJECTS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo "Linking: $@"
	@$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo "Compiling: $<"
	@$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

-include $(DEPS)

clean:
	@echo "Cleaning up..."
	@rm -rf $(OBJ_DIR) $(TARGET)

run: all
	./$(TARGET)

.PHONY: all clean run
