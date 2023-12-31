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

    if (card != NULL)
    {
        card->id = rand() % 10001;
        card->value = rand() % 11;
        card->next_card = NULL;
    }

    return card;
}

// Create a new deck of cards
Deck* createDeck()
{
    Deck* deck = NULL;
    deck = (Deck*)malloc(sizeof(Deck));

    if (deck != NULL)
    {
        deck->size = 0;
        deck->cards = NULL;
    }

    return deck;
}

// Create a new hand
Hand* createHand()
{
    Hand* hand = NULL;
    hand = (Hand*)malloc(sizeof(Hand));

    if (hand != NULL)
    {
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

    if (deck->size == 0)
    {
        deck->cards = card;
        deck->size++;
    }
    else
    {
        Card* current = deck->cards;

        while (current->next_card != NULL)
        {
            current = current->next_card;
        }

        current->next_card = card;
        deck->size++;
    }

    return 1;
}

// Check if a card with the given ID exists in the deck
int cardExists(int id, Deck* deck)
{
    if (deck == NULL)
        return 0;

    Card* current = deck->cards;

    while (current != NULL)
    {
        if (current->id == id)
            return 1;

        current = current->next_card;
    }

    return 0;
}

// Check if a card exists in the deck (based on memory address)
int cardExistsC(Card* card, Deck* deck)
{
    if (card == NULL || deck == NULL)
        return 0;

    Card* current = deck->cards;

    while (current != NULL)
    {
        if (current == card)
            return 1;

        current = current->next_card;
    }

    return 0;
}

// Shuffle the deck of cards using Fisher-Yates algorithm
void shuffle(Deck* deck)
{
    if (deck == NULL)
        return;

    int i = 0;
    int n = deck->size;
    Card* current = deck->cards;

    for (i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        Card* temp_i = current;

        int k;
        for (k = 0; k < i; k++)
        {
            temp_i = temp_i->next_card;
        }

        Card* temp_j = current;
        for (k = 0; k < j; k++)
        {
            temp_j = temp_j->next_card;
        }

        // Swap values
        int temp_id = temp_i->id;
        int temp_value = temp_i->value;
        temp_i->id = temp_j->id;
        temp_i->value = temp_j->value;
        temp_j->id = temp_id;
        temp_j->value = temp_value;
    }
}

// Fill a hand with cards from the deck
int fillHand(int size, Hand* hand, Deck* deck)
{
    if (hand == NULL || deck == NULL || size <= 0)
        return 0;

    int i;
    for (i = 0; i < size; i++)
    {
        Card* current = deck->cards;
        Card* previous = NULL;

        while (current != NULL)
        {
            if (!cardExistsC(current, hand))
            {
                Card* temp_card = createCard();
                temp_card->id = current->id;
                temp_card->value = current->value;
                temp_card->next_card = NULL;

                if (previous == NULL)
                {
                    deck->cards = current->next_card;
                }
                else
                {
                    previous->next_card = current->next_card;
                }

                addCard(temp_card, hand);
                break;
            }

            previous = current;
            current = current->next_card;
        }
    }

    return 1;
}

// Show cards in a hand
void showHand(Hand* hand)
{
    if (hand == NULL)
        return;

    printf("Hand: ");
    Card* current = hand->cards;

    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next_card;
    }

    printf("\n");
}

// Play a card from the hand and remove it from the hand and deck
int playCard(int id, Hand* hand, Deck* deck)
{
    if (hand == NULL || deck == NULL)
        return 0;

    Card* current = hand->cards;
    Card* previous = NULL;

    while (current != NULL)
    {
        if (current->id == id)
        {
            if (previous == NULL)
            {
                hand->cards = current->next_card;
            }
            else
            {
                previous->next_card = current->next_card;
            }

            current->next_card = NULL;
            addCard(current, deck);
            hand->size--;
            return 1;
        }

        previous = current;
        current = current->next_card;
    }

    return 0;
}