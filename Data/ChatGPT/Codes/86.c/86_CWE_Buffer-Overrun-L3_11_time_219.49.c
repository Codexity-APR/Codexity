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

// Create a new deck with empty cards
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

// Create a new hand with empty cards
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
    if (card != NULL && deck != NULL)
    {
        if (deck->cards == NULL)
        {
            deck->cards = card;
        }
        else
        {
            Card* current_card = deck->cards;
            while (current_card->next_card != NULL)
            {
                current_card = current_card->next_card;
            }
            current_card->next_card = card;
        }
        deck->size++;
        return 1;
    }
    return 0;
}

// Check if a card with a given ID exists in the deck
int cardExists(int id, Deck* deck)
{
    if (deck != NULL)
    {
        Card* current_card = deck->cards;
        while (current_card != NULL)
        {
            if (current_card->id == id)
            {
                return 1;
            }
            current_card = current_card->next_card;
        }
    }
    return 0;
}

// Check if a card exists in the deck based on the card's address
int cardExistsC(Card* card, Deck* deck)
{
    if (deck != NULL)
    {
        Card* current_card = deck->cards;
        while (current_card != NULL)
        {
            if (current_card == card)
            {
                return 1;
            }
            current_card = current_card->next_card;
        }
    }
    return 0;
}

// Shuffle the cards in the deck
void shuffle(Deck* deck)
{
    if (deck != NULL)
    {
        int i = 0;
        int num_cards = deck->size;
        Card* cards[num_cards];

        Card* current_card = deck->cards;
        while (current_card != NULL)
        {
            cards[i++] = current_card;
            current_card = current_card->next_card;
        }

        for (i = num_cards - 1; i >= 0; i--)
        {
            int r = rand() % (i + 1);
            Card* temp = cards[i];
            cards[i] = cards[r];
            cards[r] = temp;
        }

        deck->cards = cards[0];
        current_card = deck->cards;
        for (i = 1; i < num_cards; i++)
        {
            current_card->next_card = cards[i];
            current_card = current_card->next_card;
        }
        current_card->next_card = NULL;
    }
}

// Fill a hand with cards from the deck
int fillHand(int size, Hand* hand, Deck* deck)
{
    if (hand != NULL && deck != NULL)
    {
        if (hand->size + size <= 52)
        {
            int i;
            for (i = 0; i < size; i++)
            {
                Card* current_card = deck->cards;
                while (current_card != NULL)
                {
                    if (cardExistsC(current_card, deck))
                    {
                        Card* card = createCard();
                        card->value = current_card->value;
                        card->id = current_card->id;
                        addCard(card, hand);
                        break;
                    }
                    current_card = current_card->next_card;
                }
            }
            return 1;
        }
    }
    return 0;
}

// Show the cards in a hand
void showHand(Hand* hand)
{
    if (hand != NULL)
    {
        printf("Hand:\n");
        Card* current_card = hand->cards;
        while (current_card != NULL)
        {
            printf("ID: %d, Value: %d\n", current_card->id, current_card->value);
            current_card = current_card->next_card;
        }
        printf("\n");
    }
}

// Play a card from the hand
int playCard(int id, Hand* hand, Deck* deck)
{
    if (hand != NULL && deck != NULL)
    {
        if (cardExists(id, hand))
        {
            Card* current_card = hand->cards;
            Card* prev_card = NULL;

            while (current_card != NULL)
            {
                if (current_card->id == id)
                {
                    if (prev_card == NULL)
                    {
                        hand->cards = current_card->next_card;
                    }
                    else
                    {
                        prev_card->next_card = current_card->next_card;
                    }

                    addCard(current_card, deck);
                    hand->size--;
                    return 1;
                }

                prev_card = current_card;
                current_card = current_card->next_card;
            }
        }
    }
    return 0;
}