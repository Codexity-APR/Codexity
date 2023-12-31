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
    if (card != NULL) {
        card->value = rand() % 11;
        card->id = rand() % 10001;
        card->next_card = NULL;
    }
    return card;
}

// Create a new, empty deck
Deck* createDeck()
{
    Deck* deck = NULL;
    deck = (Deck*)malloc(sizeof(Deck));
    if (deck != NULL) {
        deck->size = 0;
        deck->cards = NULL;
    }
    return deck;
}

// Create a new, empty hand
Hand* createHand()
{
    Hand* hand = NULL;
    hand = (Hand*)malloc(sizeof(Hand));
    if (hand != NULL) {
        hand->size = 0;
        hand->cards = NULL;
    }
    return hand;
}

// Add a card to the deck
int addCard(Card* card, Deck* deck)
{
    if (card == NULL || deck == NULL) {
        return 0;
    }
    if (deck->cards == NULL) {
        deck->cards = card;
    }
    else {
        Card* curr = deck->cards;
        while (curr->next_card != NULL) {
            curr = curr->next_card;
        }
        curr->next_card = card;
    }
    deck->size++;
    return 1;
}

// Check if a card with specified ID exists in the deck
int cardExists(int id, Deck* deck)
{
    if (deck == NULL) {
        return 0;
    }
    Card* curr = deck->cards;
    while (curr != NULL) {
        if (curr->id == id) {
            return 1;
        }
        curr = curr->next_card;
    }
    return 0;
}

// Check if a card exists in the deck (based on memory address)
int cardExistsC(Card* card, Deck* deck)
{
    if (card == NULL || deck == NULL) {
        return 0;
    }
    Card* curr = deck->cards;
    while (curr != NULL) {
        if (curr == card) {
            return 1;
        }
        curr = curr->next_card;
    }
    return 0;
}

// Shuffle the deck using Fisher-Yates algorithm
void shuffle(Deck* deck)
{
    if (deck == NULL || deck->cards == NULL) {
        return;
    }
    for (int i = deck->size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Card* temp = deck->cards;
        for (int k = 0; k < j; k++) {
            temp = temp->next_card;
        }
        Card* curr = deck->cards;
        for (int k = 0; k < i; k++) {
            curr = curr->next_card;
        }
        int tempValue = temp->value;
        int tempID = temp->id;
        temp->value = curr->value;
        temp->id = curr->id;
        curr->value = tempValue;
        curr->id = tempID;
    }
}

// Fill the hand with specified number of cards from the deck
int fillHand(int size, Hand* hand, Deck* deck)
{
    if (size <= 0 || hand == NULL || deck == NULL) {
        return 0;
    }
    if (deck->size < size) {
        return 0;
    }
    hand->size = size;
    hand->cards = (Card*)malloc(size * sizeof(Card));
    if (hand->cards == NULL) {
        return 0;
    }
    Card* curr = deck->cards;
    for (int i = 0; i < size; i++) {
        hand->cards[i] = *curr;
        curr = curr->next_card;
    }
    return 1;
}

// Print the cards in the hand
void showHand(Hand* hand)
{
    if (hand == NULL || hand->cards == NULL) {
        return;
    }
    printf("Hand: ");
    for (int i = 0; i < hand->size; i++) {
        printf("%d ", hand->cards[i].value);
    }
    printf("\n");
}

// Play a card from the hand by ID
int playCard(int id, Hand* hand, Deck* deck)
{
    if (hand == NULL || deck == NULL || hand->cards == NULL) {
        return 0;
    }
    int index = -1;
    if (id != -1) {
        for (int i = 0; i < hand->size; i++) {
            if (hand->cards[i].id == id) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            return 0;
        }
    }
    else {
        index = rand() % hand->size;
    }
    Card* card = &hand->cards[index];
    if (!cardExistsC(card, hand)) {
        return 0;
    }
    if (addCard(card, deck)) {
        hand->size--;
        if (hand->size == 0) {
            free(hand->cards);
            hand->cards = NULL;
        }
        else {
            Card* newCards = (Card*)malloc(hand->size * sizeof(Card));
            int j = 0;
            for (int i = 0; i < hand->size + 1; i++) {
                if (i != index) {
                    newCards[j] = hand->cards[i];
                    j++;
                }
            }
            free(hand->cards);
            hand->cards = newCards;
        }
        return 1;
    }
    return 0;
}