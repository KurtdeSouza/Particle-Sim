CXX = g++
CXXFLAGS = -std=c++17 $(shell pkg-config --cflags sdl2)
LDFLAGS = $(shell pkg-config --libs sdl2)

sim: render.cpp
	$(CXX) render.cpp -o sim $(CXXFLAGS) $(LDFLAGS)

clean:
	rm -f sim