BUILD_DIR := build
TARGET := EP1

SOURCES = $(wildcard *.cpp)
OBJECTS = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(SOURCES))

.PHONY: all clean run format

all: $(BUILD_DIR) EP1

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
	rm $(BUILD_DIR)/*.o EP1
	rmdir $(BUILD_DIR)
endif

EP1: $(OBJECTS)
	g++ -g -Wall -Wextra -o EP1 $(OBJECTS)

run: all
ifeq ($(OS), Windows_NT)
	start powershell -NoExit ./EP1
else
	tilda -c ./EP1
endif

