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
  srand(time(NULL));

  // Choose a random word from the list
  int word_index = rand() % num_words;
  word_length = strlen(word_list[word_index]);
  strncpy(word, word_list[word_index], MAX_WORD_LENGTH);
  word[word_length] = '\0';

  // Initialize guessed letters to underscores
  for (i = 0; i < word_length; i++) {
    guessed_letters[i] = '_';
  }
  guessed_letters[word_length] = '\0';

  // Game loop
  while (num_incorrect_guesses < MAX_ATTEMPTS && strcmp(word, guessed_letters) != 0) {
    printf("Current word: %s\n", guessed_letters);
    printf("Enter a letter: ");
    char input;
    scanf(" %c", &input);

    // Check if the input is a valid letter
    if ((input < 'a' || input > 'z') && (input < 'A' || input > 'Z')) {
      printf("Invalid input. Please enter a letter.\n");
      continue;
    }

    // Check if the letter has already been guessed
    int already_guessed = 0;
    for (i = 0; i < word_length; i++) {
      if (guessed_letters[i] == input) {
        already_guessed = 1;
        break;
      }
    }
    if (already_guessed) {
      printf("You have already guessed that letter.\n");
      continue;
    }

    // Check if the input letter is in the word
    int found = 0;
    for (i = 0; i < word_length; i++) {
      if (word[i] == input) {
        guessed_letters[i] = input;
        found = 1;
      }
    }

    // Update the number of incorrect guesses
    if (!found) {
      num_incorrect_guesses++;
      draw_hangman(num_incorrect_guesses);
    }
    num_guesses++;
  }

  // Game over
  if (strcmp(word, guessed_letters) == 0) {
    printf("Congratulations! You guessed the word \"%s\" in %d guesses.\n", word, num_guesses);
  } else {
    printf("You failed to guess the word \"%s\". Game over.\n", word);
  }

  return 0;
}