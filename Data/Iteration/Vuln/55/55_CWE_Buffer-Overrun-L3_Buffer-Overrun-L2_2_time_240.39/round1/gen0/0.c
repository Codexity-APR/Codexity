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
  const char *word_list[] = {
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

  // Copy the chosen word to the 'word' variable
  strncpy(word, word_list[word_index], MAX_WORD_LENGTH);
  word[MAX_WORD_LENGTH] = '\0';

  // Get the length of the chosen word
  word_length = strlen(word);

  // Initialize guessed_letters array with underscores
  for (i = 0; i < word_length; i++) {
    guessed_letters[i] = '_';
  }
  guessed_letters[word_length] = '\0';

  // Game loop
  while (num_incorrect_guesses < MAX_ATTEMPTS && strcmp(word, guessed_letters) != 0) {
    char guess;
    int found = 0;

    // Print the current state of the word
    printf("Word: %s\n", guessed_letters);

    // Get user input
    printf("Enter a letter: ");
    scanf(" %c", &guess);

    // Check if the guessed letter is in the word
    for (i = 0; i < word_length; i++) {
      if (word[i] == guess) {
        guessed_letters[i] = guess;
        found = 1;
      }
    }

    // Update number of guesses and incorrect guesses
    num_guesses++;
    if (!found) {
      num_incorrect_guesses++;
    }
  }

  // Game over
  if (num_incorrect_guesses < MAX_ATTEMPTS) {
    printf("Congratulations, you guessed the word '%s' in %d attempts!\n", word, num_guesses);
  } else {
    printf("Sorry, you couldn't guess the word '%s' within the allowed attempts.\n", word);
  }

  return 0;
}