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
  word_length = strlen(word_list[word_index]);
  strncpy(word, word_list[word_index], MAX_WORD_LENGTH);
  word[MAX_WORD_LENGTH - 1] = '\0';

  // Initialize guessed_letters array
  for (i = 0; i < word_length; i++) {
    guessed_letters[i] = '_';
  }
  guessed_letters[word_length] = '\0';

  // Print initial state of the game
  printf("Welcome to Hangman!\n");
  printf("Guess the word: %s\n", guessed_letters);

  // Game loop
  while (num_incorrect_guesses < MAX_ATTEMPTS) {
    char guess;
    int letter_found = 0;

    printf("Enter your guess: ");
    scanf(" %c", &guess);

    // Check if the guessed letter is present in the word
    for (i = 0; i < word_length; i++) {
      if (word[i] == guess) {
        guessed_letters[i] = guess;
        letter_found = 1;
      }
    }

    if (!letter_found) {
      num_incorrect_guesses++;
      printf("Incorrect guess! You have %d attempts remaining.\n", MAX_ATTEMPTS - num_incorrect_guesses);
    }

    printf("Word: %s\n", guessed_letters);

    // Check if the word has been guessed correctly
    if (strcmp(word, guessed_letters) == 0) {
      printf("Congratulations! You guessed the word correctly!\n");
      break;
    }

    // Check if the maximum number of attempts has been reached
    if (num_incorrect_guesses == MAX_ATTEMPTS) {
      printf("Game over! You have exceeded the maximum number of attempts.\n");
      printf("The word was: %s\n", word);
      break;
    }

    num_guesses++;
  }

  return 0;
}