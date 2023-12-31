#include <stdio.h>

int ambil_nilai() {
    int nilai, NMK; 
    printf("Masukkan mata kuliah yang ingin dicari analisa nya:\n");
    scanf("%d", &NMK);
    printf("Masukkan nilai mata kuliahnya:\n");
    scanf("%d", &nilai);
    if (nilai <= 50) {
        printf("kamu harus belajar lagi karena nilai kamu kurang\n\n");
        return 1; // indicating that the student needs to study more
    } else {
        printf("nilai kamu sudah bagus\n\n");
        return 0; // indicating that the student has a good grade
    }
}

int main() {
    int result = ambil_nilai();
    return 0;
}