
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ATTEMPTS 6
#define MAX_WORD_LENGTH 20

void draw_hangman(int num_incorrect_guesses) {
  printf("   +----+\n");
  printf("   |    |\n");
  printf("   |    %c\n", num_incorrect_guesses >= 1 ? 'O' : ' ');
  printf("   |   %c%c%c\n", num_incorrect_guesses >= 3 ? '/' : ' ', num_incorrect_guesses >= 2 ? '|' : ' ', num_incorrect_guesses >= 4 ? '\\' : ' ');
  printf("   |   %c %c\n", num_incorrect_guesses >= 5 ? '/' : ' ', num_incorrect_guesses >= 6 ? '\\' : ' ');
  printf("=======\n");
}

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
      printf("\n\n");
      draw_hangman(num_incorrect_guesses);
      printf("Word: %s\n", guessed_letters);
      printf("Guesses: %d/%d\n", num_guesses, MAX_ATTEMPTS);

      // Get the user's guess
      char guess;
      printf("Enter a letter: ");
      scanf(" %c", &guess);

      // Check if the guess is correct
      int found = 0;
      for (i = 0; i < word_length; i++) {
        if (word[i] == guess) {
          guessed_letters[i] = guess;
          found = 1;
        }
      }

      // Update the game state based on the guess
      if (found) {
        printf("Correct!\n");
      } else {
        printf("Incorrect.\n");
        num_incorrect_guesses++;
      }
      num_guesses++;
    }

    // Print the final state of the game
    printf("\n\n");
    draw_hangman(num_incorrect_guesses);
    printf("Word: %s\n", guessed_letters);
    printf("Guesses: %d/%d\n", num_guesses, MAX_ATTEMPTS);
    if (num_incorrect_guesses >= MAX_ATTEMPTS) {
      printf("You lose! The word was %s.\n", word);
    } else {
      printf("You win!\n");
    }

    return 0;
  }
