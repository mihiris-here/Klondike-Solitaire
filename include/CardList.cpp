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