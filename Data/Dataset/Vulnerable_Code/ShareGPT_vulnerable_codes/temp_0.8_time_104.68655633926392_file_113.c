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

  // Initialize guessed_letters array with underscores
  for (i = 0; i < word_length; i++) {
    guessed_letters[i] = '_';
  }
  guessed_letters[word_length] = '\0';

  while (num_incorrect_guesses < MAX_ATTEMPTS && strcmp(word, guessed_letters) != 0) {
    // Print the current state of the game
    printf("\nWord: %s\n", guessed_letters);
    printf("Attempts remaining: %d\n", MAX_ATTEMPTS - num_incorrect_guesses);
    draw_hangman(num_incorrect_guesses);

    // Prompt the user for a letter
    char guess;
    printf("Enter your guess: ");
    scanf(" %c", &guess);

    // Check if the letter has already been guessed
    int already_guessed = 0;
    for (i = 0; i < word_length; i++) {
      if (guessed_letters[i] == guess) {
        already_guessed = 1;
        break;
      }
    }

    if (already_guessed) {
      printf("You already guessed that letter! Try again.\n");
      continue;
    }

    // Check if the letter is in the word
    int found = 0;
    for (i = 0; i < word_length; i++) {
      if (word[i] == guess) {
        guessed_letters[i] = guess;
        found = 1;
      }
    }

    if (found) {
      printf("Good guess!\n");
    } else {
      printf("Incorrect guess!\n");
      num_incorrect_guesses++;
    }
  }

  // Print the final state of the game
  printf("\nWord: %s\n", guessed_letters);
  draw_hangman(num_incorrect_guesses);

  // Check if the player won or lost
  if (num_incorrect_guesses >= MAX_ATTEMPTS) {
    printf("Game over! You lost. The word was: %s\n", word);
  } else {
    printf("Congratulations! You won!\n");
  }

  return 0;
}