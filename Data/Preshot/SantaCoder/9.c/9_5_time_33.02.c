#include <stdio.h>

int ambil_nilai() {
    int nilai, NMK; 
    printf("Masukkan mata kuliah yang ingin dicari analisa nya:\n");
    scanf("%d", &NMK);
    printf("Masukkan nilai mata kuliahnya:\n");
    scanf("%d", &nilai);
    if (nilai <= 50) {
        printf("Kamu harus belajar lagi karena nilai kamu kurang\n\n");
        return 0;
    } else if (nilai > 50 && nilai <= 70) {
        printf("Kamu harus memperbaiki nilai kamu agar lebih baik lagi\n\n");
        return 1;
    } else if (nilai > 70 && nilai <= 85) {
        printf("Nilai kamu sudah baik, tetapi masih ada ruang untuk perbaikan\n\n");
        return 2;
    } else {
        printf("Nilai kamu sangat bagus, pertahankan dan tingkatkan lagi prestasimu!\n\n");
        return 3;
    }
}