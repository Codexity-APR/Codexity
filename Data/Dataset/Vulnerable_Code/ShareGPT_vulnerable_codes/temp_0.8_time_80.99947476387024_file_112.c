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

  // Copy the chosen word into the word variable
  strcpy(word, word_list[word_index]);

  // Get the length of the word
  word_length = strlen(word);

  // Initialize guessed_letters array with dashes
  for (i = 0; i < word_length; i++) {
    guessed_letters[i] = '-';
  }
  guessed_letters[word_length] = '\0';

  // Game loop
  while (num_incorrect_guesses < MAX_ATTEMPTS && strcmp(word, guessed_letters) != 0) {
    // Print the current state of the word and the guessed letters
    printf("Word: %s\n", guessed_letters);
    printf("Guesses Remaining: %d\n", MAX_ATTEMPTS - num_incorrect_guesses);

    // Get user input for a letter guess
    char guess;
    printf("Enter a letter: ");
    scanf(" %c", &guess);

    // Check if the letter has already been guessed
    int already_guessed = 0;
    for (i = 0; i < strlen(guessed_letters); i++) {
      if (guessed_letters[i] == guess) {
        already_guessed = 1;
        break;
      }
    }

    // If the letter has not been guessed, check if it is in the word
    if (!already_guessed) {
      int correct_guess = 0;
      for (i = 0; i < word_length; i++) {
        if (word[i] == guess) {
          guessed_letters[i] = guess;
          correct_guess = 1;
        }
      }

      // If the guess was incorrect, increment the incorrect guess counter
      if (!correct_guess) {
        num_incorrect_guesses++;
      }
    }

    // Increment the total guess counter
    num_guesses++;
  }

  // Print the final state of the word and the number of guesses
  printf("Word: %s\n", guessed_letters);
  if (num_incorrect_guesses == MAX_ATTEMPTS) {
    printf("You lost! The word was: %s\n", word);
  } else {
    printf("Congratulations, you won!\n");
  }
  printf("Total Guesses: %d\n", num_guesses);

  return 0;
}