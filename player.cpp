//This is a file to handle the player class directly
#include "wordle.h"

/**
 * @file player.cpp
 * @brief Defining object specific to class @ref player
*/

/**
 * Setting the results of the game, from the output of the game class to the player class
 * @param solved The results of the game, communicated from the game class. 
*/
void player::set_solved_status(const results &solved) //Give player class results of the game
{
    this->n_guess = std::get<0>(solved);
    this->properly_solved = std::get<1>(solved);
    this->true_result = std::get<2>(solved);
}

/**
 * Printing out, nicely, if the player passed or failed the wordle game
*/
void player::print_player_results() //Print out final results!
{
    if(this->properly_solved)
    {
        std::cout << "Well done! You properly solved the wordle. \n";
    }
    else 
    {
        std::cout << "Unfortunately you did not properly solve this Wordle.\n";
    }
}

/**
 * Getter function to get the private number of guesses it took to end the game
*/
u_int player::get_n_guess() //Getter functions for player class with n_guess, result (true or false) and the true answer
{
    return this->n_guess;
}

/**
 * Getter function to get the private result of the game
*/
bool player::get_result()
{
    return this->properly_solved;
}

/**
 * Getter function to get the private answer to the game
*/
std::string player::get_answer()
{
    return this->true_result;
}

/**
 * Operator to print out information of the game (number of guesses, was it solved, and the true answer) with nice output. 
 * @param os: The ostream object we are saving this information to. 
 * @param User: The @ref player object containing the results of the game.
 * @return "Number of Guesses: (N_GUESS). Was the Wordle solved? (PROPERLY_SOLVED). The real answer was: (TRUE_RESULT)." 
*/
std::ostream &operator<< (std::ostream &os, const player &User) //Operator to print out information of the game
{
    os << "Number of Guesses: " << User.n_guess << ". Was the Wordle solved? " << (User.properly_solved ? "Yes":"No") << ". The real answer was: " << User.true_result << WHITE_BACKGROUND << "." << std::endl;
    return os;
}

/**
 * Empty constructor for player; just instantly initialize the game
*/
player::player() //Empty player constructor: just instantly initialize the game
{
    initialize();
}

/**
 * Destructor for player class
*/
player::~player() {}