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
    fgets(word, WORD_SIZE, stdin);
    length = strlen(word) - 1;
    word[length] = '\0';
    
    while (!is_game_over(guesses_left, word_guessed)) {
        printf("\n");
        print_word(word, length, letters_guessed);
        print_guesses_left(guesses_left);
        
        printf("Enter a letter: ");
        scanf(" %c", &guess);
        guess = tolower(guess);
        
        int found = 0;
        for (int i = 0; i < length; i++) {
            if (word[i] == guess) {
                letters_guessed[i] = 1;
                found = 1;
            }
        }
        
        if (!found) {
            guesses_left--;
        }
        
        word_guessed = 1;
        for (int i = 0; i < length; i++) {
            if (!letters_guessed[i]) {
                word_guessed = 0;
                break;
            }
        }
    }
    
    printf("\n");
    print_word(word, length, letters_guessed);
    
    if (word_guessed) {
        printf("Congratulations! You guessed the word correctly.\n");
    } else {
        printf("Game over! You ran out of guesses. The word was: %s\n", word);
    }
    
    return 0;
}