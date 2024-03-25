#ifndef __wordle__
#define __wordle__

#include <iostream>
#include <string> 
#include <map>
#include <tuple>
#include <cassert> //for assert
#include <fstream> //for ifstream 
#include <stdlib.h> //for srand() and coloring text
#include <time.h> //to initialize rand time

using results = std::tuple<int,bool,std::string>; //Easier to write; results of the game

class game //Didn't need constructor, since everything is hard coded/uses RNG (and since player initializes the rng/game)
{
    private: 
        std::string answer; //Answer found from random number generator
        std::ifstream dictionary; //Input file
        const int MAX_NUMBER{14855}; //Number of words in dictionary.txt. See README for crediting
        const u_int MAX_N_GUESS{6}; //Max number of wordle guesses
        const std::string YELLOW{"\e[0;33m"}; //ANSI color codings for yellow, green and white (RESET). See README for reference
        const std::string GREEN{"\e[0;32m"};
        const std::string RESET{"\e[0;37m"};
    public: 
        void get_dictionary(); //Open ofstream object
        void close_dictionary(); //Close ofstream object
        void initialize(); //Gets the word for the game
        results play_game(); //Actually plays the game. <0>> returns n_guess,  <1> returns if you solved correctly or not, <2> returns the answer
        void set_answer(const std::string ans); //ONLY FOR UNIT TESTING: set the answer, and then play the game. See README
};

class player: public game //Class for the user to play the game through. Constructed this way so player can only access answer AFTER being given it by game class
{
    private:
        u_int n_guess; //Number of guesses needed to solve
        bool properly_solved; //Did we solve the wordle?
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