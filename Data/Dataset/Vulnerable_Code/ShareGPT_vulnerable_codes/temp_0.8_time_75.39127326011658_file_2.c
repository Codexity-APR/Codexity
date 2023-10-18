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

    while (!is_game_over(guesses_left, word_guessed)) {
        printf("\n");
        print_word(word, length, letters_guessed);
        print_guesses_left(guesses_left);

        printf("Enter a letter: ");
        scanf(" %c", &guess);
        
        for (int i = 0; i < length; i++) {
            if (tolower(word[i]) == tolower(guess)) {
                letters_guessed[i] = 1;
            }
        }
        
        int found = 0;
        for (int i = 0; i < length; i++) {
            if (letters_guessed[i]) {
                found = 1;
            } else {
                found = 0;
                break;
            }
        }
        
        if (found) {
            word_guessed = 1;
            printf("Congratulations! You guessed the word \"%s\" correctly!\n", word);
            break;
        }
        
        if (tolower(word[i]) != tolower(guess)) {
            guesses_left--;
        }
        
        if (guesses_left == 0) {
            printf("Sorry! You ran out of guesses. The word was \"%s\".\n", word);
            break;
        }
    }

    return 0;
}