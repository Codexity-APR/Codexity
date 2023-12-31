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
        printf("Nilai kamu cukup, tapi kamu harus belajar lebih keras untuk mendapatkan nilai yang lebih baik\n\n");
    }
    else if (nilai > 60 && nilai <= 70) {
        printf("Nilai kamu sudah bagus, tapi kamu bisa memperbaiki nilai kamu lagi dengan lebih banyak belajar\n\n");
    }
    else if (nilai > 70 && nilai <= 80) {
        printf("Nilai kamu sangat bagus, tetapi tetap belajarlah dengan sungguh-sungguh untuk mendapatkan prestasi yang lebih baik lagi\n\n");
    }
    else if (nilai > 80 && nilai <= 90) {
        printf("Nilai kamu mutlak sangat bagus, tetap pertahankan dan belajarlah dengan lebih giat lagi\n\n");
    }
    else if (nilai > 90 && nilai <= 100) {
        printf("Nilai kamu sempurna, pertahankan dan lakukan yang terbaik di masa depan\n\n");
    }
    else {
        printf("Kamu memasukkan nilai yang salah!\n\n");
    }
    return nilai;
}

int main() {
    ambil_nilai();
    return 0;
}