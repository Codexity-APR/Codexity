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
  word[MAX_WORD_LENGTH - 1] = '\0';

  // Initialize the guessed letters array with dashes
  word_length = strlen(word);
  for (i = 0; i < word_length; i++) {
    guessed_letters[i] = '-';
  }
  guessed_letters[word_length] = '\0';

  // Game loop
  while (num_incorrect_guesses < MAX_ATTEMPTS && strcmp(word, guessed_letters) != 0) {
    // Print hangman
    draw_hangman(num_incorrect_guesses);

    // Print word with guessed letters
    printf("Word: %s\n", guessed_letters);

    // Prompt for a letter
    printf("Enter a letter: ");
    char letter;
    scanf(" %c", &letter);

    // Check if the letter is in the word
    int found = 0;
    for (i = 0; i < word_length; i++) {
      if (word[i] == letter) {
        guessed_letters[i] = letter;
        found = 1;
      }
    }

    // Update the number of incorrect guesses
    if (!found) {
      num_incorrect_guesses++;
    }

    // Increase the number of guesses
    num_guesses++;
  }

  // Print final hangman and result
  draw_hangman(num_incorrect_guesses);
  printf("Word: %s\n", guessed_letters);

  if (num_incorrect_guesses == MAX_ATTEMPTS) {
    printf("You lost!\n");
  } else {
    printf("Congratulations! You won in %d guesses.\n", num_guesses);
  }

  return 0;
}