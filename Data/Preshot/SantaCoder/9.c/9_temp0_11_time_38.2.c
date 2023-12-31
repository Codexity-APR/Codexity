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
    else if (nilai > 50 && nilai <= 70) {
        printf("nilai kamu cukup, tapi masih perlu ditingkatkan lagi\n\n");
        return 1;
    }
    else if (nilai > 70 && nilai <= 85) {
        printf("nilai kamu bagus, tapi masih ada ruang untuk ditingkatkan\n\n");
        return 2;
    }
    else {
        printf("nilai kamu sangat bagus, pertahankan dan tingkatkan lagi\n\n");
        return 3;
    }
}