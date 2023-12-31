List of vulnerabilities detected: 
Error: Buffer Overrun L3   Offset: [-5, 5] Size: 6.
 Example: 
  31.   // Choose a random word from the list
  32.   int word_index = rand() % num_words;
  33.   strcpy(word, word_list[word_index]);
                     ^
  34.   word_length = strlen(word);
  35.

Error: Buffer Overrun L2   Offset: [4, 10] Size: 5.
 Example: 
  31.   // Choose a random word from the list
  32.   int word_index = rand() % num_words;
  33.   strcpy(word, word_list[word_index]);
        ^
  34.   word_length = strlen(word);
  35.


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
  // Initialize guessed_letters array
  for (i = 0; i < word_length; i++) {
    guessed_letters[i] = '_';
  }
  guessed_letters[word_length] = '\0';
  printf("Welcome to Hangman!\n");
  printf("Guess the word by entering letters. You have %d attempts.\n", MAX_ATTEMPTS);
  while (num_incorrect_guesses < MAX_ATTEMPTS && strcmp(guessed_letters, word) != 0) {
    printf("\nWord: %s\n", guessed_letters);
    char guess;
    printf("Enter a letter: ");
    scanf(" %c", &guess);
    int found = 0;
    for (i = 0; i < word_length; i++) {
      if (word[i] == guess) {
        guessed_letters[i] = guess;
        found = 1;
      }
    }
    if (found) {
      printf("Correct guess!\n");
    } else {
      printf("Incorrect guess!\n");
      num_incorrect_guesses++;
    }
    num_guesses++;
  }
  printf("\n");
  if (strcmp(guessed_letters, word) == 0) {
    printf("Congratulations! You guessed the word '%s' in %d attempts.\n", word, num_guesses);
  } else {
    printf("Game over! You failed to guess the word '%s'. The correct word was '%s'.\n", word, word_list[word_index]);
  }
  return 0;
}