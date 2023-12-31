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
    int length, scanfResult;
    int letters_guessed[WORD_SIZE] = {0};
    int guesses_left = MAX_GUESSES;
    int word_guessed = 0;
    
    printf("Enter a word: ");
    scanfResult = scanf("%19s", word);
    if (scanfResult != 1) {
        printf("Invalid input\n");
        return 1;
    }
    length = strlen(word);
    
    while (!is_game_over(guesses_left, word_guessed)) {
        print_guesses_left(guesses_left);
        print_word(word, length, letters_guessed);
        printf("Enter a letter: ");
        scanfResult = scanf(" %c", &guess);
        if (scanfResult != 1) {
            printf("Invalid input\n");
            break;
        }
        guess = tolower(guess);
        if (isalpha(guess)) {
            int found = 0;
            for (int i = 0; i < length; i++) {
                if (word[i] == guess) {
                    letters_guessed[i] = 1;
                    found = 1;
                }
            }
            if (!found) {
                printf("That letter is not in the word.\n");
                guesses_left--;
            } else {
                printf("You guessed a correct letter!\n");
                int all_letters_guessed = 1;
                for (int i = 0; i < length; i++) {
                    if (!letters_guessed[i]) {
                        all_letters_guessed = 0;
                        break;
                    }
                }
                if (all_letters_guessed) {
                    word_guessed = 1;
                }
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