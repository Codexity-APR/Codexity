#include <stdio.h>

int ambil_nilai() {
    int nilai, NMK; 
    printf("Masukkan mata kuliah yang ingin dicari analisa nya:\n");
    scanf("%d", &NMK);
    printf("Masukkan nilai mata kuliahnya:\n");
    scanf("%d", &nilai);
    if (nilai <= 50) {
        printf("kamu harus belajar lagi karena nilai kamu kurang\n\n");
    } else if (nilai > 50 && nilai < 70) {
        printf("kamu harus belajar lebih giat lagi\n\n");
    } else if (nilai >= 70 && nilai < 80) {
        printf("kamu sudah lumayan, tapi masih perlu meningkatkan lagi\n\n");
    } else if (nilai >= 80 && nilai < 90) {
        printf("kamu sudah bagus, tapi masih perlu sedikit lagi\n\n");
    } else if (nilai >= 90 && nilai <= 100) {
        printf("kamu sangat bagus, pertahankan prestasimu\n\n");
    } else {
        printf("masukkan nilai yang sesuai\n\n");
    }
    return nilai;
}

int main() {
    ambil_nilai();
    return 0;
}