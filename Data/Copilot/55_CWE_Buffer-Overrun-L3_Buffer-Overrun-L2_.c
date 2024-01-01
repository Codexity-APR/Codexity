
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
  // Get the chosen word and its length
    strcpy(word, word_list[word_index]);
    word_length = strlen(word);

    // Initialize guessed_letters to all underscores
    for (i = 0; i < word_length; i++) {
      guessed_letters[i] = '_';
    }
    guessed_letters[word_length] = '\0';

    // Main game loop
    while (num_incorrect_guesses < MAX_ATTEMPTS && strcmp(word, guessed_letters) != 0) {
      // Print the current state of the game
      printf("Word: %s\n", guessed_letters);
      printf("Guesses remaining: %d\n", MAX_ATTEMPTS - num_incorrect_guesses);

      // Get the user's guess
      char guess;
      printf("Enter your guess: ");
      scanf(" %c", &guess);

      // Check if the guess is correct
      int found = 0;
      for (i = 0; i < word_length; i++) {
        if (word[i] == guess) {
          guessed_letters[i] = guess;
          found = 1;
        }
      }

      // If the guess is incorrect, increment the number of incorrect guesses
      if (!found) {
        num_incorrect_guesses++;
      }
      num_guesses++;
    }

    // Print the final state of the game
    if (num_incorrect_guesses == MAX_ATTEMPTS) {
      printf("You lose! The word was %s.\n", word);
    } else {
      printf("Congratulations, you win! The word was %s.\n", word);
    }
    printf("Number of guesses: %d\n", num_guesses);

    return 0;
  }
