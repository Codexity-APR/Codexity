List of vulnerabilities detected: 
Error: Buffer Overrun L3   Offset: [1, +oo] Size: [0, +oo] by call to `shuffle`.
 Example: 
  62.             addCard(temp, deck);
  63.         }
  64.         shuffle(deck);
              ^
  65.         fillHand(7, player1, deck);
  66.         fillHand(7, player2, deck);

 Error type: CWE-457 at line: 183. Error message: Uninitialized variables: cards.value, cards.id, cards.next_card


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
    Card* card = (Card*)malloc(sizeof(Card));
    if (card != NULL)
    {
        card->value = rand() % 11;
        card->id = rand() % 10001;
        card->next_card = NULL;
    }
    return card;
}
// Create a new deck of cards
Deck* createDeck()
{
    Deck* deck = (Deck*)malloc(sizeof(Deck));
    if (deck != NULL)
    {
        deck->size = 0;
        deck->cards = NULL;
    }
    return deck;
}
// Create a new hand of cards
Hand* createHand()
{
    Hand* hand = (Hand*)malloc(sizeof(Hand));
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
    card->next_card = deck->cards;
    deck->cards = card;
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
// Shuffle the deck of cards
void shuffle(Deck* deck)
{
    if (deck == NULL || deck->cards == NULL)
        return;
    int i = 0;
    int size = deck->size;
    Card* cards[size];
    // Move cards to an array
    Card* current = deck->cards;
    for (i = 0; i < size; i++)
    {
        cards[i] = current;
        current = current->next_card;
    }
    // Shuffle the array
    for (i = size - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        Card* temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
    // Move cards back to the deck
    deck->cards = cards[0];
    current = deck->cards;
    for (i = 1; i < size; i++)
    {
        current->next_card = cards[i];
        current = current->next_card;
    }
    current->next_card = NULL;
}
// Fill a hand with cards from the deck
int fillHand(int size, Hand* hand, Deck* deck)
{
    if (hand == NULL || deck == NULL)
        return 0;
    int i = 0;
    for (i = 0; i < size; i++)
    {
        if (deck->cards == NULL)
            return 0;
        Card* current = deck->cards;
        deck->cards = current->next_card;
        current->next_card = hand->cards;
        hand->cards = current;
        hand->size++;
    }
    return 1;
}
// Display the cards in a hand
void showHand(Hand* hand)
{
    if (hand == NULL || hand->cards == NULL)
    {
        printf("Empty hand\n");
        return;
    }
    Card* current = hand->cards;
    printf("Hand: ");
    while (current != NULL)
    {
        printf("[%d, %d] ", current->id, current->value);
        current = current->next_card;
    }
    printf("\n");
}
// Play a card from the hand
int playCard(int id, Hand* hand, Deck* deck)
{
    if (hand == NULL || hand->cards == NULL)
        return 0;
    Card* current = hand->cards;
    Card* previous = NULL;
    if (id == -1)
    {
        // Play the first card in the hand
        hand->cards = current->next_card;
    }
    else
    {
        // Play a specific card with the given ID
        while (current != NULL && current->id != id)
        {
            previous = current;
            current = current->next_card;
        }
        if (current == NULL)
            return 0;
        if (previous == NULL)
            hand->cards = current->next_card;
        else
            previous->next_card = current->next_card;
    }
    current->next_card = deck->cards;
    deck->cards = current;
    deck->size++;
    hand->size--;
    return 1;
}