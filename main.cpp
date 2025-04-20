#include <iostream>
#include "include/Card.h"
#include "include/CardList.h"
#include "include/GameUtils.h"

int main() {
    // char suits[4] = {'S', 'H', 'D', 'C'};
    // char ranks[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K'};

    // // Create Deck
    // Card deck[52];
    // createDeck(deck, suits, ranks, 4, 13);
    
    // // Shuffle Deck
    // shuffleDeck(deck, 52);

    // // Foundations 
    // CardDoublyLinkedList Foundations[4];

    // // Populate Tableau
    // CardDoublyLinkedList Tableau[7];
    // initGame(Tableau, 7, deck, 52);

    // // Game Started
    // // Print Tableau to verify
    // std::cout << "Tableau piles:\n";
    // for (int i = 0; i < 7; i++) {
    //     std::cout << "Pile " << i + 1 << ": ";
    //     Tableau[i].printForward();
    // }

    CardDoublyLinkedList mainList;
    CardDoublyLinkedList splitOut;

    // Add cards to mainList: 3♠ 4♣ 5♦ 6♠ 7♥
    mainList.append(Card('S', '3'));
    mainList.append(Card('C', '4'));
    mainList.append(Card('D', '5'));
    mainList.append(Card('S', '6'));
    mainList.append(Card('H', '7'));

    std::cout << "Before split:\n";
    std::cout << "Main List: ";
    mainList.printForward();
    std::cout << "Split Out: ";
    splitOut.printForward();

    // Perform split at 5♦
    mainList.splitList(splitOut, 'D', '5');

    std::cout << "\nAfter split:\n";
    std::cout << "Main List: ";
    mainList.printForward();
    std::cout << "Split Out: ";
    splitOut.printForward();

    return 0;
}