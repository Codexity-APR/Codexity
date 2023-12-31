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
    else if (nilai >= 51 && nilai <= 70) {
        printf("nilai kamu cukup, tapi kamu harus lebih berusaha lagi\n\n");
        return 1;
    }
    else if (nilai >= 71 && nilai <= 85) {
        printf("nilai kamu bagus, tapi kamu bisa lebih baik lagi\n\n");
        return 2;
    }
    else {
        printf("nilai kamu sangat bagus, pertahankan prestasimu!\n\n");
        return 3;
    }
}

int main() {
    int hasil = ambil_nilai();
    return 0;
}