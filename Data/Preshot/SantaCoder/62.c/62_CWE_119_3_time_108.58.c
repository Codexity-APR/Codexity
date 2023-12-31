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
    scanf("%s", word);
    length = strlen(word);
    printf("The word is ");
    print_word(word, length, letters_guessed);
    while (!is_game_over(guesses_left, word_guessed)) {
        printf("Guess a letter: ");
        scanf(" %c", &guess);
        int guess_found = 0;
        for (int i = 0; i < length; i++) {
            if (tolower(guess) == tolower(word[i])) {
                letters_guessed[i] = 1;
                guess_found = 1;
            }
        }
        if (!guess_found) {
            printf("Incorrect!\n");
            guesses_left--;
            print_guesses_left(guesses_left);
        } else {
            printf("Correct!\n");
        }
        printf("The word is ");
        print_word(word, length, letters_guessed);
        if (memcmp(letters_guessed, word, length) == 0) {
            printf("You win!\n");
            word_guessed = 1;
        }
    }
    if (guesses_left == 0) {
        printf("You lose! The word was \"%s\".\n", word);
    }
    return 0;
}