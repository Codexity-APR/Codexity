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
  srand((unsigned int)time(NULL));

  // Choose a random word from the list
  int word_index = rand() % num_words;
  strncpy(word, word_list[word_index], MAX_WORD_LENGTH);
  word_length = strlen(word);

  // Initialize guessed_letters array
  for (i = 0; i < MAX_WORD_LENGTH; i++) {
    guessed_letters[i] = ' ';
  }
  
  // Game loop
  while (num_incorrect_guesses < MAX_ATTEMPTS) {
    // Draw the hangman
    draw_hangman(num_incorrect_guesses);

    // Print the word with underscores for unguessed letters
    for (i = 0; i < word_length; i++) {
      if (guessed_letters[i] == ' ' || guessed_letters[i] != word[i]) {
        printf("_ ");
      } else {
        printf("%c ", word[i]);
      }
    }
    printf("\n");

    // Check if the player has won
    int all_letters_found = 1;
    for (i = 0; i < word_length; i++) {
      if (guessed_letters[i] == ' ' || guessed_letters[i] != word[i]) {
        all_letters_found = 0;
        break;
      }
    }
    if (all_letters_found) {
      printf("Congratulations, you won!\n");
      return 0;
    }

    // Get a guess from the user
    char guess;
    printf("Guess a letter: ");
    scanf(" %c", &guess);

    // Check if the guess is correct
    int correct_guess = 0;
    for (i = 0; i < word_length; i++) {
      if (word[i] == guess) {
        guessed_letters[i] = guess;
        correct_guess = 1;
      }
    }
    if (!correct_guess) {
      num_incorrect_guesses++;
    }
    num_guesses++;
  }

  // Draw the hangman one last time
  draw_hangman(num_incorrect_guesses);

  // Print the word
  for (i = 0; i < word_length; i++) {
    printf("%c ", word[i]);
  }
  printf("\n");

  // Print the game over message
  printf("Sorry, you lost. The word was %s.\n", word);

  return 0;
}