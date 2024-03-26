ALL: wordle

SOURCES := $(wildcard *.cpp)
HEADERS := wordle.h #Only 1 header
SOURCES_test := player.cpp game.cpp 

OBJECTS := $(SOURCES:.cpp=.o)
%.o : %.cpp ${HEADERS}
	g++ -c $< $(CFLAGS)

wordle: ${OBJECTS}
	g++ -o $@ ${OBJECTS} $(LDFLAGS)

clean:
	rm -f *.o wordle