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
        printf("nilai kamu cukup, perlu meningkatkan lagi\n\n");
    }
    else if (nilai <= 70) {
        printf("nilai kamu bagus, perlu lebih meningkatkan lagi\n\n");
    }
    else if (nilai <= 80) {
        printf("nilai kamu sangat bagus, tapi perlu lebih meningkatkan lagi\n\n");
    }
    else if (nilai <= 90) {
        printf("nilai kamu mutlak sangat bagus, tapi perlu lebih meningkatkan lagi\n\n");
    }
    else {
        printf("nilai kamu luar biasa, pertahankan dan terus tingkatkan\n\n");
    }
    return nilai;
}

int main() {
    int nilai = ambil_nilai();
    printf("Nilai anda adalah: %d\n", nilai);
    return 0;
}