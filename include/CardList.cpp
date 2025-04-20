#include "CardList.h"
#include <iostream>

Node::Node(Card c) : card(c), prev(nullptr), next(nullptr) {}

CardDoublyLinkedList::CardDoublyLinkedList() : head(nullptr), tail(nullptr) {}

void CardDoublyLinkedList::append(Card card) {
    Node* newNode = new Node(card);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void CardDoublyLinkedList::append(Card* cards, int size) {
    for (int i = 0; i < size; i++) {
        append(cards[i]); // Reuse the single-card append function
    }
}

void CardDoublyLinkedList::appendList(const CardDoublyLinkedList& other) {
    Node* current = other.head;
    while (current) {
        append(current->card); // Reuse single-card append
        current = current->next;
    }
}

void CardDoublyLinkedList::splitList(CardDoublyLinkedList& other, char suit, char rank) {
    Node* current = head;

    while (current) {
        if (current->card.suit == suit && current->card.rank == rank and current->card.donotshow == false) {
            // Found the match — start the split here

            // Detach the previous part of the list
            if (current->prev) {
                current->prev->next = nullptr;
                tail = current->prev;
                current->prev = nullptr;
            } else {
                // Match is at the head — whole list is moving
                head = nullptr;
                tail = nullptr;
            }

            // Transfer nodes starting from current to `other`
            Node* moveNode = current;
            while (moveNode) {
                other.append(moveNode->card); // Copy card to other list
                Node* temp = moveNode;
                moveNode = moveNode->next;
                delete temp; // Free the node from original list
            }

            break; // Done splitting
        }

        current = current->next;
    }
}

void CardDoublyLinkedList::printForward() const {
    Node* current = head;
    while (current) {
        std::cout << current->card.toString() << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void CardDoublyLinkedList::printBackward() const {
    Node* current = tail;
    while (current) {
        std::cout << current->card.toString() << " ";
        current = current->prev;
    }
    std::cout << std::endl;
}

CardDoublyLinkedList::~CardDoublyLinkedList() {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}