ALL: wordle

SOURCES := $(wildcard *.cpp)
HEADERS := wordle.h #Only 1 header

OBJECTS := $(SOURCES:.cpp=.o)
%.o : %.cpp ${HEADERS}
	g++ -c $< $(CFLAGS)

wordle: ${OBJECTS}
	g++ -o $@ ${OBJECTS} $(LDFLAGS)

clean:
	rm -f *.o wordle