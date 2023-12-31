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

  // Game loop
  while (num_incorrect_guesses < MAX_ATTEMPTS && strcmp(word, guessed_letters) != 0) {
    draw_hangman(num_incorrect_guesses);
    printf("Guessed letters: %s\n", guessed_letters);
    printf("Enter a letter: ");
    char guess;
    scanf(" %c", &guess);

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

  if (strcmp(word, guessed_letters) == 0) {
    printf("Congratulations! You guessed the word '%s' in %d attempts.\n", word, num_guesses);
  } else {
    draw_hangman(num_incorrect_guesses);
    printf("Sorry, you ran out of attempts. The word was '%s'. Better luck next time!\n", word);
  }

  return 0;
}