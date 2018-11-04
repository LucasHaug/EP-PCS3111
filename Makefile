BUILD_DIR := build
TARGET := EP2

SOURCES = $(wildcard *.cpp)
OBJECTS = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(SOURCES))

.PHONY: all clean run format

all: $(BUILD_DIR) EP2

$(BUILD_DIR):
	@echo "Creating build directory"
	@mkdir -p $@

$(BUILD_DIR)/%.o: %.cpp
	g++ -g -Wall -Wextra -std=c++11 -o $@ -c $^

clean:
ifeq ($(OS), Windows_NT)
	rm $(BUILD_DIR)/*.o *.exe
	rmdir $(BUILD_DIR)
else
	rm $(BUILD_DIR)/*.o EP2
	rmdir $(BUILD_DIR)
endif

EP2: $(OBJECTS)
	g++ -g -Wall -Wextra -o EP2 $(OBJECTS)

run: all
ifeq ($(OS), Windows_NT)
	start powershell -NoExit ./EP2
else
	tilda -c ./EP2
endif

