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
    
    if (nilai > 50 && nilai <=70) {
        printf("nilai kamu cukup, tapi kamu harus lebih belajar lagi\n\n");
        return 1;
    }
    
    if (nilai > 70 && nilai <=80) {
        printf("nilai kamu memuaskan, tapi kamu harus berusaha lebih keras lagi\n\n");
        return 2;
    }
    
    printf("nilai kamu sangat baik, pertahankan dan tingkatkan lagi\n\n");
    return 3;
}

int main() {
    int result = ambil_nilai();
    printf("Hasil analisis nilai kamu: %d\n", result);
    return 0;
}