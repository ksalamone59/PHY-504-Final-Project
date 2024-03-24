ALL: wordle

SOURCES := $(wildcard *.cpp) #3 cpp files
HEADERS := wordle.h #Only 1 header

OBJECTS := $(SOURCES:.cpp=.o)
%.o : %.cpp ${HEADERS}
	g++ -c $<

# explicitly write the rule for linking together the executable

wordle: ${OBJECTS}
	g++ -o $@ ${OBJECTS}