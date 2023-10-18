#include <stdio.h>

int ambil_nilai() {
    int nilai, NMK; 
    printf("Masukkan mata kuliah yang ingin dicari analisa nya:\n");
    scanf("%d", &NMK);
    printf("Masukkan nilai mata kuliahnya:\n");
    scanf("%d", &nilai);
    if (nilai <= 50) {
        printf("kamu harus belajar lagi karena nilai kamu kurang\n\n");
    }
    else if (nilai <= 70) {
        printf("nilai kamu cukup, tapi masih perlu perbaikan\n\n");
    }
    else if (nilai <= 85) {
        printf("nilai kamu bagus, tetapi bisa lebih baik lagi\n\n");
    }
    else {
        printf("nilai kamu sangat baik, pertahankan!\n\n");
    }
}

int main() {
    ambil_nilai();
    return 0;
}