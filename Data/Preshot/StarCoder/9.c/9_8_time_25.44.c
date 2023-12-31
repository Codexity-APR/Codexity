#include <stdio.h>

int ambil_nilai() {
    int nilai, NMK;
    printf("Masukkan mata kuliah yang ingin dicari analisa nya:\n");
    scanf("%d", &NMK);
    printf("Masukkan nilai mata kuliahnya:\n");
    scanf("%d", &nilai);

    if (nilai < 0 || nilai > 100) {
        printf("Nilai tidak sesuai, silahkan masukkan nilai dalam rentang 0-100.\n\n");
    } else if (nilai <= 50) {
        printf("Kamu harus belajar lagi karena nilai kamu kurang.\n\n");
    } else if (nilai <= 60) {
        printf("Kamu harus belajar lagi karena nilai kamu cukup.\n\n");
    } else if (nilai <= 70) {
        printf("Kamu sudah cukup bagus, tapi tetap perlu belajar lagi.\n\n");
    } else if (nilai <= 80) {
        printf("Kamu bagus, tapi masih bisa lebih baik lagi.\n\n");
    } else if (nilai <= 90) {
        printf("Kamu sangat bagus, terus pertahankan!\n\n");
    } else {
        printf("Kamu hebat sekali! Pertahankan prestasimu.\n\n");
    }

    return nilai;
}

int main() {
    ambil_nilai();
    return 0;
}