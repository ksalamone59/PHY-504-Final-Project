ALL: wordle test

SOURCES := wordle.cpp player.cpp game.cpp #3 cpp files; NON UNIT TESTING
HEADERS := wordle.h #Only 1 header
SOURCES_test := testing.cpp player.cpp game.cpp 

OBJECTS := $(SOURCES:.cpp=.o)
%.o : %.cpp ${HEADERS}
	g++ -c $<

wordle: ${OBJECTS}
	g++ -o $@ ${OBJECTS}

OBJECTS_test := $(SOURCES_test:.cpp=.o)
%.o : %.cpp ${HEADERS}
	g++ -c $<

test: ${OBJECTS_test}
	g++ -o $@ ${OBJECTS_test}