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

  // Copy the chosen word into the 'word' array
  strcpy(word, word_list[word_index]);
  word_length = strlen(word);

  // Initialize the 'guessed_letters' array with dashes
  for (i = 0; i < word_length; i++) {
    guessed_letters[i] = '-';
  }
  guessed_letters[word_length] = '\0';

  // Game loop
  while (num_incorrect_guesses < MAX_ATTEMPTS && strcmp(word, guessed_letters) != 0) {
    // Print the current state of the game
    printf("Word: %s\n", guessed_letters);
    printf("Incorrect guesses remaining: %d\n", MAX_ATTEMPTS - num_incorrect_guesses);

    // Get a letter guess from the user
    char guess;
    printf("Enter your guess: ");
    scanf(" %c", &guess);

    // Check if the guessed letter is in the word
    int found = 0;
    for (i = 0; i < word_length; i++) {
      if (word[i] == guess) {
        guessed_letters[i] = guess;
        found = 1;
      }
    }

    // Update the game status based on the guess
    if (found) {
      printf("Correct guess!\n");
    } else {
      printf("Incorrect guess!\n");
      num_incorrect_guesses++;
    }

    // Increase the number of guesses
    num_guesses++;
  }

  // Print the final state of the game
  printf("Final word: %s\n", word);
  if (strcmp(word, guessed_letters) == 0) {
    printf("Congratulations! You guessed the word in %d guesses.\n", num_guesses);
  } else {
    printf("Game over! You have run out of attempts.\n");
  }

  return 0;
}