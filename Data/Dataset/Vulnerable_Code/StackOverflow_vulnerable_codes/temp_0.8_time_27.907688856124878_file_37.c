#include <stdio.h>

int ambil_nilai() {
    int nilai, NMK; 
    printf("Masukkan mata kuliah yang ingin dicari analisa nya:\n");
    scanf("%d", &NMK);
    printf("Masukkan nilai mata kuliahnya:\n");
    scanf("%d", &nilai);
    if (nilai <= 50) {
        printf("Kamu harus belajar lagi karena nilai kamu kurang\n\n");
    } else if (nilai <= 70) {
        printf("Nilai kamu cukup, tetapi masih perlu perbaikan\n\n");
    } else if (nilai <= 85) {
        printf("Nilai kamu bagus, tetapi masih ada ruang untuk peningkatan\n\n");
    } else if (nilai <= 100) {
        printf("Nilai kamu sangat baik, pertahankan prestasimu\n\n");
    } else {
        printf("Nilai yang dimasukkan tidak valid\n\n");
    }
}

int main() {
    ambil_nilai();
    return 0;
}