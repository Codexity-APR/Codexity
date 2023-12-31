List of vulnerabilities detected: 
Error: Buffer Overrun L1   Offset: [1, +oo] Size: 1 by call to `shuffle`.
 Example: 
  69.         }
  70. 
  71.         shuffle(deck);
              ^
  72. 
  73.         fillHand(7, player1, deck);


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
// Create a new deck with empty card list and size 0
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
// Create a new hand with empty card list and size 0
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
// Add card to the deck
int addCard(Card* card, Deck* deck)
{
    if (card == NULL || deck == NULL) {
        return -1;
    }
    if (cardExistsC(card, deck)) {
        return -1;
    }
    if (deck->size == 0) {
        deck->cards = card;
    } else {
        Card* current_card = deck->cards;
        while (current_card->next_card != NULL) {
            current_card = current_card->next_card;
        }
        current_card->next_card = card;
    }
    deck->size++;
    return 0;
}
// Check if a card with the given ID exists in the deck
int cardExists(int id, Deck* deck)
{
    if (deck == NULL) {
        return 0;
    }
    Card* current_card = deck->cards;
    while (current_card != NULL) {
        if (current_card->id == id) {
            return 1;
        }
        current_card = current_card->next_card;
    }
    return 0;
}
// Check if a card exists in the deck
int cardExistsC(Card* card, Deck* deck)
{
    if (card == NULL || deck == NULL) {
        return 0;
    }
    Card* current_card = deck->cards;
    while (current_card != NULL) {
        if (current_card == card) {
            return 1;
        }
        current_card = current_card->next_card;
    }
    return 0;
}
// Shuffle the deck using Fisher-Yates algorithm
void shuffle(Deck* deck)
{
    if (deck == NULL) {
        return;
    }
    int i, j;
    int n = deck->size;
    Card* cards = deck->cards;
    for (i = n - 1; i > 0; i--) {
        j = rand() % (i + 1);
        Card temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}
// Fill hand with cards from the deck
int fillHand(int size, Hand* hand, Deck* deck)
{
    if (size <= 0 || hand == NULL || deck == NULL) {
        return -1;
    }
    int i;
    for (i = 0; i < size; i++) {
        if (deck->size == 0) {
            return -1;
        }
        Card* card = deck->cards;
        deck->cards = card->next_card;
        card->next_card = hand->cards;
        hand->cards = card;
        deck->size--;
        hand->size++;
    }
    return 0;
}
// Display the cards in the hand
void showHand(Hand* hand)
{
    if (hand == NULL) {
        return;
    }
    printf("Hand: ");
    Card* current_card = hand->cards;
    while (current_card != NULL) {
        printf("(%d, %d) ", current_card->id, current_card->value);
        current_card = current_card->next_card;
    }
    printf("\n");
}
// Play a card from the hand and remove it from the hand and deck
int playCard(int id, Hand* hand, Deck* deck)
{
    if (hand == NULL || deck == NULL) {
        return -1;
    }
    Card* current_card = hand->cards;
    Card* previous_card = NULL;
    while (current_card != NULL) {
        if (id == -1 || current_card->id == id) {
            if (previous_card == NULL) {
                hand->cards = current_card->next_card;
            } else {
                previous_card->next_card = current_card->next_card;
            }
            current_card->next_card = NULL;
            deck->size++;
            free(current_card);
            return 0;
        }
        previous_card = current_card;
        current_card = current_card->next_card;
    }
    return -1;
}