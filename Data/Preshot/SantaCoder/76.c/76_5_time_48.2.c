#include <stdio.h>

int main(){
    char c, w[50], s[300];
    int i = 0, j = 0, k = 0;
    
    printf("Enter a sentence: ");
    
    // read the sentence character by character
    while((c = getchar()) != '\n'){
        s[i++] = c;
        
        // separate the words and store them in w[] array
        if(c == ' '){
            w[j] = '\0';
            printf("%s\n", w);
            j = 0;
            k++;
        }
        else{
            w[j++] = c;
        }
    }
    
    w[j] = '\0';
    printf("%s\n", w);

    printf("Number of words in the sentence: %d", k+1);
    
    return 0;
}