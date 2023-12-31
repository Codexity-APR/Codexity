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


Card* createCard() {
    Card* card = (Card*) malloc(sizeof(Card));
    if (card == NULL) {
        return NULL;
    }
    card->id = rand() % 10000;
    card->value = rand() % 10;
    card->next_card = NULL;
    return card;
}

Deck* createDeck() {
    Deck* deck = (Deck*) malloc(sizeof(Deck));
    if (deck == NULL) {
        return NULL;
    }
    deck->size = 52;
    deck->cards = NULL;
    return deck;
}

Hand* createHand() {
    Hand* hand = (Hand*) malloc(sizeof(Hand));
    if (hand == NULL) {
        return NULL;
    }
    hand->size = 0;
    hand->cards = NULL;
    return hand;
}

int addCard(Card* card, Deck* deck) {
    if (card == NULL || deck == NULL) {
        return -1;
    }
    Card* temp = deck->cards;
    Card* prev = NULL;
    while (temp != NULL) {
        prev = temp;
        temp = temp->next_card;
    }
    if (temp == NULL) {
        if (prev == NULL) {
            deck->cards = card;
        } else {
            prev->next_card = card;
        }
    }
    deck->size++;
    return 0;
}

int cardExists(int id, Deck* deck) {
    if (deck == NULL) {
        return -1;
    }
    Card* temp = deck->cards;
    while (temp != NULL) {
        if (temp->id == id) {
            return 1;
        }
        temp = temp->next_card;
    }
    return 0;
}

int cardExistsC(Card* card, Deck* deck) {
    if (deck == NULL) {
        return -1;
    }
    Card* temp = deck->cards;
    while (temp != NULL) {
        if (temp->id == card->id) {
            return 1;
        }
        temp = temp->next_card;
    }
    return 0;
}

void shuffle(Deck* deck) {
    if (deck == NULL) {
        return;
    }
    int i, j, k;
    Card* temp;
    for (i = 0; i < deck->size; i++) {
        j = rand() % deck->size;
        k = rand() % deck->size;
        temp = deck->cards + j;
        deck->cards[j] = deck->cards[k];
        deck->cards[k] = *temp;
    }
}

int fillHand(int size, Hand* hand, Deck* deck) {
    if (hand == NULL || deck == NULL) {
        return -1;
    }
    if (size > deck->size) {
        return -1;
    }
    hand->size = size;
    hand->cards = (Card*) malloc(size * sizeof(Card));
    if (hand->cards == NULL) {
        return -1;
    }
    int i = 0;
    Card* temp_deck = deck->cards;
    Card* temp_hand = hand->cards;
    while (i < size && temp_deck != NULL) {
        *temp_hand = *temp_deck;
        temp_deck = temp_deck->next_card;
        temp_hand++;
        i++;
    }
    deck->cards = temp_deck;
    deck->size -= size;
    return 0;
}

void showHand(Hand* hand) {
    if (hand == NULL) {
        return;
    }
    printf("Hand: ");
    int i;
    for (i = 0; i < hand->size; i++) {
        printf("%d ", hand->cards[i].id);
    }
    printf("\n");
}