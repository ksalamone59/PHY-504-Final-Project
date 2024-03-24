# PHY-504-Final-Project
Final Project for PHY 504 as a Wordle Solver (as suggeted)

dictionary.txt: contains all valid wordle words; thanks to user Dracos/this git repo: https://gist.github.com/dracos/dd0668f281e685bad51479e5acaadb93 
In reading in from this file, since it starts at line 1, we will say that the nth word in the random number generator is the (n+1)st word in the dictionary (random number = 0, word = 1)
For the random number generator: https://cplusplus.com/reference/cstdlib/rand/
ANSI color coding help: https://gist.github.com/RabaDabaDoba/145049536f815903c79944599c6f952a 

This code makes use of tuples of length 3; this was done by using https://en.cppreference.com/w/cpp/utility/tuple
