#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

int is_game_over(int guesses_left, int word_guessed) {
    return guesses_left == 0 || word_guessed;
}

int main() {
    char word[WORD_SIZE];
    char guess;
    int length;
    int letters_guessed[WORD_SIZE] = {0};
    int guesses_left = MAX_GUESSES;
    int word_guessed = 0;

    printf("Enter a word: ");
    if (scanf("%19s", word) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    length = strlen(word);

    while (!is_game_over(guesses_left, word_guessed)) {
        print_guesses_left(guesses_left);
        print_word(word, length, letters_guessed);
        printf("Enter a letter: ");
        if (scanf(" %c", &guess) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
        guess = tolower(guess);
        if (!isalpha(guess)) {
            printf("That is not a letter.\n");
            continue;
        }
        int letter_found = 0;
        for (int i = 0; i < length; i++) {
            if (word[i] == guess) {
                letters_guessed[i] = 1;
                letter_found = 1;
            }
        }
        if (letter_found) {
            printf("You guessed a letter!\n");
        } else {
            printf("That letter is not in the word.\n");
            guesses_left--;
        }
        int all_letters_guessed = 1;
        for (int i = 0; i < length; i++) {
            if (!letters_guessed[i]) {
                all_letters_guessed = 0;
                break;
            }
        }
        if (all_letters_guessed) {
            word_guessed = 1;
            break;
        }
    }
    if (word_guessed) {
        printf("You win!\n");
    } else {
        printf("You lose!\n");
    }
    return 0;
}