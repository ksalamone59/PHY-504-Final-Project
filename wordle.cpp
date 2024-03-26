//The main file, actually calling the game
#include "wordle.h"

/**
 * @file wordle.cpp 
 * @brief Calling the wordle game to be played with the user input.
*/

/**
 * Using CMAKE to automate unit testing. This is done by specifying "make CFLAGS="-DUNIT_TEST""
 * Make sure to run "make clean" in between running in unit test and regular mode
*/
#ifdef UNIT_TEST
#define DO_UNIT_TEST 1
#else 
#define DO_UNIT_TEST 0
#endif

int main()
{
    player User; //Instantizing player object, and initializing/playing game and writing out results
    /**
     * UNIT TESTING : doing unit testing for a) getting the answer right and b) getting it wrong in various ways. See README and other documentation for detailed instructions how to run
    */
    if(DO_UNIT_TEST) //Debugging, which can be turned on or off by CMAKE. See README and Doxygen code
    {
        std::cout << "In Unit Test mode! Please enter 'three'." << std::endl;
        User.set_answer("three"); //USED THIS WAY FOR UNIT TESTING ONLY
        User.set_solved_status(User.play_game()); //Give the first guess input as "three" please
        assert(User.get_answer() == "three"); //Asserting that we get "three" as the answer, true as a passed result and 1 as number of guesses
        assert(User.get_n_guess() == 1);
        assert(User.get_result() == true);
        User.print_player_results();
        std::cout << "Game Statistics: \n" << User;

        std::cout << RESET << "\nSecond testing: \n"; //Again, see README for reccomended way to run arguments here
        player User1;
        User1.set_answer("three");
        User1.set_solved_status(User1.play_game()); //This is testing the yellow letters, as well as what happens if you fail
        assert(User1.get_answer() == "three"); //Asserting that we get "three" as the real answer still
        assert(User1.get_n_guess() == 6);
        assert(User1.get_result() == false);
        User1.print_player_results();
        std::cout << "Game Statistics:\n" << User1;

        return 0; //Ending game here since we are doing unit testing
    }
    User.set_solved_status(User.play_game());
    User.print_player_results();
    std::cout << "Statistics: \n" << User;
    return 0;
}