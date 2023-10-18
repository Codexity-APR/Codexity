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

  // Initialize guessed_letters array
  for (i = 0; i < word_length; i++) {
    guessed_letters[i] = '_';
  }
  guessed_letters[word_length] = '\0';

  // Game loop
  while (num_incorrect_guesses < MAX_ATTEMPTS && strcmp(word, guessed_letters) != 0) {
    // Print current state of guessed word
    printf("Guessed word: %s\n", guessed_letters);

    // Get user input
    char guess;
    printf("Enter a letter: ");
    scanf(" %c", &guess);

    // Check if letter has already been guessed
    int already_guessed = 0;
    for (i = 0; i < word_length; i++) {
      if (guessed_letters[i] == guess) {
        already_guessed = 1;
        break;
      }
    }

    if (already_guessed) {
      printf("You already guessed that letter!\n");
      continue;
    }

    // Check if guess is correct
    int found = 0;
    for (i = 0; i < word_length; i++) {
      if (word[i] == guess) {
        guessed_letters[i] = guess;
        found = 1;
      }
    }

    if (found) {
      printf("Correct guess!\n");
    } else {
      printf("Incorrect guess!\n");
      num_incorrect_guesses++;
    }

    num_guesses++;
  }

  // Game over
  if (num_incorrect_guesses == MAX_ATTEMPTS) {
    printf("You lose! The word was: %s\n", word);
  } else {
    printf("Congratulations! You guessed the word: %s\n", word);
  }

  return 0;
}