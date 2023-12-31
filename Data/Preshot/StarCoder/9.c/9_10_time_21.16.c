#include <stdio.h>

void ambil_nilai() {
    int nilai, NMK; 
    printf("Masukkan mata kuliah yang ingin dicari analisa nya:\n");
    scanf("%d", &NMK);
    printf("Masukkan nilai mata kuliahnya:\n");
    scanf("%d", &nilai);
    if (nilai <= 50) {
        printf("Kamu harus belajar lagi karena nilai kamu kurang.\n\n");
    } else if (nilai <= 60) {
        printf("Kamu perlu memperbaiki nilai kamu.\n\n");
    } else if (nilai <= 70) {
        printf("Kamu perlu lebih banyak belajar.\n\n");
    } else if (nilai <= 80) {
        printf("Kamu sudah cukup baik.\n\n");
    } else if (nilai <= 90) {
        printf("Kamu sudah sangat baik.\n\n");
    } else {
        printf("Kamu sangat luar biasa!\n\n");
    }
}

int main() {
    ambil_nilai();
    return 0;
}