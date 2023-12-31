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
        printf("kamu harus belajar lebih keras lagi karena nilai kamu cukup\n\n");
    }
    else if (nilai > 60 && nilai <= 70) {
        printf("kamu harus memperbaiki lagi karena nilai kamu belum cukup bagus\n\n");
    }
    else if (nilai > 70 && nilai <= 80) {
        printf("nilai kamu sudah bagus, tapi masih ada ruang untuk perbaikan\n\n");
    }
    else if (nilai > 80 && nilai <= 90) {
        printf("nilai kamu sangat bagus, tetap pertahankan!\n\n");
    }
    else if (nilai > 90 && nilai <= 100) {
        printf("nilai kamu sangat memuaskan, selamat!\n\n");
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