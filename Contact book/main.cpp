#include "contact.h"

#include <limits>
#include <string_view>
#include <string>
#include <fstream>
#include <vector>
#include <iostream>

//-------------------------------------- Input check

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Returns true if extraction failed, false otherwise
bool clearFailedExtraction()
{
    // Check for failed extraction 
    if (!std::cin)  // If the previous extraction failed
    {
        if (std::cin.eof()) // If the stream was closed
        {
            std::exit(0);
        }

        std::cin.clear(); // Put us back in "normal" operation mode
        ignoreLine();

        return true;
    }

    return false;
}


//--------------------------------------

// Namespace with functions that are only used for adding new contacts
namespace AddContactInfo
{
    std::string fullName() // [TIN] Can I make this faster and not use a string
    {
        /*
            Since naming contacts is an user option which can be used in more different ways 
            then we can plan for I think I can leave this as is without adding bunch of
            tests for example the name having a number in it or something like that
        */
        /*
            [TIN] Do I need this while true if I am saying that the user has freedom
            to name the contact how ever they want? I could add something that would
            check if std::cin not in normal mode ?! 
        */
        while (true) 
        {
            std::string full_name {};
            std::cout << "Enter the full name of the contact\n";
            std::getline(std::cin >> std::ws, full_name);

            std::cout << "The full name of the contact is " << full_name << '\n';
            return full_name;
        }
    }

    int phoneNumber()
    {
        while (true)
        {
            int phone_number {};

            std::cout << "Enter the phone number of the contact\n";
            std::cin >> phone_number; 

            if (clearFailedExtraction())
            {
                std::cout << "Input invalid. Please try again.\n";
                continue;
            }

            std::cout << "The entered phone number is: " << phone_number << '\n';
            return phone_number;
        }
    }
}

void addContact(std::vector<Contact>& contact_book)
{
    // const Contact contact { "Ivan Horvat", 69902349, "alex@mint.com" };
    // std::cout << "Created contact -> "
    //           << "Full name: " << contact.full_name 
    //           << " | Phone number: " << contact.phone_number 
    //           << " | Email: " << contact.email << '\n';

    // contact_book.push_back(contact);

    std::cout << "Adding contact...\n";
    
    while (true)
    {
        std::string full_name   { AddContactInfo::fullName() };
        int phone_number        { AddContactInfo::phoneNumber() };

        break; // remove later
    }

    std::cout << "DONE\n";
}

void deleteContact(std::vector<Contact>& contact_book)
{
    // add all sorts of edge cases so that the user cant write something that doesnt make sense...
    /*
    for example
    while (true)
    std::cout write a name...
    std::cin....
    */

    // For now just a simple delete will work
    // Not the nicest output but will work on it later
    const Contact contact { contact_book.front() };
    std::cout << "Full name: " << contact.full_name 
            << " | Phone number: " << contact.phone_number 
            << " | Email: " << contact.email
            << " HAS BEEN DELETED!\n";
    contact_book.pop_back();
}

// potentially add a template for the key
void findContact(const std::vector<Contact>& contact_book/* We could place here a parameter that will be used as a key*/)
{
    /*
        this will be a bigger maybe even a function that will call other functions
        because it depends how we want to find the contact, we could look it up
        through name, phone number...

        we also need to take care about wrong inputs etc
    */
   std::cout << "Function is empty!\n";
}

void showContact(const std::vector<Contact>& contact_book)
{
    // For now im making it simple, i will just print out the first contact
    const Contact contact { contact_book.front() };
    std::cout << "Full name: " << contact.full_name 
              << " | Phone number: " << contact.phone_number 
              << " | Email: " << contact.email << '\n';
}

int getInstruction()
{
    while (true)
    {
        std::cout << "Pick a number between 0 and 7 to proceed: ";

        int number_to_proceed {};
        std::cin >> number_to_proceed;

        switch (number_to_proceed)
        {
        case 0: //fallthrough
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            return number_to_proceed;
        default:
            std::cout << "Pick a number in the range to proceed. Please try again...\n";
        };
    }
}

void printManual()
{
    std::cout << "######################################\n";
    std::cout << "0) -> Print Manual\n";
    std::cout << "1) -> Add Contact\n";
    std::cout << "2) -> Find Contact\n";
    std::cout << "3) -> Delete Contact\n";
    std::cout << "4) -> Show(list) contacts\n";
    std::cout << "5) -> Save contacts\n";
    std::cout << "6) -> Load contacts\n";
    std::cout << "7) -> Quit\n";
    std::cout << "######################################\n";
}

int main()
{
    std::cout << "*************Contact Book*************\n";
    std::vector<Contact> contact_book {};
    bool quit {false};

    std::cout << "What do you want to do?\n";
    std::cout << "Input 0 for a Manual\n";
        
    while(true)
    {
        if (quit) break;
        int command { getInstruction() };

        switch (command)
        {
        case 0:
            printManual();
            continue;
        case 1:
        
        case 7:
            std::cout << "Quit\n"; // An option to save before quit would be cool
            quit = true;
            break;
        
        default:
            std::cout << "Something has gone horribly wrong!\n";
        };          
    }

    addContact(contact_book);
    // deleteContact(contact_book);
    // showContact(contact_book);


    //---------------------------------------------------------------------------------

    // The idea will be to save contacts into a csv format and we can load a csv too 
    // we load it into a vector

    // This needs more work, for now im just playing with the idea and how to use this
    // thinking on how to implement the saving and loading mechanic and if it even
    // makes sense...
    // std::ofstream fs {"test.txt"};
    // if (!fs.is_open())
    // {
    //     std::cout << "Failed to open!\n";    
    // }
    // fs << "test 1" << std::endl;
    // fs << "test 2" << std::endl;
    
    // fs.close();

    // Here i want to make it so the user can decide what to do, inspect contacts, save them, add them, remove them etc
    // This will be made with Cin and switch while(true)

    return 0;
}