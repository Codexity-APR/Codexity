#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    Card* card = (Card*)malloc(sizeof(Card));
    if (card == NULL) {
        return NULL;
    }
    card->id = rand() % 10000;
    card->value = rand() % 10;
    card->next_card = NULL;
    return card;
}

Deck* createDeck() {
    Deck* deck = (Deck*)malloc(sizeof(Deck));
    if (deck == NULL) {
        return NULL;
    }
    deck->size = 52;
    deck->cards = NULL;
    return deck;
}

Hand* createHand() {
    Hand* hand = (Hand*)malloc(sizeof(Hand));
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
    card->next_card = deck->cards;
    deck->cards = card;
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
    if (deck == NULL || card == NULL) {
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
    Card* temp = deck->cards;
    Card* prev = NULL;
    Card* next = NULL;
    int i = 0;
    for (i = 0; i < deck->size; i++) {
        next = temp->next_card;
        if (next == NULL) {
            deck->cards = temp;
            temp->next_card = NULL;
            break;
        } else {
            prev = temp;
            temp = next;
        }
    }
    while (next != NULL) {
        prev->next_card = next->next_card;
        next = next->next_card;
    }
}

int fillHand(int size, Hand* hand, Deck* deck) {
    if (hand == NULL || deck == NULL) {
        return -1;
    }
    int i;
    for (i = 0; i < size; i++) {
        Card* temp = createCard();
        if (temp == NULL) {
            return -1;
        }
        while (!cardExistsC(temp, deck)) {
            free(temp);
            temp = createCard();
            if (temp == NULL) {
                return -1;
            }
        }
        addCard(temp, deck);
    }
    hand->size = size;
    hand->cards = deck->cards;
    deck->cards = NULL;
    return 0;
}

void showHand(Hand* hand) {
    if (hand == NULL) {
        return;
    }
    Card* temp = hand->cards;
    printf("Hand: ");
    while (temp != NULL) {
        printf("%d ", temp->id);
        temp = temp->next_card;
    }
    printf("\n");
}

int playCard(int id, Hand* hand, Deck* deck) {
    if (hand == NULL || deck == NULL) {
        return -1;
    }