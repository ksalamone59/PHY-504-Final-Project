# PHY-504-Final-Project
## Final Project for PHY 504: a Wordle Game

This is the final project for PHY 504 by Kyle Salamone, in which I recreate the NYT hit game wordle through two class structures: the game itself, and the derived player class.

The GitHub Pages page is located at: https://ksalamone59.github.io/PHY-504-Final-Project/. 

## References/Examples

dictionary.txt: contains all valid wordle words; thanks to user Dracos/this git repo: https://gist.github.com/dracos/dd0668f281e685bad51479e5acaadb93 

In reading in from this file, since it starts at line 1, we will say that the nth word in the random number generator is the (n+1)st word in the dictionary (random number = 0, word = 1)

For the random number generator: https://cplusplus.com/reference/cstdlib/rand/

ANSI color coding help: https://gist.github.com/RabaDabaDoba/145049536f815903c79944599c6f952a https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797 https://cplusplus.com/forum/beginner/7303/

This code makes use of tuples of length 3; this was done by using https://en.cppreference.com/w/cpp/utility/tuple

For the style of debugging I chose in my GNUmakefile: I took heavy inspiration from https://stackoverflow.com/questions/50329451/ifdef-and-conditional-compilation-with-makefile, https://stackoverflow.com/questions/13249610/how-to-use-ldflags-in-makefile and the PHY 504 OpenMP file notes. 

For sstream stuff: googled all over the place, found useful help in these few pages: https://www.reddit.com/r/cpp_questions/comments/smj7et/how_to_pass_variables_to_cin_standard_input/ https://www.geeksforgeeks.org/processing-strings-using-stdistringstream/ https://en.cppreference.com/w/cpp/io/basic_istringstream . I figured out the "\n"/newline stuff to simulate multiple user inputs in a row through testing.

# DESCRIPTION OF THE CODE

The code is commented fairly well, but to go over it briefly here: the class __game__ holds the actual declarations and variables needed for the worlde game: calling the dictionary and closing it, getting a random word from the dictionary, handling the I/O with the user while playing the game, storing the answer, and then communicating the results of the game to the player afterwards. The derived __player__ class (child class of game) in turn simply handles the player itself: from outputting the results of the game, to initializing the game upon the creation of a player. 

# RUNNING THE CODE

To run unit testing, see the **UNIT TESTING** section below. To run the main code, clone this repo and then run make, and then ./wordle. In one line (using make clean to ensure we can switch between unit testing and run mode at will): ````make clean && make && ./wordle````.

The code is designed similarly to the NYT wordle game: the correct letter in the right spot colors green, the correct letter in the wrong spot colors yellow, and an incorrect letter (not in the final results at all) colors white (I force a black background as well; I run dark mode on my terminal so I didn't think about that). 

# DESCRIPTION OF FILES

dictionary.txt: A long list, credited above, of 5 letter wordle accepted letters 

wordle.h: The header file. Contains the parent class game, and then the child class player. Defines the constructors of both class, and as well defines many variables like the max number of guesses, how many words are in dictionary.txt, the ANSI color cout variables, and holds all of the functions needed by the constituent classes. 

wordle.cpp: Simple file to create a player, have the player initialize and then play the game. Then, print out the results of the game. 

game.cpp: The file for the "game" class specific functions. From opening and closing the dictionary, to initializing the game with a random word from the dictionary, to playing the game and going through the logic to determine what color each letter should be drawn and returning the appropriate information based on if you beat the game or not. 

player.cpp: The file for the "player" class specific functions. Mostly setting the private variables like the number of guesses it took, the status if we passed or failed the game, and the true answer. Prints all of this information out. 

GNUmakefile: make file to assist with using multiple files, and helps with unit testing. 

Doxyfile: Doxygen file. See "DOXYGEN DOCUMENTATION" for more. 

# DOXYGEN DOCUMENTATION

Makes use of Doxygen to create documentation hub. Upon calling "doxyen Doxyfile" will create directory "docs". Go to docs/html, and observe the .html files from there (or call google-chrome on it, etc.).

# UNIT TESTING

The Unit Testing for this repository will be just giving the game with certain arguments. Example: I am forcing the word to be "three", so therefore if we instantize the game and instantly give "Three", we should get back true and that n_guess = 1 (which I will assert). As well, if we give a list of strings for the user to input in a row, they can ensure the coloring is proper and failed results work. I.e. if we force "three" again as the true result: if we start with "eeemm" (we don't care if the inputs are actual words, as per the problem statement) the first two "e" should be yellow, the third white and the two "m" white. Then if we go with "tteeh" the first "t" will be green, second will be white, first "e" yellow, second green and the "h" will be yellow. Then in order you can go: "aaaaa" for all white, "threw" for all green besdies the w, "hhhhh" for one green in the second spot and, finally, "rrrrr" for one green in the third spot, along with the failed results. These are all testing that the wordle function is behaving as expected and properly; since it requires user input the user can feel free to do their own unit testing on the word "three" as well, beyond what I have given (while of course, understanding the rules of wordle). 

There will also be some testing in the form of a github pages yml file similar to HW6; this is done automatically upon pushing the code and making use of our unit testing output, stored in "test.txt" (pay no mind to the text in this file, it is muddied by some of the ANSI color codings).

## RUNNING UNIT TESTING 

To run the Unit Test, please make sure you run "make clean" to set everything for initialization. Then, run "make CFLAGS="-DUNIT_TEST"" and call ./wordle. In a one liner: ````make clean && make CFLAGS="-DUNIT_TEST" && ./wordle````. The testing is done in two stages, described below (and above in more detail):

- **FIRST TEST :**
  - Input "three" right away
- **SECOND TEST :** input, for visuals (the inuputs with numbers won't be printed, but they'll be told that there is incorrect input):
  - "eeemm"
  - "nTTE3h"
  - "n33TEN"
  - "ntteEH"
  - "aaaaa"
  - "threw"
  - "hhhhh"
  - "eeeel"
