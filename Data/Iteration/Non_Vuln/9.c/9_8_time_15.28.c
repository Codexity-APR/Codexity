#include <stdio.h>

int ambil_nilai() {
    int nilai, NMK; 
    printf("Masukkan mata kuliah yang ingin dicari analisa nya:\n");
    scanf("%d", &NMK);
    printf("Masukkan nilai mata kuliahnya:\n");
    scanf("%d", &nilai);
    if (nilai <= 50) {
        printf("Kamu harus belajar lagi karena nilai kamu kurang\n\n");
    }
    else {
        printf("Nilai kamu sudah cukup baik. Tetap pertahankan!\n\n");
    }
    return 0;
}

int main() {
    ambil_nilai();
    return 0;
}