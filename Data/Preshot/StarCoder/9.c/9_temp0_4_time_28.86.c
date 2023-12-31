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
    else if (nilai > 50 && nilai <= 60) {
        printf("nilai kamu cukup, perlu lebih banyak belajar lagi\n\n");
    }
    else if (nilai > 60 && nilai <= 70) {
        printf("nilai kamu bagus, tapi masih perlu lebih banyak belajar lagi\n\n");
    }
    else if (nilai > 70 && nilai <= 80) {
        printf("nilai kamu sangat bagus, tapi masih perlu lebih banyak belajar lagi\n\n");
    }
    else if (nilai > 80 && nilai <= 90) {
        printf("nilai kamu mutlak sangat bagus, tapi masih perlu lebih banyak belajar lagi\n\n");
    }
    else if (nilai > 90 && nilai <= 100) {
        printf("nilai kamu sangat luar biasa, tapi masih perlu lebih banyak belajar lagi\n\n");
    }
    else {
        printf("nilai yang kamu masukkan tidak valid\n\n");
    }
    return nilai;
}

int main() {
    ambil_nilai();
    return 0;
}