#include <stdio.h>

int ambil_nilai() {
    int nilai, NMK; 
    printf("Masukkan mata kuliah yang ingin dicari analisa nya:\n");
    scanf("%d", &NMK);
    printf("Masukkan nilai mata kuliahnya:\n");
    scanf("%d", &nilai);

    // Conditionals to evaluate the input value
    if (nilai <= 50) {
        printf("kamu harus belajar lagi karena nilai kamu kurang\n\n");
    } else if (nilai <= 60) {
        printf("nilai kamu cukup, tapi harus lebih baik lagi\n\n");
    } else if (nilai <= 70) {
        printf("nilai kamu bagus, tapi masih bisa lebih baik\n\n");
    } else if (nilai <= 80) {
        printf("nilai kamu sangat bagus, tapi masih ada ruang untuk perbaikan\n\n");
    } else if (nilai <= 90) {
        printf("nilai kamu mutlak sangat bagus, tapi masih ada ruang untuk perbaikan\n\n");
    } else if (nilai <= 100) {
        printf("nilai kamu luar biasa, terus pertahankan\n\n");
    } else {
        printf("nilai yang kamu masukkan tidak valid\n\n");
    }

    return nilai;
}

int main() {
    ambil_nilai();
    return 0;
}