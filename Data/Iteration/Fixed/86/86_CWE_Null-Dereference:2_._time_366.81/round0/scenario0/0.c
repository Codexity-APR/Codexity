List of vulnerabilities detected: 
Error: Null Dereference   pointer `cardArr` last assigned on line 193 could be null and is dereferenced at line 205, column 22.
 Example: 
  203.     for (i = deck->size - 1; i > 0; i--) {
  204.         int j = rand() % (i + 1);
  205.         Card* temp = cardArr[i];
                            ^
  206.         cardArr[i] = cardArr[j];
  207.         cardArr[j] = temp;

Error: Null Dereference   pointer `cardArr` last assigned on line 193 could be null and is dereferenced at line 198, column 9.
 Example: 
  196. 
  197.     while (current != NULL) {
  198.         cardArr[i++] = current;
               ^
  199.         current = current->next_card;
  200.     }


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
// Create an empty deck
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
// Create an empty hand
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
    if (card == NULL || deck == NULL)
        return -1;
    card->next_card = deck->cards;
    deck->cards = card;
    deck->size++;
    return 0;
}
// Check if a card with the given id exists in the deck
int cardExists(int id, Deck* deck)
{
    if (deck == NULL)
        return 0;
    Card* current = deck->cards;
    while (current != NULL) {
        if (current->id == id)
            return 1;
        current = current->next_card;
    }
    return 0;
}
// Check if a card exists in the deck (based on card object)
int cardExistsC(Card* card, Deck* deck)
{
    if (card == NULL || deck == NULL)
        return 0;
    Card* current = deck->cards;
    while (current != NULL) {
        if (current == card)
            return 1;
        current = current->next_card;
    }
    return 0;
}
// Shuffle the deck by rearranging the order of cards
void shuffle(Deck* deck)
{
    if (deck == NULL || deck->size <= 1)
        return;
    // Convert deck to array
    Card** cardArr = (Card**)malloc(deck->size * sizeof(Card*));
    Card* current = deck->cards;
    int i = 0;
    while (current != NULL) {
        cardArr[i++] = current;
        current = current->next_card;
    }
    // Perform Fisher-Yates shuffle algorithm
    for (i = deck->size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Card* temp = cardArr[i];
        cardArr[i] = cardArr[j];
        cardArr[j] = temp;
    }
    // Update deck with shuffled cards
    deck->cards = cardArr[0];
    current = deck->cards;
    for (i = 1; i < deck->size; i++) {
        current->next_card = cardArr[i];
        current = current->next_card;
    }
    current->next_card = NULL;
    // Free temporary array
    free(cardArr);
}
// Fill the hand with cards from the deck
int fillHand(int size, Hand* hand, Deck* deck)
{
    if (hand == NULL || deck == NULL || size <= 0)
        return -1;
    if (deck->size < size)
        size = deck->size;
    int count = 0;
    Card* current = deck->cards;
    Card* prev = NULL;
    while (count < size) {
        Card* temp = current;
        current = current->next_card;
        if (prev != NULL)
            prev->next_card = current;
        else
            deck->cards = current;
        temp->next_card = hand->cards;
        hand->cards = temp;
        hand->size++;
        count++;
    }
    deck->size -= count;
    return 0;
}
// Display the cards in the hand
void showHand(Hand* hand)
{
    if (hand == NULL || hand->size == 0) {
        printf("Hand is empty.\n");
        return;
    }
    printf("Hand contains %d cards:\n", hand->size);
    Card* current = hand->cards;
    while (current != NULL) {
        printf("Card ID: %d, Value: %d\n", current->id, current->value);
        current = current->next_card;
    }
}
// Play a card from the hand with the given id
int playCard(int id, Hand* hand, Deck* deck)
{
    if (hand == NULL || deck == NULL || hand->size == 0)
        return -1;
    Card* current = hand->cards;
    Card* prev = NULL;
    while (current != NULL) {
        if (id == -1 || current->id == id) {
            if (id == -1 && prev != NULL)
                prev->next_card = current->next_card;
            else if (id == -1)
                hand->cards = current->next_card;
            else if (prev != NULL)
                prev->next_card = current->next_card;
            else
                hand->cards = current->next_card;
            current->next_card = deck->cards;
            deck->cards = current;
            hand->size--;
            deck->size++;
            return 0;
        }
        prev = current;
        current = current->next_card;
    }
    return -1;
}