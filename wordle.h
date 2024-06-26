#ifndef __wordle__
#define __wordle__

/**
 * @file wordle.h
 * @brief Header file containing includes, global variables, and forward declarations for class game and player.
*/

#include <iostream>
#include <string> 
#include <map>
#include <tuple>
#include <sstream> //for istringstream
#include <cassert> //for assert
#include <fstream> //for ifstream 
#include <stdlib.h> //for srand() and coloring text
#include <time.h> //to initialize rand time
#include <ctype.h> //for isalpha()

/**
 * Alias for std::tuple<int,bool,std::string> to hold the...<number_guesses, properly_solved_game (True for yes, False for no), true answer>
*/
using results = std::tuple<int,bool,std::string>; //Easier to write; results of the game
/**
 * ANSI color coding for yellow text with black background.
*/
const std::string YELLOW{"\033[0;33;40m"}; //ANSI color codings for yellow, green and white (RESET) with black backgrounds. See README for reference
/**
 * ANSI color coding for green text with black background.
*/
const std::string GREEN{"\033[0;32;40m"};
/**
 * ANSI color coding for white text with black background.
*/
const std::string RESET{"\033[0;37;40m"};
/**
 * ANSI color coding to reset to white background.
*/
const std::string WHITE_BACKGROUND{"\033[0;37"};

/**
 * The main class for the wordle game. Contains the logic for opening/closing the dictionary, getting a random word, setting the answer, and playing the game with color-coded I/O with the user.
*/
class game //Didn't need constructor, since everything is hard coded/uses RNG (and since player initializes the rng/game)
{
    private: 
        /**
         * Answer found from random number generator
        */
        std::string answer; 
        /**
         * Input file
        */
        std::ifstream dictionary;
        /**
         * Number of words in dictionary.txt. See README for crediting
        */
        const int MAX_NUMBER{14847};
        /**
         * Max number of wordle guesses*/ 
        const u_int MAX_N_GUESS{6}; 
        /**
         * Input stream (allows for custom inputs for unit testing)
        */
        std::istream *input_stream;
    public: 
        void get_dictionary(); //Open ifstream object
        void close_dictionary(); //Close ifstream object
        void initialize(); //Gets the word for the game
        void set_answer(const std::string &ans); 
        void check_spaces(std::string &input); //Ensures no spaces in user input
        void check_length(std::string &input); //Check length of word
        bool space_input_only(const std::string &input); //Checks if input is only space characters
        void set_streams(std::istream &in); //Setting input stream
        void take_input(std::string &input); //Taking in user input
        results play_game(); //Actually plays the game. <0> returns n_guess,  <1> returns if you solved correctly or not, <2> returns the answer
};

/**
 * The derived class of the player of the game. Handles the I/O of the results of the game, calling the initializing of the game, and an operator to print out the results nicely.
*/
class player: public game //Class for the user to play the game through. Constructed this way so player can only access answer AFTER being given it by game class
{
    private:
        /**
        * How many guesses were inputted this game
        */
        u_int n_guess; 
        /**
         * Did we properly solve the game?
        */
        bool properly_solved; 
        /**
         * The true answer of the game
        */
        std::string true_result;
    public:
        player();
        ~player();
        bool get_result(); //Getter functions for private members
        u_int get_n_guess();
        std::string get_answer();
        void set_solved_status(const results &solved); //Communicating result from game to player class
        void print_player_results(); //Write out the results from the player
        friend std::ostream &operator<< (std::ostream &os, const player &User); //Operator to print out players information from the game
};

#endif 