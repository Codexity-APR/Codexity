#include <stdio.h>
#include <string.h>

#define MAX_W 50
#define MAX_S 300

int main(){
    char c, w[MAX_W+1], s[MAX_S+1];
	
	// Initialize variables
	memset(w, 0, sizeof(w));
	memset(s, 0, sizeof(s));
	
	// Get user input with field width limits
	printf("Enter a word (max %d characters): ", MAX_W);
	scanf("%" STR(MAX_W) "s", w);
	printf("Enter a string (max %d characters): ", MAX_S);
	scanf("%" STR(MAX_S) "s", s);

	// Find common letters
	for(int i = 0; i < strlen(w); i++){
		for(int j = 0; j < strlen(s); j++){
			if(w[i] == s[j]){
				printf("%c", w[i]);
			}
		}
	}
	
	return 0;
}