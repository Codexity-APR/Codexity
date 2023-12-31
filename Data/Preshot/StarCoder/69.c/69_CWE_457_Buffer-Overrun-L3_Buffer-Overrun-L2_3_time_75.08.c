#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ATTEMPTS 6
#define MAX_WORD_LENGTH 20

void draw_hangman(int num_incorrect_guesses) {
  printf("   +----+\n");
  printf("   |    |\n");
  printf("   |    %c\n", num_incorrect_guesses >= 1 ? 'O' : ' ');
  printf("   |   %c%c%c\n", num_incorrect_guesses >= 3 ? '/' : ' ', num_incorrect_guesses >= 2 ? '|' : ' ', num_incorrect_guesses >= 4 ? '\\' : ' ');
  printf("   |   %c %c\n", num_incorrect_guesses >= 5 ? '/' : ' ', num_incorrect_guesses >= 6 ? '\\' : ' ');
  printf("=======\n");
}

int main() {
    char word[MAX_WORD_LENGTH + 1];
    char guessed_letters[MAX_WORD_LENGTH];
    int num_guesses = 0;
    int num_incorrect_guesses = 0;
    int word_length;
    int i;

    // List of words to choose from
    char *word_list[] = {
        "apple",
        "banana",
        "cherry",
        "orange",
        "pear",
        "watermelon"
    };
    int num_words = sizeof(word_list) / sizeof(word_list[0]);

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Choose a random word from the list
    int word_index = rand() % num_words;

    printf("The word has been chosen. It has %d characters. You have %d attempts.\n", strlen(word_list[word_index]), MAX_ATTEMPTS);

    // Start the game
    while (num_incorrect_guesses < MAX_ATTEMPTS) {
        // Print the current status of the word
        word_length = strlen(word_list[word_index]);
        for (i = 0; i < word_length; i++) {
            if (strchr(guessed_letters, word_list[word_index][i]) != NULL) {
                printf("%c ", word_list[word_index][i]);
            } else {
                printf("_ ");
            }
        }
        printf("\n");

        // Get a guess from the user
        char guess;
        printf("Enter your guess: ");
        scanf(" %c", &guess);

        // Check if the guess is in the word
        if (strchr(word_list[word_index], guess) != NULL) {
            guessed_letters[num_guesses] = guess;
            num_guesses++;
        } else {
            num_incorrect_guesses++;
            draw_hangman(num_incorrect_guesses);
        }

        // Check if the word has been completed
        int word_completed = 1;
        for (i = 0; i < word_length; i++) {
            if (strchr(guessed_letters, word_list[word_index][i]) == NULL) {
                word_completed = 0;
                break;
            }
        }

        if (word_completed) {
            printf("Congratulations! You guessed the word.\n");
            break;
        }
    }

    if (num_incorrect_guesses == MAX_ATTEMPTS) {
        printf("Sorry, you did not guess the word. The word was %s.\n", word_list[word_index]);
    }

    return 0;
}