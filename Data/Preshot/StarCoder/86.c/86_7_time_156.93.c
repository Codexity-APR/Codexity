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


Card* createCard(){
    Card* card = (Card*)malloc(sizeof(Card));
    if(card != NULL){
        card->id = rand() % 10000;
        card->value = rand() % 10;
        card->next_card = NULL;
    }
    return card;
}

Deck* createDeck(){
    Deck* deck = (Deck*)malloc(sizeof(Deck));
    if(deck != NULL){
        deck->size = 52;
        deck->cards = NULL;
    }
    return deck;
}

Hand* createHand(){
    Hand* hand = (Hand*)malloc(sizeof(Hand));
    if(hand != NULL){
        hand->size = 0;
        hand->cards = NULL;
    }
    return hand;
}

int addCard(Card* card, Deck* deck){
    if (card == NULL || deck == NULL)
    {
        return -1;
    }
    else
    {
        if(deck->cards == NULL){
            deck->cards = card;
        }else{
            Card* temp = deck->cards;
            while (temp->next_card != NULL)
            {
                temp = temp->next_card;
            }
            temp->next_card = card;
        }
        return 0;
    }
}

int cardExists(int id, Deck* deck){
    if (deck == NULL)
    {
        return -1;
    }
    else
    {
        Card* temp = deck->cards;
        while (temp!= NULL)
        {
            if (temp->id == id)
            {
                return 1;
            }
            temp = temp->next_card;
        }
        return 0;
    }
}

int cardExistsC(Card* card, Deck* deck){
    if (deck == NULL)
    {
        return -1;
    }
    else
    {
        Card* temp = deck->cards;
        while (temp!= NULL)
        {
            if (temp->id == card->id)
            {
                return 1;
            }
            temp = temp->next_card;
        }
        return 0;
    }
}

void shuffle(Deck* deck){
    if (deck == NULL)
    {
        return;
    }
    else
    {
        Card* temp = deck->cards;
        Card* prev = NULL;
        Card* next = NULL;
        int i = 0;
        for (i = 0; i < deck->size; i++)
        {
            next = temp->next_card;
            if (next == NULL)
            {
                deck->cards = temp;
                temp->next_card = NULL;
                break;
            }
            else
            {
                prev = temp;
                temp = next;
            }
        }
        while (next!= NULL)
        {
            prev->next_card = next->next_card;
            next = next->next_card;
        }
    }
}

int fillHand(int size, Hand* hand, Deck* deck){
    if (hand == NULL || deck == NULL)
    {
        return -1;
    }
    else
    {
        int i = 0;
        for (i = 0; i < size; i++)
        {
            Card* temp = createCard();
            if (cardExistsC(temp, deck))
            {
                addCard(temp, deck);
            }
            else
            {
                free(temp);
            }
        }
        hand->size = size;
        hand->cards = deck->cards;
        deck->cards = NULL;
        return 0;
    }
}

void showHand(Hand* hand){
    if (hand == NULL)
    {
        return;
    }
    else
    {
        Card* temp = hand->cards;
        printf("Hand: ");
        while (temp!= NULL)
        {
            printf("%d ", temp->id);
            temp = temp->next_card;
        }
        printf("\n");
    }
}