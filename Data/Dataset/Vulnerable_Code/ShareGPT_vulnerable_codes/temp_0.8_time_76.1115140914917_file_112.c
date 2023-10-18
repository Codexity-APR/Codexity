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
  strcpy(word, word_list[word_index]);
  word_length = strlen(word);

  // Initialize guessed letters with spaces
  for (i = 0; i < word_length; i++) {
    guessed_letters[i] = ' ';
  }
  guessed_letters[word_length] = '\0';

  // Game loop
  while (num_incorrect_guesses < MAX_ATTEMPTS && strcmp(word, guessed_letters) != 0) {
    char guess;

    // Print current state of the word
    printf("Word: %s\n", guessed_letters);
    printf("Incorrect guesses: %d/%d\n", num_incorrect_guesses, MAX_ATTEMPTS);

    // Get user input
    printf("Enter a letter: ");
    scanf(" %c", &guess);

    // Check if the letter has already been guessed
    if (strchr(guessed_letters, guess) != NULL) {
      printf("You already guessed that letter.\n");
      continue;
    }

    // Update guessed letters
    for (i = 0; i < word_length; i++) {
      if (word[i] == guess) {
        guessed_letters[i] = guess;
      }
    }

    // Check if the guess was correct
    if (strchr(word, guess) == NULL) {
      num_incorrect_guesses++;
    }

    // Increase the number of guesses
    num_guesses++;
  }

  // Print end-of-game message
  if (num_incorrect_guesses >= MAX_ATTEMPTS) {
    printf("You lost! The word was %s.\n", word);
  } else {
    printf("Congratulations! You guessed the word %s in %d attempts.\n", word, num_guesses);
  }

  return 0;
}