#include <stdio.h>

int main(){
    int N, A, D;
    int mat,men,ter;
    mat = 0;
    men = 0;
    ter = 0;
    scanf("%d", &N);
    while (N>0)
    {
        scanf("%d", &A);
        if (A == 1){
            scanf("%d", &D);
            if (D >= 0 && D < 3){
                printf("Kategori: Mentah\n");
                men++;
            } else if (D > 2 && D < 6)
            {
                printf("Kategori: Matang\n");
                mat++;
            } else if (D > 5)
            {
                printf("Kategori: Terlalu matang\n");
                ter++;
            }
            N--;          
        } else if (A == 2){
            printf("Laporan Kematangan Pisang\n");
            printf("Mentah: %d\n",men);
            printf("Matang: %d\n",mat);
            printf("Terlalu matang: %d\n",ter);
        } else{
            printf("Input salah. Masukkan kembali input dengan benar.\n");
        }
    }
    printf("Program selesai\n");
}