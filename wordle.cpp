//The main file, actually calling the game
#include "wordle.h"

int main()
{
    player User; //Instantizing player object, and initializing/playing game and writing out results
    User.set_solved_status(User.play_game());
    User.print_player_results();
    std::cout << "Statistics: \n" << User;
    return 0;
}