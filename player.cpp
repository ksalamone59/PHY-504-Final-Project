//This is a file to handle the player class directly
#include "wordle.h"

void player::set_solved_status(const std::tuple<int,bool,std::string> &solved) //Give player class results of the game
{
    this->n_guess = std::get<0>(solved);
    this->properly_solved = std::get<1>(solved);
    this->answer = std::get<2>(solved);
}

void player::print_player_results() //Print out final results!
{
    if(this->properly_solved)
    {
        std::cout << "Well done! You properly solved the wordle in " << this->n_guess << " guesses!\n";
    }
    else 
    {
        std::cout << "Unfortunately you did not properly solve this wordle. The real word was: " << this->answer << "." << std::endl;
    }
}