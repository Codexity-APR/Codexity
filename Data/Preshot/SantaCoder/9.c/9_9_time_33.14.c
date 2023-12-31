#include <stdio.h>

int ambil_nilai() {
    int nilai, NMK; 
    printf("Masukkan mata kuliah yang ingin dicari analisa nya:\n");
    scanf("%d", &NMK);
    printf("Masukkan nilai mata kuliahnya:\n");
    scanf("%d", &nilai);
    if (nilai <= 50) {
        printf("kamu harus belajar lagi karena nilai kamu kurang\n\n");
        return 1;
    } else if (nilai <= 70) {
        printf("nilai kamu cukup, kamu bisa lebih baik lagi\n\n");
        return 2;
    } else if (nilai <= 80) {
        printf("nilai kamu bagus, pertahankan!\n\n");
        return 3;
    } else {
        printf("nilai kamu sangat bagus, selamat!\n\n");
        return 4;
    }
}