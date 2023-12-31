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


// Create a new card generating a random ID (0-10,000)and value from 0-10
Card* createCard()
{
    Card* card = NULL;
    card = (Card*)malloc(sizeof(Card));
#ifdef __cplusplus
    card->id = rand(0,100000);
#else
    card->id = rand(0,100000);
#endif
    card->value = rand(0,10);
    return card;
}

// Create a new deck of cards
Deck* createDeck()
{
    Deck* deck = NULL;
    deck = (Deck*)malloc(sizeof(Deck));
    deck->size = 52;
    deck->cards = (Card*)malloc(sizeof(Card));
    return deck;
}

// Create a new hand of cards
Hand* createHand()
{
    Hand* hand = NULL;
    hand = (Hand*)malloc(sizeof(Hand));
    hand->size = 7;
    hand->cards = (Card*)malloc(sizeof(Card));
    return hand;
}

// Add a card to a deck
int addCard(Card* card, Deck* deck)
{
    int i;
    for (i = 0; i < deck->size; i++)
    {
        if (card->value > deck->cards[i->value].value)
        {
            card->next_card = deck->cards[i];
            deck->cards[i->value] = card;
            return 1;
        }
    }
    card->next_card = deck->cards[deck->size];
    deck->cards[deck->size] = card;
    return 1;
}

// Check if a card exists in a deck
int cardExists(int id, Deck* deck)
{
    int i;
    for (i = 0; i < deck->size; i++)
    {
        if (deck->cards[i->value].id == id)
        {
            return 1;
        }
    }
    return 0;
}

// Check if a card exists in a hand
int cardExistsC(Card* card, Deck* deck)
{
    int i;
    for (i = 0; i < deck->size; i++)
    {
        if (deck->cards[i->value].id == card->id)
        {
            return 1;
        }
    }
    return 0;
}

// Shuffle a deck
void shuffle(Deck* deck)
{
    int i;
    for (i = 0; i < deck->size; i++)
    {
        int j;
        for (j = i; j < deck->size; j++)
        {
            if (deck->cards[i->value].value > deck->cards[j->value].value)
            {
                int temp = deck->cards[i->value];
                deck->cards[i->value] = deck->cards[j->value];
                deck->cards[j->value] = temp;
            }
        }
    }
}

// Fill a hand with cards
void fillHand(int size, Hand* hand, Deck* deck)
{
    int i;
    for (i = 0; i < size; i++)
    {
        hand->cards[i] = deck->cards[i];
    }
}

// Show a hand
void showHand(Hand* hand)
{
    int i;
    for (i = 0; i < hand->size; i++)
    {
        printf("%d ", hand->cards[i->value].id);
    }
    printf("\n");
}

// Play a card
int playCard(int id, Hand* hand, Deck* deck)
{
    int i;
    for (i = 0; i < hand->size; i++)
    {
        if (hand->cards[i->value].id == id)
        {
            if (cardExists(id, deck))
            {
                return -1;
            }
            else
            {
                hand->cards[i->value].id = id;
                return 1;
            }
        }
    }
    return -1;
}

int main(int argc, char** argv)
{
    int i;
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
    }}