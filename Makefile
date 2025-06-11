# Aryan Kumar

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O3 -flto -DNDEBUG -MMD -MP 

# Platform detection
UNAME_S := $(shell uname -s)
ifeq ($(OS),Windows_NT)
    TARGET = main.exe
else ifeq ($(UNAME_S),Linux)
    TARGET = main.out
else ifeq ($(UNAME_S),Darwin)
    TARGET = main.out
else
    TARGET = main.out
endif

SRCS = main.cpp board.cpp minmax.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(DEPS)

run: $(TARGET)
	@./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJS) $(DEPS)

.PHONY: all clean run
