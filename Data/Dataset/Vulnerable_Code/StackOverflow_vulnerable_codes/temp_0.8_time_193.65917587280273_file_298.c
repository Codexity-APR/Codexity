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
    card->id = rand() % 10000;
    card->value = rand() % 11;
    card->next_card = NULL;
    
    return card;
}

// Create a new deck with an initial size of 0
Deck* createDeck()
{
    Deck* deck = NULL;
    deck = (Deck*)malloc(sizeof(Deck));
    deck->size = 0;
    deck->cards = NULL;
    
    return deck;
}

// Create a new hand with an initial size of 0
Hand* createHand()
{
    Hand* hand = NULL;
    hand = (Hand*)malloc(sizeof(Hand));
    hand->size = 0;
    hand->cards = NULL;
    
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
    }
    else
    {
        Card* current = deck->cards;
        while (current->next_card != NULL)
            current = current->next_card;
        
        current->next_card = card;
    }
    
    deck->size++;
    
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

// Shuffle the deck by randomly rearranging the cards
void shuffle(Deck* deck)
{
    if (deck == NULL)
        return;
    
    int n = deck->size;
    if (n <= 1)
        return;
    
    Card** cards = (Card**)malloc(n * sizeof(Card*));
    int i = 0;
    Card* current = deck->cards;
    
    while (current != NULL)
    {
        cards[i] = current;
        current = current->next_card;
        i++;
    }
    
    for (i = n - 1; i >= 1; i--)
    {
        int j = rand() % (i + 1);
        Card* temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
    
    deck->cards = cards[0];
    current = deck->cards;
    
    for (i = 1; i < n; i++)
    {
        current->next_card = cards[i];
        current = current->next_card;
    }
    
    current->next_card = NULL;
    free(cards);
}

// Fill the hand with cards from the deck
int fillHand(int size, Hand* hand, Deck* deck)
{
    if (hand == NULL || deck == NULL)
        return 0;
    
    if (size > deck->size)
        size = deck->size;
    
    int i = 0;
    for (i = 0; i < size; i++)
    {
        Card* current = deck->cards;
        hand->cards = current;
        deck->cards = current->next_card;
        hand->size++;
        deck->size--;
        current->next_card = NULL;
    }
    
    return 1;
}

// Show the cards in the hand
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

// Play a card from the hand by ID
int playCard(int id, Hand* hand, Deck* deck)
{
    if (hand == NULL || deck == NULL)
        return 0;
    
    if (hand->size == 0)
        return 0;
    
    Card* current = hand->cards;
    Card* prev = NULL;
    
    if (id == -1)
    {
        while (current->next_card != NULL)
        {
            prev = current;
            current = current->next_card;
        }
    }
    else
    {
        while (current != NULL && current->id != id)
        {
            prev = current;
            current = current->next_card;
        }
    }
    
    if (current == NULL)
        return 0;
    
    if (prev == NULL)
        hand->cards = current->next_card;
    else
        prev->next_card = current->next_card;
    
    current->next_card = NULL;
    hand->size--;
    
    addCard(current, deck);
    
    return 1;
}