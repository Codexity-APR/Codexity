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
  char guessed_letters[MAX_WORD_LENGTH] = {'\0'};
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
  
  // Copy the word into the word array
  strcpy(word, word_list[word_index]);
  word_length = strlen(word);
  
  // Loop until the player guesses the word or runs out of guesses
  while (num_guesses < MAX_ATTEMPTS && num_incorrect_guesses < MAX_ATTEMPTS) {
    // Draw the hangman
    draw_hangman(num_incorrect_guesses);

    // Print the word so far
    printf("Word: ");
    for (i = 0; i < word_length; i++) {
      if (guessed_letters[i] == '\0') {
        printf("_ ");
      } else {
        printf("%c ", guessed_letters[i]);
      }
    }
    printf("\n");

    // Print the number of guesses so far
    printf("Guesses: %d\n", num_guesses);

    // Get the next guess from the player
    char guess;
    printf("Guess a letter: ");
    scanf(" %c", &guess);
    getchar();

    // Check if the guess is in the word
    int found_letter = 0;
    for (i = 0; i < word_length; i++) {
      if (guess == word[i]) {
        found_letter = 1;
        guessed_letters[i] = guess;
      }
    }

    // Check if the guess is correct
    if (found_letter) {
      printf("Correct!\n");
    } else {
      printf("Incorrect!\n");
      num_incorrect_guesses++;
    }

    // Check if the player has guessed the word
    int found_word = 1;
    for (i = 0; i < word_length; i++) {
      if (guessed_letters[i] == '\0') {
        found_word = 0;
      }
    }

    if (found_word) {
      printf("You win!\n");
      break;
    }

    num_guesses++;
  }

  // Draw the hangman
  draw_hangman(num_incorrect_guesses);

  // Print the word
  printf("Word: ");
  for (i = 0; i < word_length; i++) {
    printf("%c ", guessed_letters[i]);
  }
  printf("\n");

  // Print the number of guesses
  printf("Guesses: %d\n", num_guesses);

  // Print the number of incorrect guesses
  printf("Incorrect guesses: %d\n", num_incorrect_guesses);

  return 0;
}