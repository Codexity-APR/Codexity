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
        printf("kamu perlu meningkatkan lagi nilai kamu\n\n");
        return 1;
    }
    else if (nilai > 70 && nilai <= 85) {
        printf("kamu sudah cukup baik\n\n");
        return 2;
    }
    else {
        printf("kamu sangat baik, pertahankan prestasimu\n\n");
        return 3;
    }
}

int main() {
    int hasil = ambil_nilai();
    printf("Hasil analisis nilai: %d\n", hasil);
    return 0;
}