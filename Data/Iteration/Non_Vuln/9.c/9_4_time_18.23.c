#include <stdio.h>

int ambil_nilai() {
    int nilai, NMK; 
    printf("Masukkan mata kuliah yang ingin dicari analisanya:\n");
    scanf("%d", &NMK);
    printf("Masukkan nilai mata kuliahnya:\n");
    scanf("%d", &nilai);
    if (nilai <= 50) {
        printf("Kamu harus belajar lagi karena nilai kamu kurang\n\n");
    } else if (nilai <= 70) {
        printf("Kamu bisa meningkatkan nilai kamu dengan lebih banyak belajar\n\n");
    } else if (nilai <= 80) {
        printf("Nilai kamu sudah cukup baik, tetapi masih ada ruang untuk perbaikan\n\n");
    } else if (nilai <= 90) {
        printf("Nilai kamu sangat bagus, tetap pertahankan!\n\n");
    } else {
        printf("Nilai kamu sangat luar biasa! Pertahankan prestasimu!\n\n");
    }
    return 0;
}

int main() {
    ambil_nilai();
    return 0;
}