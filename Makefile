CXX := c++
CXXFLAGS := -O2 -Wall -Wextra -std=c++23
SRCS := main.cpp A_BOARDS.cpp funcs.cpp types.cpp
TARGET := main

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

debug:
	$(CXX) $(CXXFLAGS) -g -fsanitize=address,undefined -O0 $(SRCS) -o main_debug

clean:
	rm -f $(TARGET) main_debug

.PHONY: clean debug
