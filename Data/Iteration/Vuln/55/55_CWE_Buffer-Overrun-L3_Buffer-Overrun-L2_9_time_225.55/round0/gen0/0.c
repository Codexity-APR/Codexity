#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ATTEMPTS 6
#define MAX_WORD_LENGTH 20

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
  
    // Get the chosen word
    strcpy(word, word_list[word_index]);
    word_length = strlen(word);

    // Initialize the guessed letters array
    for (i = 0; i < word_length; i++) {
        guessed_letters[i] = '_';
    }
    guessed_letters[word_length] = '\0';

    // Game loop
    while (num_incorrect_guesses < MAX_ATTEMPTS && strcmp(word, guessed_letters) != 0) {
        char guess;
        printf("Guess a letter: ");
        scanf(" %c", &guess);

        int found = 0;
        for (i = 0; i < word_length; i++) {
            if (word[i] == guess) {
                guessed_letters[i] = guess;
                found = 1;
            }
        }

        if (!found) {
            num_incorrect_guesses++;
            printf("Incorrect guess! Attempt %d of %d\n", num_incorrect_guesses, MAX_ATTEMPTS);
        }

        printf("Guessed letters: %s\n", guessed_letters);
        printf("\n");

        num_guesses++;
    }

    if (num_incorrect_guesses < MAX_ATTEMPTS) {
        printf("Congratulations! You guessed the word correctly in %d attempts.\n", num_guesses);
    } else {
        printf("Sorry, you failed to guess the word. The word was: %s\n", word);
    }

    return 0;
}