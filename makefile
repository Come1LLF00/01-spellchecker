CC                 = clang
CXX                = clang++

SOURCES            = src
INCLUDES           = inc
OBJECTS            = obj

EXECUTABLE         = spellchecker

CXX_STANDARD       = -std=c++17

CXX_INCLUDE_FLAGS  = -I$(INCLUDES)

CXX_DEBUG_FLAGS    = -Wall -Werror -g
CXX_SANITIZE_FLAGS = -fsanitize=address,leak,undefined
CXX_RELEASE_FLAGS  = -O3

CXX_FLAGS          = $(CXX_STANDARD) $(CXX_INCLUDE_FLAGS) $(CXX_DEBUG_FLAGS)

all: main.o

build:
	mkdir $(OBJECTS)

main.o: $(SOURCES)/main.cpp build
	$(CXX) $(CXX_FLAGS) -c $< -o $(OBJECTS)/$@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)