#include <fstream>
#include <cstddef> // for std::size_t
#include <cctype>
#include <string_view>  // for string_view
#include <cstring> // std::strerror
#include <limits> // included for numeric_limits
#include <iomanip> // included for std::setprecision 
#include <iostream>

void numberOfCharacters(const std::string& text)
{
    std::cout << "Total number of characters (including whitespaces): " << text.size() << '\n';
}

void numberOfWords(const std::string& text)
{
    // In case the text has no words
    if (text.size() < 1)
    {
        std::cout << "There are no words in the file!\n";
        return;
    }

    std::size_t total_number_of_words {0};
    bool currently_in_word {false};
    for (const auto& character : text)
    {
        if (std::isspace(character))
        {
            // std::cout << "Whitespace!\n";
            if (currently_in_word)
                ++total_number_of_words;

            currently_in_word = false;
        }
        else
        {
            // std::cout << "Char!\n";
            currently_in_word = true;
        }
    }

    std::cout << "The total number of words: " << total_number_of_words << '\n';
}

void numberOfWhitespaces(const std::string& text)
{
    std::size_t total_number_of_whitespace {};
    for (const auto& character : text)
    {
        if (std::isspace(character))
            ++total_number_of_whitespace;
    }

    std::cout << "Total number of whitespaces: " << total_number_of_whitespace << '\n';
}

void theLargestWord(std::string_view sv_text)
{
    std::size_t current_word_size           {};
    std::size_t size_of_the_largest_word    {};
    std::size_t starting_index_for_the_largest_word  {};
    std::size_t string_index                {};

    for (const auto& character : sv_text)
    {
        if (character == ',' || isspace(character))
        {
            if (current_word_size != 0)
            {    
                if (size_of_the_largest_word < current_word_size)
                {    
                    size_of_the_largest_word = current_word_size;
                    starting_index_for_the_largest_word = string_index - current_word_size;
                }
            }
            
            current_word_size = 0;
        }
        else
        {
            ++current_word_size;
        }
        
        ++string_index;
    }

    std::string_view longest_word {sv_text.substr(starting_index_for_the_largest_word, size_of_the_largest_word)};

    std::cout << "The size of the longest word is: " << size_of_the_largest_word << '\n';
    std::cout << "And the word is: " << longest_word << '\n';
}

void countSpecificCharacter(std::string_view text, const char specific_character)
{
    std::size_t specific_character_count {};

    for (const auto& character : text)
    {
        if (character == specific_character)
        {
            ++specific_character_count;
        }
    }

    std::cout << "You chose " << specific_character << " and that character occurred " << specific_character_count << " times\n";
}

void findTheShortestWord(const std::string_view text)
{
    std::size_t current_length_of_word      {};
    std::size_t size_of_the_shortest_word   {std::numeric_limits<std::size_t>::max()};
    std::size_t index_of_the_shortest_word  {};

    bool end_of_word                        {false};
    std::size_t current_index_in_text       {};

    for (const auto& character : text)
    {
        if (character == ',' || isspace(character))
        {
            if (!end_of_word)
            {
                if (current_length_of_word < size_of_the_shortest_word)
                {
                    size_of_the_shortest_word = current_length_of_word;
                    index_of_the_shortest_word = current_index_in_text - current_length_of_word;
                }

                current_length_of_word = 0;
                end_of_word = true;
            }
        }
        else
        {
            end_of_word = false;
            ++current_length_of_word;
        }
        
        ++current_index_in_text;
    }

    std::cout << "The size of the shortest word is: " << size_of_the_shortest_word << '\n';
    std::cout << "The shortest word is: " << text.substr(index_of_the_shortest_word, size_of_the_shortest_word) << '\n';
}

void averageWordLength(std::string_view text)
{
    size_t total_length_of_words {};
    size_t total_number_of_words {};
    bool end_of_word             {false};

    for (const auto& character : text)
    {
        if (character == ',' || isspace(character))
        {
            if(!end_of_word)
            {
                ++total_number_of_words;
            }

            end_of_word = true;
        }
        else
        {
            end_of_word = false;
            ++total_length_of_words;
        }
    }

    if (total_number_of_words == 0)
    {
        std::cout << "The average word length is: 0\n";
        return;
    }

    double result {static_cast<double>(total_length_of_words) / static_cast<double>(total_number_of_words)};
    std::cout << "The average word length is: " << std::setprecision(3) << result << '\n';
}

void findTheSpecificWord(std::string_view text, std::string_view users_word)
{
    std::size_t index_of_found_word {text.find(users_word)};
    
    if (index_of_found_word != std::string_view::npos)
    {
        std::cout << "The word that the user requested exists! And it starts at index: " << index_of_found_word << '\n';
    }
    else
    {
        std::cout << "The word that the user requested doesn't exist!\n";
    }
}

// Returns true if std::cin has unextracted input on the current line
bool hasUnextractedInput()
{
    return !std::cin.eof() && std::cin.peek() != '\n';
}

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void askUserForInput(std::string_view text)
{
    char users_specific_character {};
    while (true)
    {
        std::cout << "Choose a character: ";
        std::cin >> users_specific_character;
        
        // If the user has written more than one character we retry again
        if (hasUnextractedInput())
        {
            ignoreLine();
            continue;
        }
        break;
    }
    
    countSpecificCharacter(text, users_specific_character);


    std::string users_specific_word {};
    while (true)
    {

        std::cout << "Write a word you are looking for: ";
        std::cin >> users_specific_word;

        if (hasUnextractedInput())
        {
            ignoreLine();
            continue;
        }
        break;
    }

    findTheSpecificWord(text, users_specific_word);
}

int main()
{
    std::cout << "-------------------------------- TEXT ANALYZER --------------------------------\n";

    // I want to change this to not be hard coded but im leaving it as is for now
    std::string txt_file_path {"res/lorem_ipsum.txt"};

    // Ifstream is for reading files 
    // Ofstream is for writing in files
    std::ifstream ifstream;
    ifstream.open(txt_file_path);

    // Check if there was an error when opening the txt file
    if (ifstream.fail()) // More common would be to use ! like this -> if (!ifstream)...
    {
        std::cout << "An error has occurred: " << std::strerror(errno);
        return 1;
    }

    // Read the file line by line and save it to a string
    std::string line {};
    std::string text {};

    while (std::getline(ifstream, line))
    {
        line.push_back('\n'); // I have noticed that this makes my functions work "unexpectedly" since \n adds a character to each line
        text += line;
    }

    // Check if we have an empty txt file
    if (text.empty())
    {
        std::cout << "The txt file is empty\n";
        return 1;
    }

    numberOfCharacters(text);
    numberOfWhitespaces(text);
    numberOfWords(text);
    theLargestWord(text);
    findTheShortestWord(text);
    averageWordLength(text);

    std::cout << "++++++++++++++++++ User input ++++++++++++++++++\n";

    askUserForInput(text);

    return 0;
}