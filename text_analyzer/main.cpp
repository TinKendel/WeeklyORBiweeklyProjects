#include <fstream>
#include <cstddef> // for std::size_t
#include <cctype>
#include <iostream>

void numberOfCharacters(const std::string& text)
{
    std::cout << "Total number of characters (excluding whitespaces): " << text.size() << '\n';
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

void theLargestWord(const std::string& text)
{
    std::size_t current_word_size           {};
    std::size_t size_of_the_largest_word    {};
    std::size_t starting_index_for_the_largest_word  {};
    std::size_t string_index                {};

    for (const auto& character : text)
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

    std::string longest_word {text.substr(starting_index_for_the_largest_word, size_of_the_largest_word)};

    std::cout << "The size of the longest word is: " << size_of_the_largest_word << '\n';
    std::cout << "And the word is: " << longest_word << '\n';
}

void countSpecificCharacter(const std::string& text, const char specific_character)
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

int main()
{
    std::cout << "-------------------------------- TEXT ANALYZER --------------------------------\n";

    // I want to change this to not be hard coded but im leaving it as is for now
    std::string txt_file_path {"res/lorem_ipsum.txt"};

    // Ifstream is for reading files 
    // Ofstream is for writing in files
    std::ifstream ifstream;
    ifstream.open(txt_file_path);

    // Read the file line by line and save it to a string
    std::string line {};
    std::string text {};

    while (std::getline(ifstream, line))
    {
        line.push_back('\n');
        text += line;
    }

    numberOfCharacters(text);
    numberOfWhitespaces(text);
    numberOfWords(text);
    theLargestWord(text);

    char users_specific_character {};
    std::cout << "Choose a character: ";
    std::cin >> users_specific_character;
    countSpecificCharacter(text, users_specific_character);


    return 0;
}