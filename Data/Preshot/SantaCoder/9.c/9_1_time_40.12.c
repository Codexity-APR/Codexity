#include <stdio.h>

int ambil_nilai() {
    int nilai, NMK; 
    printf("Masukkan mata kuliah yang ingin dicari analisa nya:\n");
    scanf("%d", &NMK);
    printf("Masukkan nilai mata kuliahnya:\n");
    scanf("%d", &nilai);
    if (nilai <= 50) {
        printf("kamu harus belajar lagi karena nilai kamu kurang\n\n");
        return 1; // indicating failure
    } else {
        printf("nilai kamu cukup, lanjutkan belajar!\n\n");
        return 0; // indicating success
    }
}

int main() {
    int status = ambil_nilai();
    if (status == 0) {
        printf("Selamat, kamu berhasil melewati mata kuliah ini!\n");
    } else {
        printf("Kamu harus mengulang mata kuliah ini.\n");
    }
    return 0;
}