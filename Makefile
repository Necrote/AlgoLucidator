CXX = g++
CXXFLAGS=-I. -w
LDFLAGS=-lGLU -lGL -lglut

all: ALmake
all: clean
all: run

debug: CXXFLAGS += -DDEBUG -g
debug: ALmake
debug: clean
debug: run	

ALmake: AlgoLucidator.o
	$(CXX) -o AlgoLucidator AlgoLucidator.o $(LDFLAGS) $(CFLAGS)

run: AlgoLucidator
	./AlgoLucidator

.PHONY: clean

clean:
	rm *.o
