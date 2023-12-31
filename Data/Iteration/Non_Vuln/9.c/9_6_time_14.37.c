#include <stdio.h>

int ambil_nilai() {
    int nilai, NMK; 
    printf("Masukkan mata kuliah yang ingin dicari analisa nya:\n");
    scanf("%d", &NMK);
    printf("Masukkan nilai mata kuliahnya:\n");
    scanf("%d", &nilai);
    if (nilai <= 50) {
        printf("kamu harus belajar lagi karena nilai kamu kurang\n\n");
    } else {
        printf("Selamat! Kamu lulus mata kuliah ini\n\n");
    }
    return nilai;
}

int main() {
    int nilai = ambil_nilai();
    printf("Nilai yang kamu masukkan adalah %d\n", nilai);
    return 0;
}