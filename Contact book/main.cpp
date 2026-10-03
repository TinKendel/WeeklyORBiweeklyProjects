#include "contact.h"

#include <fstream>
#include <vector>
#include <iostream>




void addContact(std::vector<Contact>& contact_book)
{
    // add all sorts of edge cases so that the user cant write something that doesnt make sense...
    /*
    for example
    while (true)
    std::cout write a name...
    std::cin....


    */
    const Contact contact { "Ivan Horvat", 69902349, "alex@mint.com" };
    std::cout << "Created contact -> "
              << "Full name: " << contact.full_name 
              << " | Phone number: " << contact.phone_number 
              << " | Email: " << contact.email << '\n';

    contact_book.push_back(contact);
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

int main()
{
    std::cout << "*************Contact Book*************\n";
    std::vector<Contact> contact_book {};

    addContact(contact_book);
    // deleteContact(contact_book);
    showContact(contact_book);


    // This needs more work, for now im just playing with the idea and how to use this
    // thinking on how to implement the saving and loading mechanic and if it even
    // makes sense...
    std::ofstream fs {"test.txt"};
    if (!fs.is_open())
    {
        std::cout << "Failed to open!\n";    
    }
    fs << "test 1" << std::endl;
    fs << "test 2" << std::endl;
    
    fs.close();

    // Here i want to make it so the user can decide what to do, inspect contacts, save them, add them, remove them etc
    // This will be made with Cin and switch while(true)

    return 0;
}