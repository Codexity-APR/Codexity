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
            if(temp != NULL) {
                addCard(temp, deck);
            }
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


// Create a new card generating a random ID (0-10,000)and value from 0-10
Card* createCard()
{
    Card* card = (Card*)malloc(sizeof(Card));
    if(card != NULL) {
        card->id = rand() % 10000;
        card->value = rand() % 10;
        card->next_card = NULL;
        return card;
    }
    else {
        return NULL;
    }
}

// Create a new deck with a size of 52
Deck* createDeck()
{
    Deck* deck = (Deck*)malloc(sizeof(Deck));
    if(deck != NULL) {
        deck->size = 52;
        deck->cards = NULL;
        return deck;
    }
    else {
        return NULL;
    }
}

// Create a new hand with a size of 0
Hand* createHand()
{
    Hand* hand = (Hand*)malloc(sizeof(Hand));
    if(hand != NULL) {
        hand->size = 0;
        hand->cards = NULL;
        return hand;
    }
    else {
        return NULL;
    }
}

// Add a card to the deck
int addCard(Card* card, Deck* deck)
{
    if (card == NULL || deck == NULL)
    {
        return -1;
    }
    else
    {
        Card* temp = deck->cards;
        Card* prev = NULL;
        while (temp!= NULL)
        {
            prev = temp;
            temp = temp->next_card;
        }
        if (temp == NULL)
        {
            deck->cards = card;
        }
        else
        {
            prev->next_card = card;
        }
        return 0;
    }
}

// Check if a card with the given ID exists in the deck
int cardExists(int id, Deck* deck)
{
    if (deck == NULL)
    {
        return -1;
    }