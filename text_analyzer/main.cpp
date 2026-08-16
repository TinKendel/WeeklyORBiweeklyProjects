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
    // Need to update this in case where there is only whitespace because for now it goes through which it shouldn't
    if (text.size() < 1)
    {
        std::cout << "There are no words in the file!\n";
        return;
    }

    // If we passed the first if than we need to have at least one word
    std::size_t total_number_of_words {0};
    bool currently_in_word {false};
    for (const auto& character : text)
    {
        if (std::isspace(character))
        {
            std::cout << "Whitespace!\n";
            if (currently_in_word)
                ++total_number_of_words;

            currently_in_word = false;
        }
        else
        {
            std::cout << "Char!\n";
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

// void theLargestWord(const std::string& text)
// {
//     std::size_t word_size {};
// }

int main()
{
    std::cout << "-------------------------------- TEXT ANALYZER --------------------------------\n";

    // I want to change this to not be hard coded but im leaving it as is for now
    std::string txt_file_path {"res/lorem_ipsum.txt"};
    // I need to open the file
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

    return 0;
}