#ifndef CARD_LIST_H
#define CARD_LIST_H

#include "Card.h"

// Node structure for doubly linked list
struct Node {
    Card card;
    Node* prev;
    Node* next;

    Node(Card c);
};

// Doubly linked list for managing cards
class CardDoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    CardDoublyLinkedList();
    ~CardDoublyLinkedList();
    
    // Add card at the end
    void append(Card card);
    
    // Append multiple cards from an array
    void append(Card* cards, int size);
    
    // Print list from front to back
    void printForward() const;
    
    // Print list from back to front
    void printBackward() const;
};

#endif // CARD_LIST_H