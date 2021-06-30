CC                 = clang
CXX                = clang++

SOURCES            = src
INCLUDES           = inc
OBJECTS            = obj

EXECUTABLE         = spellchecker

CXX_STANDARD       = -std=c++17

CXX_INCLUDE_FLAGS  = -I$(INCLUDES)

CXX_DEBUG_FLAGS    = -Wall -Werror -g
CXX_SANITIZE_FLAGS = -fsanitize=address,undefined
CXX_RELEASE_FLAGS  = -O3

CXX_FLAGS          = $(CXX_STANDARD) $(CXX_INCLUDE_FLAGS)

all: release

build:
	mkdir -p $(OBJECTS)

$(OBJECTS)/main.o: $(SOURCES)/main.cpp $(OBJECTS)/store.o build
	$(CXX) $(CXX_FLAGS) -c $< -o $@

$(OBJECTS)/store.o: $(SOURCES)/store.cpp build
	$(CXX) $(CXX_FLAGS) -c $< -o $@

link: $(OBJECTS)/main.o $(OBJECTS)/store.o
	clang++ $(LD_FLAGS) -o $(EXECUTABLE) $^

debug: CXX_FLAGS += $(CXX_DEBUG_FLAGS)
debug: link

release: CXX_FLAGS += $(CXX_DEBUG_FLAGS) $(CXX_RELEASE_FLAGS)
release: link

sanitize: CXX_FLAGS += $(CXX_DEBUG_FLAGS) $(CXX_SANITIZE_FLAGS)
sanitize: LD_FLAGS := $(CXX_SANITIZE_FLAGS)
sanitize: link

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)