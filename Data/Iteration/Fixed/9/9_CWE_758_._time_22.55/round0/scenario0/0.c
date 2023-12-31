List of vulnerabilities detected: 
 Error type: CWE-758 at line: 12. Error message: Found a exit path from function with non-void return type that has missing return statement


#include <stdio.h>
int ambil_nilai() {
    int nilai, NMK; 
    printf("Masukkan mata kuliah yang ingin dicari analisa nya:\n");
    scanf("%d", &NMK);
    printf("Masukkan nilai mata kuliahnya:\n");
    scanf("%d", &nilai);
    if (nilai <= 50) {
        printf("kamu harus belajar lagi karena nilai kamu kurang\n\n");
    } else {
        printf("nilai kamu sudah cukup baik\n\n");
    }
}
int main() {
    ambil_nilai();
    return 0;
}