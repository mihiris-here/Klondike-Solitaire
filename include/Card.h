#ifndef CARD_H
#define CARD_H

#include <string>

// Represents a playing card with suit, rank, and visibility
class Card {
public:
    char suit;
    char rank;
    bool donotshow;

    // Default constructor
    Card();
    
    // Parameterized constructor
    Card(char s, char r, bool hide = false);
    
    // Convert card to string representation
    std::string toString() const;
};

#endif // CARD_H