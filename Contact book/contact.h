#ifndef CONTACT_H
#define CONTACT_H

#include <string>

/// @brief Contact contains specific contact information
struct Contact
{
    std::string full_name {};
    std::string phone_number {};
    std::string email {}; 
};

#endif // CONTACT_H