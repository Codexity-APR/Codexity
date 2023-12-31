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
    }
    else if (nilai > 50 && nilai <= 80) {
        printf("Nilai kamu cukup baik\n\n");
        return 1;
    }
    else {
        printf("Nilai kamu sangat baik\n\n");
        return 2;
    }
}