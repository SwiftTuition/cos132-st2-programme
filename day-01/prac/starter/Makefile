CXX = g++
CXXFLAGS = -std=c++98 -Wall -Wextra -pedantic

squad: main.cpp Squad.cpp Squad.h
	$(CXX) $(CXXFLAGS) -o squad main.cpp Squad.cpp

.PHONY: clean
clean:
	rm -f squad
