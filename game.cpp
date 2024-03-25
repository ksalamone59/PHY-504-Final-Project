//This file handles the actual "wordle" game itself
#include "wordle.h"

void game::get_dictionary() //Open dictionary to read in from
{
    dictionary.open("dictionary.txt");
}

void game::initialize() //Get the current wordle guess
{
    std::string rand_word;
    srand(time(NULL)); //Initialize random number generator
    int rand_number{rand() % MAX_NUMBER}; //Random word from the list of words (recall: 0->1, 1->2, etc. See README)
    int curr_word{0}; //To loop through dictionary file 
    get_dictionary(); //Get the dictionary
    while(dictionary.good()) //Continue looping through dictionary until we get line we want
    {
        getline(dictionary,rand_word);
        if(curr_word == rand_number) break;
        curr_word++;
    }
    set_answer(rand_word); //Set the answer to the game
    close_dictionary(); //Close the dictionary
}

void game::close_dictionary() //Close dictionary
{
    dictionary.close();
}

results game::play_game()
{
    u_int n_guess = 0; //How many guesses it took
    std::string out_names[6] = {"first","second","third","fourth","fifth","sixth and final"}; //Making I/O easier
    std::cout << RESET << std::endl; //Easiet way to force background text styles to be the same regardless of editor/terminal themes
    while(n_guess < MAX_N_GUESS) //Only 6 guesses
    {
        std::string input;
        std::cout << "Please enter your " << out_names[n_guess] << " guess: ";
        std::cin >> input;
        while(input.length() != 5) //Testing to ensure we get 5 letter words only
        {
            std::cout << "Oops! You need a five letter word to play the game. Please re enter a 5 letter word: ";
            std::cin >> input;
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
                n_occurences_in[input[i]]++;
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

void game::set_answer(const std::string ans) //Set the answer to the game. Used in unit testing more forcefully as well
{
    this->answer = ans;
}