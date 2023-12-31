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
    else if (nilai > 50 && nilai <= 70) {
        printf("kamu perlu meningkatkan pembelajaran kamu\n\n");
    }
    else if (nilai > 70 && nilai <= 85) {
        printf("kamu mendapatkan hasil yang cukup baik\n\n");
    }
    else if (nilai > 85) {
        printf("kamu memiliki hasil yang sangat baik\n\n");
    }
    return 0;
}

int main() {
    ambil_nilai();
    return 0;
}