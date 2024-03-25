//This is a file to handle the player class directly
#include "wordle.h"

void player::set_solved_status(const results &solved) //Give player class results of the game
{
    this->n_guess = std::get<0>(solved);
    this->properly_solved = std::get<1>(solved);
    this->true_result = std::get<2>(solved);
}

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

u_int player::get_n_guess() //Getter functions for player class with n_guess, result (true or false) and the true answer
{
    return this->n_guess;
}

bool player::get_result()
{
    return this->properly_solved;
}

std::string player::get_answer()
{
    return this->true_result;
}

std::ostream &operator<< (std::ostream &os, const player &User) //Operator to print out information of the game
{
    os << "Number of Guesses: " << User.n_guess << ". Was the Wordle solved? " << (User.properly_solved ? "Yes":"No") << ". The real answer was: " << User.true_result << std::endl;
    return os;
}

player::player() //Empty player constructor: just instantly initialize the game
{
    initialize();
}

player::~player() {}