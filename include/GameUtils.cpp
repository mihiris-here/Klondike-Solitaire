#include "GameUtils.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

bool GAME_START = false;

void createDeck(Card deck[], char suits[], char ranks[], int numSuits, int numRanks) {
    int cardIndex = 0;
    for (int s = 0; s < numSuits; s++) {
        for (int r = 0; r < numRanks; r++) {
            deck[cardIndex].suit = suits[s];
            deck[cardIndex].rank = ranks[r];
            deck[cardIndex].donotshow = false;
            cardIndex++;
        }
    }
}

void shuffleDeck(Card deck[], int deckSize) {
    // Seed the random number generator
    srand(time(0));
    
    for (int i = 0; i < deckSize; i++) {
        int j = rand() % deckSize;
        // Swap cards at positions i and j
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void printCards(Card stack[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << stack[i].toString() << " ";
        // Print newline every 13 cards for better readability
        if ((i + 1) % 13 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

void initGame(CardDoublyLinkedList Tableau[], int tableauSize, Card deck[], int deckSize) {
    // Populate Tableau 
    int deckIndex = 0; // To track which card is being placed

    for (int i = 0; i < tableauSize; i++) { // Loop over 7 piles
        for (int j = 0; j < i + 1; j++) { // Place `i+1` cards in each pile
            bool isLastCard = (j == i); // Last card should be visible
            Tableau[i].append(Card(deck[deckIndex].suit, deck[deckIndex].rank, !isLastCard)); 
            deckIndex++;
        }
    }

    GAME_START = true;
}

int getRankValue(char rank) {
    if (rank >= '2' && rank <= '9') return rank - '0';
    if (rank == '0') return 10; // Represents 10
    if (rank == 'A') return 1;
    if (rank == 'J') return 11;
    if (rank == 'Q') return 12;
    if (rank == 'K') return 13;
    return -1; // Invalid rank
}

bool isRed(char suit) {
    return suit == 'H' || suit == 'D';
}

bool isValidMoveInFoundation(Card src, Card dest) {
    // Empty destination case: must be Ace
    if (dest.rank == '\0') { // Assuming '\0' means empty slot
        return src.rank == 'A';
    }

    // Same suit required
    if (src.suit != dest.suit) return false;

    // Must be next in sequence
    int srcValue = getRankValue(src.rank);
    int destValue = getRankValue(dest.rank);
    return srcValue == destValue + 1;
}

bool isValidMoveInTableau(Card src, Card dest) {
    // src and dest must be opposite colors
    if (isRed(src.suit) == isRed(dest.suit)) return false;

    // dest must be one rank lower than src ( A < 1 )
    int srcValue = getRankValue(src.rank);
    int destValue = getRankValue(dest.rank);
    return srcValue + 1 == destValue;
}
