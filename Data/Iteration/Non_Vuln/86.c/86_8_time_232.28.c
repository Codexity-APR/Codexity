#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct CARD Card;

struct CARD {
    int value;
    int id;
    Card* next_card;
};

typedef struct Deck {
    int size;
    Card* cards;
} Deck;

typedef struct Hand {
    int size;
    Card* cards;
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

    if (card != NULL)
    {
        card->value = rand() % 11;
        card->id = rand() % 10001;
        card->next_card = NULL;
    }

    return card;
}

// Create a new deck
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
        card->next_card = NULL;
    }
    else
    {
        Card* temp = deck->cards;
        while (temp->next_card != NULL)
            temp = temp->next_card;

        temp->next_card = card;
        card->next_card = NULL;
    }

    deck->size++;
    return 1;
}

// Check if a card with a specific ID exists in the deck
int cardExists(int id, Deck* deck)
{
    if (deck == NULL)
        return 0;

    Card* temp = deck->cards;
    while (temp != NULL)
    {
        if (temp->id == id)
            return 1;
        temp = temp->next_card;
    }

    return 0;
}

// Check if a specific card exists in the deck
int cardExistsC(Card* card, Deck* deck)
{
    if (card == NULL || deck == NULL)
        return 0;

    Card* temp = deck->cards;
    while (temp != NULL)
    {
        if (temp == card)
            return 1;
        temp = temp->next_card;
    }

    return 0;
}

// Shuffle the cards in the deck randomly
void shuffle(Deck* deck)
{
    if (deck == NULL)
        return;

    int i = 0;
    for (i = deck->size - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        Card* temp1 = deck->cards;
        Card* temp2 = deck->cards;

        for (int k = 0; k < i; k++)
            temp1 = temp1->next_card;

        for (int k = 0; k < j; k++)
            temp2 = temp2->next_card;

        int value_temp = temp1->value;
        int id_temp = temp1->id;

        temp1->value = temp2->value;
        temp1->id = temp2->id;

        temp2->value = value_temp;
        temp2->id = id_temp;
    }
}

// Fill the hand with cards from the deck
int fillHand(int size, Hand* hand, Deck* deck)
{
    if (hand == NULL || deck == NULL)
        return 0;

    while (hand->size < size && deck->size > 0)
    {
        Card* temp = deck->cards;
        if (temp != NULL)
        {
            if (hand->cards == NULL)
            {
                hand->cards = temp;
                deck->cards = temp->next_card;
                temp->next_card = NULL;
            }
            else
            {
                Card* last_card = hand->cards;
                while (last_card->next_card != NULL)
                    last_card = last_card->next_card;

                last_card->next_card = temp;
                deck->cards = temp->next_card;
                temp->next_card = NULL;
            }

            hand->size++;
            deck->size--;
        }
    }

    return 1;
}

// Show the cards in the hand
void showHand(Hand* hand)
{
    if (hand == NULL)
        return;

    Card* temp = hand->cards;
    printf("Hand (Size: %d): ", hand->size);

    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next_card;
    }

    printf("\n");
}

// Play a card with a specific ID from the hand and add it back to the deck
int playCard(int id, Hand* hand, Deck* deck)
{
    if (hand == NULL || deck == NULL)
        return 0;

    Card* temp = hand->cards;
    Card* prev_card = NULL;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            if (prev_card == NULL)
            {
                hand->cards = temp->next_card;
            }
            else
            {
                prev_card->next_card = temp->next_card;
            }

            temp->next_card = NULL;
            hand->size--;

            if (deck->cards == NULL)
            {
                deck->cards = temp;
            }
            else
            {
                Card* last_card = deck->cards;
                while (last_card->next_card != NULL)
                    last_card = last_card->next_card;

                last_card->next_card = temp;
            }

            deck->size++;
            return 1;
        }

        prev_card = temp;
        temp = temp->next_card;
    }

    return 0;
}