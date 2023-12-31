#include <stdio.h>

int ambil_nilai() {
    int nilai, NMK; 
    printf("Masukkan mata kuliah yang ingin dicari analisa nya:\n");
    scanf("%d", &NMK);
    printf("Masukkan nilai mata kuliahnya:\n");
    scanf("%d", &nilai);
    if (nilai <= 50) {
        printf("kamu harus belajar lagi karena nilai kamu kurang\n\n");
        return 1;
    }
    else if (nilai > 50 && nilai <= 75) {
        printf("nilai kamu sudah cukup, tapi masih perlu ditingkatkan lagi\n\n");
        return 2;
    }
    else {
        printf("nilai kamu sudah sangat bagus, terus pertahankan\n\n");
        return 3;
    }
}

int main() {
    int hasil_ambil_nilai = ambil_nilai();
    printf("Hasil analisis kamu adalah %d\n", hasil_ambil_nilai);
    return 0;
}