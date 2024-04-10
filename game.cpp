//This file handles the actual "wordle" game itself
#include "wordle.h"

/**
 * @file game.cpp
 * @brief Defining objects specific to class @ref game; actually playing the wordle game.
*/

/**
 * Opening the dictionary.txt file
*/
void game::get_dictionary() //Open dictionary to read in from
{
    dictionary.open("dictionary.txt");
}

/**
 * Initializing the Wordle game. Uses random number generator to get a random word from the dictionary.txt file, and then sets the answer
*/
void game::initialize() //Get the current wordle guess
{
    std::string rand_word;
    srand(time(NULL)); //Initialize random number generator
    int rand_number{rand() % (MAX_NUMBER+1)}; //Random word from the list of words (recall: 0->1, 1->2, etc. See README)
    int curr_word{0}; //To loop through dictionary file 
    get_dictionary(); //Get the dictionary
    while(dictionary.good()) //Continue looping through dictionary until we get line we want
    {
        getline(dictionary,rand_word);
        if(curr_word++ == rand_number) break;
    }
    set_answer(rand_word); //Set the answer to the game
    close_dictionary(); //Close the dictionary
}

/**
 * Closing the dictionary.txt file
*/
void game::close_dictionary() //Close dictionary
{
    dictionary.close();
}

/**
 * Setting user defined input stream; output automatically is set to std::cout
 * @param in Input stream; either std::cin for actual game or some istringstream for unit testing
*/
void game::set_streams(std::istream &in)
{
    this->input_stream = &in;
}

/**
 * Checking if input has any spaces; done this way as it's called multiple times
 * @param input user input necessary from wordle game
 * @return input without spaces
*/
void game::check_spaces(std::string &input)
{
    for(int i=0;i<input.length();i++) //Gets rid of any spaces
    {
        if(isspace(input[i]))
        {
            input.erase(input.begin()+i);
        }
    }
}

/**
 * Playing the game itself. Keeps track of properly placed letters (green), correct letters in the incorrect place (yellow) and incorrect letters (white). Allows 6 user gueses, forces all lowercase and 5 letters long (spaces do not count). 
 * @return @ref results of the game.
*/
results game::play_game()
{
    u_int n_guess = 0; //How many guesses it took
    std::string out_names[6] = {"first","second","third","fourth","fifth","sixth and final"}; //Making I/O easier
    std::cout << RESET << std::endl; //Easiet way to force background text styles to be the same regardless of editor/terminal themes
    while(n_guess < MAX_N_GUESS) //Only 6 guesses
    {
        std::string input;
        std::cout << "Please enter your " << out_names[n_guess] << " guess: "; //Does NOT need to be a valid english word
        std::getline(*(this->input_stream),input);
        check_spaces(input);
        while(input.length() != 5) //Testing to ensure we get 5 letter words only
        {
            std::cout << "Oops! You need a five letter word to play the game. Please re enter a 5 letter word: ";
            std::getline(*(this->input_stream),input);
            check_spaces(input);
        }
        bool good_word = false;
        while(!good_word) //Ensuring that all inputs are in the standard alphabet
        {
            int n_good = 0;
            for(const auto &c: input)
            {
                if(!isalpha(c))
                {
                    std::cout << "Oops! All characters must be in the alphabet. Character " << c << " is not allowed. Please re enter a 5 letter word, totally in the alphabet: ";
                    *(this->input_stream) >> input;
                    check_spaces(input);
                    break;
                }
                else n_good++;
            }
            if(n_good == 5) good_word = true;
        }
        for(auto &c: input) //Ensure that all inputs are lowercase
        {
            if(isupper(c)) //This checks if c is uppercase, and then forces it to be lowercase
            {
                c += 32; //This converts the character from upper to lower case. See README for documentation
            }
        }
        n_guess++;
        if(input == answer) //Guess is fully correct
        {
            std::cout << GREEN << input << RESET << std::endl; //Print out word in green
            return std::make_tuple(n_guess,true,this->answer); //Return successful guess with n_guess guesses
        }
        bool good_input[5] = {false}; //See if current entry is already accounted for 
        std::map<char,int> n_occurences_ans; //Count number of times each character appears in each word
        std::map<char,int> n_occurences_in;
        for(int i=0;i<5;i++) //Count how many letters are already correct (necessary for multiple of the same letter)
        {
            n_occurences_ans[answer[i]]++; //Inciment letter in answer 
            if(input[i] == answer[i]) //Correctly guessed letter!
            {
                n_occurences_in[input[i]]++;
                good_input[i] = true;
                continue;
            }
        }
        for(int i=0;i<5;i++)
        {
            if(good_input[i]) //Write in green, continue
            {
                std::cout << GREEN << input[i] << RESET;
                continue;
            }
            bool draw_white = true; //Last check to draw letter nowhere in word as just plain
            for(int j=0;j<5;j++)
            {
                if(good_input[j]) continue;
                if((input[i] == answer[j]) && !good_input[i] && !good_input[j] && (n_occurences_in[input[i]] < n_occurences_ans[input[i]])) //Have at most n_occurences_ans copies of a letter 
                {
                    std::cout << YELLOW << input[i] << RESET;
                    n_occurences_in[input[i]]++;
                    draw_white = false;
                    break;
                }
            }
            if(draw_white) //Letter is nowhere in word
            {
                std::cout << RESET << input[i] << RESET;
            }
        }
        std::cout << std::endl;
    }
    return std::make_tuple(6,false,this->answer); //Return failed status with 6 guesses
}

/**
 * Setting the answer to the wordle. Used primarily in the initializing function, but also used in unit testing more forcefully.
 * @param ans The answer to the current game of wordle.
*/
void game::set_answer(const std::string &ans) //Set the answer to the game. Used in unit testing more forcefully as well
{
    this->answer = ans;
}