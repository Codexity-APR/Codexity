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

    if (card != NULL)
    {
        card->value = rand() % 11;
        card->id = rand() % 10001;
        card->next_card = NULL;
    }

    return card;
}

// Create an empty deck
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

// Create an empty hand
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

    if (cardExistsC(card, deck))
        return 0;

    if (deck->cards == NULL)
    {
        deck->cards = card;
    }
    else
    {
        Card* current = deck->cards;
        while (current->next_card != NULL)
        {
            current = current->next_card;
        }
        current->next_card = card;
    }

    deck->size++;
    return 1;
}

// Check if card with specific ID already exists in the deck
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

// Check if a card already exists in the deck
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

// Shuffle the cards in the deck
void shuffle(Deck* deck)
{
    if (deck == NULL || deck->cards == NULL)
        return;

    int i, j;
    int size = deck->size;
    Card* cards_arr[size];
    Card* current = deck->cards;

    for (i = 0; i < size; i++)
    {
        cards_arr[i] = current;
        current = current->next_card;
    }

    for (i = 0; i < size; i++)
    {
        j = i + rand() % (size - i);
        Card* temp = cards_arr[i];
        cards_arr[i] = cards_arr[j];
        cards_arr[j] = temp;
    }

    deck->cards = cards_arr[0];
    current = deck->cards;
    for (i = 1; i < size; i++)
    {
        current->next_card = cards_arr[i];
        current = current->next_card;
    }
    current->next_card = NULL;
}

// Fill a hand with cards from the deck
int fillHand(int size, Hand* hand, Deck* deck)
{
    if (hand == NULL || deck == NULL || size <= 0)
        return 0;

    if (size > deck->size)
        size = deck->size;

    int i;
    for (i = 0; i < size; i++)
    {
        Card* current = deck->cards;
        if (current == NULL)
            break;

        if (hand->cards == NULL)
        {
            hand->cards = current;
        }
        else
        {
            Card* last = hand->cards;
            while (last->next_card != NULL)
            {
                last = last->next_card;
            }
            last->next_card = current;
        }

        deck->cards = deck->cards->next_card;
        hand->size++;
        deck->size--;
    }

    return 1;
}

// Show the cards in a hand
void showHand(Hand* hand)
{
    if (hand == NULL || hand->cards == NULL)
        return;

    Card* current = hand->cards;
    printf("Hand: ");
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next_card;
    }
    printf("\n");
}

// Play a card from the hand and remove it from the deck
int playCard(int id, Hand* hand, Deck* deck)
{
    if (hand == NULL || deck == NULL || hand->cards == NULL)
        return 0;

    Card* current = hand->cards;

    if (id >= 0)
    {
        Card* previous = NULL;
        while (current != NULL)
        {
            if (current->id == id)
            {
                if (previous == NULL)
                    hand->cards = current->next_card;
                else
                    previous->next_card = current->next_card;

                current->next_card = NULL;
                hand->size--;
                deck->size++;
                addCard(current, deck);
                return 1;
            }

            previous = current;
            current = current->next_card;
        }
    }
    else
    {
        Card* last = hand->cards;
        while (last->next_card != NULL)
        {
            last = last->next_card;
        }

        if (last != NULL)
        {
            last->next_card = current;
            hand->cards = current->next_card;
            current->next_card = NULL;
            hand->size--;
            deck->size++;
            addCard(current, deck);
            return 1;
        }
    }

    return 0;
}