#ifndef __wordle__
#define __wordle__

#include <iostream>
#include <cassert> //for assert
#include <fstream> //for ifstream 
#include <string> 
#include <algorithm> //to sort strings
#include <stdlib.h> //for srand() and coloring text
#include <time.h> //to initialize rand time
#include <map>
#include <tuple>

class game 
{
    protected:
        std::string answer; //Answer found from random number generator
    private: 
        std::ifstream dictionary; //Input file
        const u_int MAX_NUMBER{14855}; //Number of words in dictionary.txt
        const u_int MAX_N_GUESS{6}; //Max number of wordle guesses
        const std::string RED{"\033[31m"}; //ANSI color codings for red, yellow, green and white (RESET)
        const std::string YELLOW{"\033[33m"};
        const std::string GREEN{"\033[32m"};
        const std::string RESET{"\033[0m"};
    public: 
        void get_dictionary(); //Open ofstream object
        void close_dictionary(); //Close ofstream object
        void initialize(); //Gets the word for the game
        std::tuple<int,bool,std::string> play_game(); //Actually plays the game. <0>> returns n_guess,  <1> returns if you solved correctly or not, <2> returns the answer
};

class player: public game //Class for the user to play the game through. Constructed this way so player can only access answer AFTER being given it by game class
{
    private:
        u_int n_guess; //Number of guesses needed to solve
        bool properly_solved; //Did we solve the wordle?
        std::string true_result;
    public:
        player(int n_guess_, bool properly_solved_, std::string true_result_)//Rule of 3
        {
            n_guess = n_guess_;
            properly_solved = properly_solved_;
            true_result = true_result_;
        } 
        player() {};
        ~player() {};
        void set_solved_status(const std::tuple<int,bool,std::string> &solved);
        void print_player_results();
};

#endif 