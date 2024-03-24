# PHY-504-Final-Project
**Final Project for PHY 504: a Wordle Game**

dictionary.txt: contains all valid wordle words; thanks to user Dracos/this git repo: https://gist.github.com/dracos/dd0668f281e685bad51479e5acaadb93 

In reading in from this file, since it starts at line 1, we will say that the nth word in the random number generator is the (n+1)st word in the dictionary (random number = 0, word = 1)

For the random number generator: https://cplusplus.com/reference/cstdlib/rand/

ANSI color coding help: https://gist.github.com/RabaDabaDoba/145049536f815903c79944599c6f952a 

This code makes use of tuples of length 3; this was done by using https://en.cppreference.com/w/cpp/utility/tuple

To run the code: run "make" and then "./wordle" (or make && ./wordle)

**DESCRIPTION OF FILES:**

dictionary.txt: A long list, credited above, of 5 letter wordle accepted letters 

wordle.h: The header file. Contains the parent class game, and then the child class player. Defines the constructors of both class, and as well defines many variables like the max number of guesses, how many words are in dictionary.txt, the ANSI color cout variables, and holds all of the functions needed by the constituent classes. 

wordle.cpp: Simple file to create a player, have the player initialize and then play the game. Then, print out the results of the game. 

game.cpp: The file for the "game" class specific functions. From opening and closing the dictionary, to initializing the game with a random word from the dictionary, to playing the game and going through the logic to determine what color each letter should be drawn and returning the appropriate information based on if you beat the game or not. 

player.cpp: The file for the "player" class specific functions. Mostly setting the private variables like the number of guesses it took, the status if we passed or failed the game, and the true answer. Prints all of this information out. 

GNUmakefile: make file to assist with using multiple files, and helps with unit testing. 

**UNIT TESTING**
