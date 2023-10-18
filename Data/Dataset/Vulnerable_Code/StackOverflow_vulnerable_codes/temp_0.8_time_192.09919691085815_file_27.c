#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct CARD Card;

struct CARD {
    int value;
    int id;
    Card *next_card;
};

typedef struct Deck {
    int size;
    Card *cards;
} Deck;

typedef struct Hand {
    int size;
    Card *cards;
} Hand;


Card* createCard();
Deck* createDeck();
Hand* createHand();
int addCard(Card* card, Deck* deck);
int cardExists(int id, Deck* deck);
int cardExistsC(Card* card, Deck* deck);
void shuffle(Deck* deck);
int fillHand(int size, Hand* hand, Deck* deck);
void showHand(Hand* hand);
int playCard(int id, Hand* hand, Deck* deck);


int main(int argc, char** argv)
{
    // Initialise seed for random number generator
    srand(time(NULL));
    int playable = 1;

    Deck* deck = createDeck();
    Hand* player1 = createHand();
    Hand* player2 = createHand();

    if (deck == NULL || player1 == NULL || player2 == NULL)
    {
        if (deck != NULL)
            free(deck);
        if (player1 != NULL)
            free(player1);
        if (player2 != NULL)
            free(player2);
        playable = 0;
    }

    if (!playable)
    {
        return -1;
    }
    else
    {
        int i = 0;
        for (i = 0; i < 52; i++)
        {
            Card* temp = createCard();
            addCard(temp, deck);
        }

        shuffle(deck);

        fillHand(7, player1, deck);
        fillHand(7, player2, deck);

        for (i = 0; i < 7; i++)
        {
            showHand(player1);
            showHand(player2);

            playCard(-1, player1, deck);
            playCard(-1, player2, deck);
        }

        free(deck);
        free(player1);
        free(player2);
    }

    return 0;
}


// Create a new card generating a random ID (0-10,000) and value from 0-10
Card* createCard()
{
    Card* card = NULL;
    card = (Card*)malloc(sizeof(Card));
    if (card != NULL) {
        card->value = rand() % 11;
        card->id = rand() % 10001;
        card->next_card = NULL;
    }
    return card;
}

// Create a new deck with size 0 and no cards
Deck* createDeck() {
    Deck* deck = (Deck*)malloc(sizeof(Deck));
    if (deck != NULL) {
        deck->size = 0;
        deck->cards = NULL;
    }
    return deck;
}

// Create a new hand with size 0 and no cards
Hand* createHand()
{
    Hand* hand = (Hand*)malloc(sizeof(Hand));
    if (hand != NULL) {
        hand->size = 0;
        hand->cards = NULL;
    }
    return hand;
}

// Add a card to the deck
int addCard(Card* card, Deck* deck)
{
    if (card == NULL || deck == NULL)
        return 0;
    
    if (deck->cards == NULL) {
        deck->cards = card;
    } else {
        Card* temp = deck->cards;
        while (temp->next_card != NULL) {
            temp = temp->next_card;
        }
        temp->next_card = card;
    }
    
    deck->size++;
    return 1;
}

// Check if a card with the given id exists in the deck
int cardExists(int id, Deck* deck)
{
    if (deck == NULL)
        return 0;
    
    Card* temp = deck->cards;
    while (temp != NULL) {
        if (temp->id == id)
            return 1;
        temp = temp->next_card;
    }
    
    return 0;
}

// Check if a card exists in the deck (by comparing the memory addresses)
int cardExistsC(Card* card, Deck* deck)
{
    if (card == NULL || deck == NULL)
        return 0;
    
    Card* temp = deck->cards;
    while (temp != NULL) {
        if (temp == card)
            return 1;
        temp = temp->next_card;
    }
    
    return 0;
}

// Shuffle the cards in the deck
void shuffle(Deck* deck)
{
    if (deck == NULL)
        return;
    
    int i, j;
    int size = deck->size;
    Card** cards = (Card**)malloc(size * sizeof(Card*));
    
    Card* temp = deck->cards;
    for (i = 0; i < size; i++) {
        cards[i] = temp;
        temp = temp->next_card;
    }
    
    for (i = size - 1; i > 0; i--) {
        j = rand() % (i + 1);
        Card* temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
    
    deck->cards = cards[0];
    temp = deck->cards;
    for (i = 1; i < size; i++) {
        temp->next_card = cards[i];
        temp = temp->next_card;
    }
    temp->next_card = NULL;
    
    free(cards);
}

// Fill the hand with cards from the deck
int fillHand(int size, Hand* hand, Deck* deck)
{
    if (hand == NULL || deck == NULL)
        return 0;
    
    int i;
    for (i = 0; i < size; i++) {
        Card* temp = deck->cards;
        if (temp == NULL)
            return 0;
        
        deck->cards = temp->next_card;
        temp->next_card = hand->cards;
        hand->cards = temp;
        
        hand->size++;
        deck->size--;
    }
    
    return 1;
}

// Display the cards in the hand
void showHand(Hand* hand)
{
    if (hand == NULL)
        return;
    
    Card* temp = hand->cards;
    while (temp != NULL) {
        printf("Card ID: %d, Value: %d\n", temp->id, temp->value);
        temp = temp->next_card;
    }
}

// Play a card from the hand by id
int playCard(int id, Hand* hand, Deck* deck)
{
    if (hand == NULL || deck == NULL || hand->size == 0)
        return 0;
    
    Card* prev = NULL;
    Card* curr = hand->cards;
    
    while (curr != NULL) {
        if (curr->id == id) {
            if (prev == NULL) {
                hand->cards = curr->next_card;
            } else {
                prev->next_card = curr->next_card;
            }
            
            curr->next_card = deck->cards;
            deck->cards = curr;
            
            hand->size--;
            deck->size++;
            
            return 1;
        }
        
        prev = curr;
        curr = curr->next_card;
    }
    
    return 0;
}