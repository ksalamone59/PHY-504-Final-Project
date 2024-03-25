//File for unit testing; contains only function relevant to unit testing. Run with ./test after running make
#include "wordle.h"

int main()
{
    player User; //Instatiating a player, and initializing the game 
    User.set_answer("three"); //USED THIS WAY FOR UNIT TESTING ONLY
    User.set_solved_status(User.play_game()); //Give the first guess input as "three" please
    assert(User.get_answer() == "three"); //Asserting that we get "three" as the answer, true as a passed result and 1 as number of guesses
    assert(User.get_n_guess() == 1);
    assert(User.get_result() == true);
    User.print_player_results();
    std::cout << "Game Statistics: \n" << User;

    std::cout << RESET << "Second testing: \n"; //Again, see README for reccomended way to run arguments here
    player User1;
    User1.set_answer("three");
    User1.set_solved_status(User1.play_game()); //This is testing the yellow letters, as well as what happens if you fail
    assert(User1.get_answer() == "three"); //Asserting that we get "three" as the real answer still
    assert(User1.get_n_guess() == 6);
    assert(User1.get_result() == false);
    User1.print_player_results();
    std::cout << "Game Statistics:\n" << User1;

    return 0;
}