#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_GUESSES 6
#define WORD_SIZE 20

void print_guesses_left(int guesses_left) {
    printf("You have %d guesses left.\n", guesses_left);
}

void print_word(char word[], int length, int letters_guessed[]) {
    for (int i = 0; i < length; i++) {
        if (letters_guessed[i]) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

bool is_game_over(int guesses_left, bool word_guessed) {
    return guesses_left == 0 || word_guessed;
}

int main() {
    char word[WORD_SIZE+1];
    char guess;
    int length;
    bool letters_guessed[WORD_SIZE] = {false};
    int guesses_left = MAX_GUESSES;
    bool word_guessed = false;
    
    printf("Enter a word: ");
    if (scanf("%20s", word) != 1) {
        printf("Input error\n");
        return 1;
    }
    length = strlen(word);
    
    while (!is_game_over(guesses_left, word_guessed)) {
        print_guesses_left(guesses_left);
        print_word(word, length, letters_guessed);
        printf("Enter a letter: ");
        if (scanf(" %c", &guess) != 1) {
            printf("Input error\n");
            return 1;
        }
        guess = tolower(guess);
        if (isalpha(guess)) {
            bool found = false;
            for (int i = 0; i < length; i++) {
                if (word[i] == guess) {
                    letters_guessed[i] = true;
                    found = true;
                }
            }
            if (found) {
                printf("You guessed a letter!\n");
                if (memcmp(word, letters_guessed, length) == 0) {
                    word_guessed = true;
                }
            } else {
                printf("That letter is not in the word.\n");
                guesses_left--;
            }
        } else {
            printf("That is not a letter.\n");
        }
    }
    if (word_guessed) {
        printf("You win!\n");
    } else {
        printf("You lose!\n");
    }
    return 0;
}