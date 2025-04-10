#include "Card.h"

Card::Card() : suit('S'), rank('A'), donotshow(false) {}

Card::Card(char s, char r, bool hide) : suit(s), rank(r), donotshow(hide) {}

std::string Card::toString() const {
    if (donotshow) {
        return "XX";
    }
    
    std::string cardStr;
    
    // Add suit symbol
    switch(suit) {
        case 'S': cardStr += "♠"; break;
        case 'H': cardStr += "♥"; break;
        case 'D': cardStr += "♦"; break;
        case 'C': cardStr += "♣"; break;
    }

    // Convert rank to proper representation
    if (rank == '0') cardStr += "10";
    else cardStr += rank;
    
    return cardStr;
}
