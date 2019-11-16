BUILD_DIR := build
FLAGS := -g -Wall -Wextra -std=c++11
COMPILER := g++
EXECUTABLE := ep2

VERBOSE ?= 0

# Verbosity
ifeq ($(VERBOSE),0)
AT := @
else
AT :=
endif

SOURCES = $(shell find src -name "*.cpp")
HEADERS = $(shell find inc -name "*.h")
OBJECTS:= $(addprefix $(BUILD_DIR)/,$(notdir $(SOURCES:.cpp=.o)))

vpath %.cpp $(sort $(dir $(SOURCES)))

C_INCLUDES  := $(addprefix -I,                            \
	$(sort $(dir $(HEADERS)))                             \
)

FLAGS += $(C_INCLUDES)

all: ep

ep: $(OBJECTS)
	$(AT)$(COMPILER) $(FLAGS) -o $(BUILD_DIR)/$(EXECUTABLE) $(OBJECTS)

$(BUILD_DIR):
	$(AT)echo "Creating build directory"
	$(AT)mkdir -p $@

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(AT)$(COMPILER) $(FLAGS) -o $@ -c $^

clean:
	$(AT)rm -rf $(BUILD_DIR)


run: all
ifeq ($(OS), Windows_NT)
	$(AT)start powershell -NoExit ./$(BUILD_DIR)/$(EXECUTABLE)
else
	$(AT)tilda -c ./$(BUILD_DIR)/$(EXECUTABLE)
endif

# Format source code using uncrustify
format:
	$(AT)uncrustify -c uncrustify.cfg --replace --no-backup $(SOURCES) $(HEADERS)


.PHONY: all clean run format