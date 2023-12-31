#include <stdio.h>

int ambil_nilai() {
    int nilai, NMK; 
    printf("Masukkan mata kuliah yang ingin dicari analisa nya:\n");
    scanf("%d", &NMK);
    printf("Masukkan nilai mata kuliahnya:\n");
    scanf("%d", &nilai);
    if (nilai <= 50) {
        printf("kamu harus belajar lagi karena nilai kamu kurang\n\n");
        return 0;
    } else if (nilai > 50 && nilai <= 75) {
        printf("nilai kamu cukup, tapi tetap perlu lebih banyak belajar\n\n");
        return 1;
    } else if (nilai > 75 && nilai <= 85) {
        printf("nilai kamu bagus!\n\n");
        return 2;
    } else if (nilai > 85) {
        printf("nilai kamu sangat bagus, pertahankan!\n\n");
        return 3;
    }
    return -1;
}