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

  // Initialize guessed_letters array with dashes
  for (i = 0; i < word_length; i++) {
    guessed_letters[i] = '-';
  }
  guessed_letters[word_length] = '\0';

  // Game loop
  while (num_incorrect_guesses < MAX_ATTEMPTS && strcmp(word, guessed_letters) != 0) {
    // Print hangman and guessed letters
    draw_hangman(num_incorrect_guesses);
    printf("Guessed letters: %s\n", guessed_letters);

    // Get user input
    char guess;
    printf("Enter a letter: ");
    scanf(" %c", &guess);

    // Check if the letter has already been guessed
    int already_guessed = 0;
    for (i = 0; i < word_length; i++) {
      if (guessed_letters[i] == guess) {
        already_guessed = 1;
        break;
      }
    }

    // Process the guess
    if (already_guessed) {
      printf("You already guessed that letter!\n");
    } else {
      int found_letter = 0;
      for (i = 0; i < word_length; i++) {
        if (word[i] == guess) {
          guessed_letters[i] = guess;
          found_letter = 1;
        }
      }

      if (found_letter) {
        printf("Good guess!\n");
      } else {
        num_incorrect_guesses++;
        printf("Wrong guess!\n");
      }
    }

    num_guesses++;
  }

  // Print hangman and guessed letters one last time
  draw_hangman(num_incorrect_guesses);
  printf("Guessed letters: %s\n", guessed_letters);

  // Print game result
  if (num_incorrect_guesses >= MAX_ATTEMPTS) {
    printf("You lost! The word was: %s\n", word);
  } else {
    printf("Congratulations! You guessed the word in %d attempts.\n", num_guesses);
  }

  return 0;
}