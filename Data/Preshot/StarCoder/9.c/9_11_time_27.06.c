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
    else if (nilai <= 60) {
        printf("kamu masih perlu belajar lebih giat lagi\n\n");
    }
    else if (nilai <= 70) {
        printf("nilai kamu cukup bagus\n\n");
    }
    else if (nilai <= 80) {
        printf("nilai kamu sangat bagus\n\n");
    }
    else if (nilai <= 90) {
        printf("nilai kamu mutlak sangat bagus\n\n");
    }
    else {
        printf("nilai kamu luar biasa! Pertahankan prestasi kamu!\n\n");
    }
    return nilai;
}

int main() {
    int hasil = ambil_nilai();
    printf("Nilai yang kamu input adalah: %d\n", hasil);
    return 0;
}