#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ATTEMPTS 6
#define MAX_WORD_LENGTH 20

int main() {
  char word[MAX_WORD_LENGTH + 1];
  char guessed_letters[MAX_WORD_LENGTH + 1];
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
  strncpy(word, word_list[word_index], MAX_WORD_LENGTH);
  word[MAX_WORD_LENGTH] = '\0';
  word_length = strlen(word);

  // Initialize guessed_letters array with dashes
  for (i = 0; i < word_length; i++) {
    guessed_letters[i] = '-';
  }
  guessed_letters[word_length] = '\0';

  // Game loop
  while (num_guesses < MAX_ATTEMPTS && strcmp(word, guessed_letters) != 0) {
    printf("Guess a letter: ");
    char guess;
    scanf(" %c", &guess);

    // Check if the guessed letter is in the word
    int found = 0;
    for (i = 0; i < word_length; i++) {
      if (word[i] == guess) {
        guessed_letters[i] = guess;
        found = 1;
      }
    }

    if (!found) {
      num_incorrect_guesses++;
    }
    num_guesses++;

    printf("Guessed letters: %s\n", guessed_letters);
    printf("Incorrect guesses: %d/%d\n", num_incorrect_guesses, MAX_ATTEMPTS);
  }

  // Check if the player won or lost
  if (strcmp(word, guessed_letters) == 0) {
    printf("Congratulations, you guessed the word correctly!\n");
  } else {
    printf("Sorry, you ran out of attempts. The word was %s.\n", word);
  }

  return 0;
}