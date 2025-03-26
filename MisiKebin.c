#include <stdio.h>

// TODO: Perbaiki prosedur agar variabel total bisa diperbarui secara langsung
int countPrime(int A, int B)
{
    int total = 0;
    int counter;
    for (int i = A; i <= B; i++ ){
        counter = 0;
        if (i < 2){
            i++;
        }
        for (int j = 1; j <= i;j++){
            if (i % j == 0){
                counter++;
            }
        }
        if (counter < 3){
            total++;
        }
    }
    return total;
}

int main()
{
    int A, B, total;
    total = 0;
    // TODO: Baca dua bilangan integer A dan B dalam satu baris
    // Input harus dalam format: "A B"

    // TODO: Perbaiki pemanggilan prosedur dengan menggunakan alamat variabel total
    // Agar perubahan nilai di dalam prosedur juga mempengaruhi nilai di main()
    scanf("%d %d",&A, &B);
    total = countPrime(A, B);

    printf("%d\n", total);

    return 0;
}