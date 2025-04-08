#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

// clubs (♣), diamonds (♦), hearts (♥) and spades (♠)
// diamonds and hearts are red, spades and clubs are black

bool GAME_START = false;

class Card {
    public:
        char suit;
        char rank;
        bool donotshow;

        // Default constructor
        Card() : suit('S'), rank('A'), donotshow(false) {}

        // Parameterized constructor
        Card(char s, char r, bool hide = false) : suit(s), rank(r), donotshow(hide) {}
    
        std::string toString() const {
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
};

struct Node{
    Card card;
    Node* prev;
    Node* next;

    Node (Card c) : card(c), prev(nullptr), next(nullptr) {} 
};

class CardDoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    CardDoublyLinkedList() : head(nullptr), tail(nullptr) {}

    //Add card at the end
    void append(Card card){
        Node* newNode = new Node(card);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next =  newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Append multiple cards from an array
    void append(Card* cards, int size) {
        for (int i = 0; i < size; i++) {
            append(cards[i]); // Reuse the single-card append function
        }
    }

    //starting from head, print the list forward
    void printForward() const {
        Node* current = head;
        while (current) {
            std::cout << current->card.toString() << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void printBackward() const {
        Node* current = tail;
        while (current){
            std::cout << current->card.toString() << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }

    // Destructor to free memory 
    ~CardDoublyLinkedList(){
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

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

void shuffleDeck(Card deck[], int deckSize = 52) {
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

void __init__Game__(CardDoublyLinkedList Tableau[], int tableauSize, Card deck[], int deckSize){
        // populate Tableau 
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



bool isValidMoveinFoundation(Card src, Card dest) {
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

bool isValidMoveinTableau(Card src, Card dest) {
    // src and dest must be opposite colors
    if (isRed(src.suit) == isRed(dest.suit)) return false;

    // dest must be one rank lower than src ( A < 1 )
    int srcValue = getRankValue(src.rank);
    int destValue = getRankValue(dest.rank);
    return srcValue + 1 == destValue;
}



int main(){
    char suits[4] = {'S','H','D','C'};
    char ranks[13] = {'A','2','3','4','5','6','7','8','9','0','J','Q','K'};

    // Create Deck
    Card deck[52];
    createDeck(deck, suits, ranks, 4, 13);
    // Shuffle Deck
    shuffleDeck(deck, 52);

    // Foundations 
    CardDoublyLinkedList Foundations[4];

    // Populate Tableau
    CardDoublyLinkedList Tableau[7];
    __init__Game__(Tableau, 7, deck, 52);

    // Game Started
    CardDoublyLinkedList move;


    return 0;
}
