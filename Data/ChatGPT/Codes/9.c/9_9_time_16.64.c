#include <stdio.h>

int ambil_nilai() {
    int nilai, NMK; 
    printf("Masukkan mata kuliah yang ingin dicari analisa nya:\n");
    scanf("%d", &NMK);
    printf("Masukkan nilai mata kuliahnya:\n");
    scanf("%d", &nilai);
    if (nilai <= 50) {
        printf("Kamu harus belajar lagi karena nilai kamu kurang\n\n");
    } else if (nilai > 50 && nilai <= 70) {
        printf("Nilai kamu cukup, tetapi perlu lebih banyak usaha\n\n");
    } else if (nilai > 70 && nilai <= 85) {
        printf("Nilai kamu bagus, tapi masih ada ruang untuk peningkatan\n\n");
    } else {
        printf("Nilai kamu sangat baik, pertahankan!\n\n");
    }
    return 0;
}

int main() {
    ambil_nilai();
    return 0;
}