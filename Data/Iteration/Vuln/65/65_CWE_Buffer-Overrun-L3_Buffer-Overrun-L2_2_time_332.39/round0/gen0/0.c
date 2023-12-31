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
  strcpy(word, word_list[word_index]);
  word_length = strlen(word);

  // Initialize the guessed letters array
  for (i = 0; i < word_length; i++) {
    guessed_letters[i] = '_';
  }
  guessed_letters[word_length] = '\0';

  // Game loop
  while (num_incorrect_guesses < MAX_ATTEMPTS && strcmp(word, guessed_letters) != 0) {
    // Print the hangman drawing
    draw_hangman(num_incorrect_guesses);

    // Print the guessed letters
    printf("Guessed letters: %s\n", guessed_letters);

    // Prompt for a letter guess
    char guess;
    printf("Enter a letter guess: ");
    scanf(" %c", &guess);

    // Check if the letter has already been guessed
    int already_guessed = 0;
    for (i = 0; i < word_length; i++) {
      if (guess == guessed_letters[i]) {
        already_guessed = 1;
        break;
      }
    }

    if (already_guessed) {
      printf("You've already guessed that letter!\n");
    } else {
      // Check if the letter is in the word
      int found_letter = 0;
      for (i = 0; i < word_length; i++) {
        if (guess == word[i]) {
          guessed_letters[i] = guess;
          found_letter = 1;
        }
      }

      if (found_letter) {
        printf("Correct guess!\n");
      } else {
        printf("Incorrect guess!\n");
        num_incorrect_guesses++;
      }

      num_guesses++;
    }

    printf("\n");
  }

  // Print the final hangman drawing
  draw_hangman(num_incorrect_guesses);

  // Print the guessed letters
  printf("Guessed letters: %s\n", guessed_letters);

  // Check if the player won or lost
  if (num_incorrect_guesses == MAX_ATTEMPTS) {
    printf("You lost! The word was: %s\n", word);
  } else {
    printf("Congratulations! You won in %d guesses.\n", num_guesses);
  }

  return 0;
}