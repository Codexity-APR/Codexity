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
  word[MAX_WORD_LENGTH] = '\0';

  // Initialize guessed letters array with dashes
  for (i = 0; i < word_length; i++) {
    guessed_letters[i] = '-';
  }
  guessed_letters[word_length] = '\0';

  // Game loop
  while (num_incorrect_guesses < MAX_ATTEMPTS && strcmp(word, guessed_letters) != 0) {
    // Print current state of the word
    printf("Word: %s\n", guessed_letters);

    // Get user's guess
    char guess;
    printf("Enter a letter: ");
    scanf(" %c", &guess);

    // Check if the letter has already been guessed
    if (strchr(guessed_letters, guess) != NULL) {
      printf("You already guessed that letter!\n");
      continue;
    }

    // Update guessed letters and check if the guess is correct
    int is_correct_guess = 0;
    for (i = 0; i < word_length; i++) {
      if (word[i] == guess) {
        guessed_letters[i] = guess;
        is_correct_guess = 1;
      }
    }

    // Update number of guesses and incorrect guesses
    num_guesses++;
    if (is_correct_guess == 0) {
      num_incorrect_guesses++;
    }

    printf("\n");

    // Print hangman ASCII art based on the number of incorrect guesses
    switch (num_incorrect_guesses) {
      case 1:
        printf("    ________\n"
               "   |        |\n"
               "   |        O\n"
               "   |\n"
               "   |\n"
               "   |\n"
               "___|___\n\n");
        break;
      case 2:
        printf("    ________\n"
               "   |        |\n"
               "   |        O\n"
               "   |        |\n"
               "   |\n"
               "   |\n"
               "___|___\n\n");
        break;
      case 3:
        printf("    ________\n"
               "   |        |\n"
               "   |        O\n"
               "   |       /|\n"
               "   |\n"
               "   |\n"
               "___|___\n\n");
        break;
      case 4:
        printf("    ________\n"
               "   |        |\n"
               "   |        O\n"
               "   |       /|\\\n"
               "   |\n"
               "   |\n"
               "___|___\n\n");
        break;
      case 5:
        printf("    ________\n"
               "   |        |\n"
               "   |        O\n"
               "   |       /|\\\n"
               "   |       /\n"
               "   |\n"
               "___|___\n\n");
        break;
      case 6:
        printf("    ________\n"
               "   |        |\n"
               "   |        O\n"
               "   |       /|\\\n"
               "   |       / \\\n"
               "   |\n"
               "___|___\n\n");
        break;
    }
  }

  // Game over
  if (num_incorrect_guesses == MAX_ATTEMPTS) {
    printf("You lost! The word was %s.\n", word);
  } else {
    printf("Congratulations! You won with %d guesses.\n", num_guesses);
  }

  return 0;
}