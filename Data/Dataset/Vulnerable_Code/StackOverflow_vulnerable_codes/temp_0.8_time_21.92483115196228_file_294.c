#include <stdio.h>

typedef unsigned short WORD;
typedef unsigned long DWORD;

#pragma pack(2)
typedef struct _BITMAPFILEHEADER {
    WORD Type;
    DWORD Size;
    WORD Reserved1;
    WORD Reserved2;
    DWORD OffBits;
} BITMAPFILEHEADER;
#pragma pack()

int main() {
    char* file = "/path/to/bitmap/file.bmp";
    FILE *fp;
    BITMAPFILEHEADER header;

    fp = fopen(file,"rb");
    if (fp == NULL) {
        printf("cannot open file!\n");
        return 1;
    }

    fread(&header, sizeof(BITMAPFILEHEADER), 1, fp);

    printf("Type: %04x\n", header.Type);

    return 0;
}