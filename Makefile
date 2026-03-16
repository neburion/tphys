# =================================================================================================
# Compiler & Flags
# =================================================================================================
CXX     = g++
LIBS    = -lncurses
INCLUDE = -Iinclude

RELEASE_FLAGS = $(INCLUDE) -std=c++17 -O2 -DNDEBUG
DEBUG_FLAGS   = $(INCLUDE) -std=c++17 -g -Wall -Wextra -Wpedantic -fsanitize=undefined,address,leak

# =================================================================================================
# Files
# =================================================================================================
SRC         = $(wildcard src/*.cpp)
TEST_SRC    = $(filter-out src/main.cpp, $(wildcard src/*.cpp))
RELEASE_OBJ = $(patsubst src/%.cpp, build/release/%.o, $(SRC))
DEBUG_OBJ   = $(patsubst src/%.cpp, build/debug/%.o, $(SRC))
TEST_OBJ    = $(patsubst src/%.cpp, build/test/%.o, $(TEST_SRC))

EXEC  = bin/engine
DEXEC = bin/dbg-engine
TEXEC = bin/test-engine

# =================================================================================================
# Targets
# =================================================================================================
.PHONY: all dbg test clean clean-release clean-debug

all: $(EXEC)

dbg: $(DEXEC)

test: $(TEXEC)

# =================================================================================================
# Binaries
# =================================================================================================
$(EXEC): $(RELEASE_OBJ) | bin
	$(CXX) $(RELEASE_OBJ) -o $@ $(LIBS)

$(DEXEC): $(DEBUG_OBJ) | bin
	$(CXX) $(DEBUG_OBJ) -o $@ $(LIBS) $(DEBUG_FLAGS)

$(TEXEC): $(TEST_OBJ) | bin
	$(CXX) $(DEBUG_FLAGS) tests/test.cpp $(TEST_OBJ) -o $@ $(LIBS)

# =================================================================================================
# Object Files
# =================================================================================================
build/release/%.o: src/%.cpp | build/release
	$(CXX) $(RELEASE_FLAGS) -c $< -o $@

build/debug/%.o: src/%.cpp | build/debug
	$(CXX) $(DEBUG_FLAGS) -c $< -o $@

build/test/%.o: src/%.cpp | build/test
	$(CXX) $(DEBUG_FLAGS) -c $< -o $@

# =================================================================================================
# Directories
# =================================================================================================
bin build/release build/debug build/test:
	mkdir -p $@

# =================================================================================================
# Clean
# =================================================================================================
clean:
	rm -rf build/ bin/

clean-release:
	rm -rf build/release/ $(EXEC)

clean-debug:
	rm -rf build/debug/ $(DEXEC)
