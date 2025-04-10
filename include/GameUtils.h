#ifndef GAME_UTILS_H
#define GAME_UTILS_H

#include "Card.h"
#include "CardList.h"

// Global game state
extern bool GAME_START;

// Create a standard deck of cards
void createDeck(Card deck[], char suits[], char ranks[], int numSuits, int numRanks);

// Shuffle the deck of cards
void shuffleDeck(Card deck[], int deckSize = 52);

// Print an array of cards
void printCards(Card stack[], int size);

// Initialize the game by distributing cards to tableau piles
void initGame(CardDoublyLinkedList Tableau[], int tableauSize, Card deck[], int deckSize);

// Get numerical value of a card rank
int getRankValue(char rank);

// Check if a suit is red
bool isRed(char suit);

// Check if a move to the foundation pile is valid
bool isValidMoveInFoundation(Card src, Card dest);

// Check if a move within the tableau is valid
bool isValidMoveInTableau(Card src, Card dest);

#endif // GAME_UTILS_H