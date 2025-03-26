#include <stdio.h>

// Fungsi menghitung jumlah digit suatu bilangan
int FindDigits(int bil) {
    int factor = 1;
    int digit = 0;
    while (bil / factor > 0) {
        digit += (bil / factor) % 10;
        factor *= 10;
    }
    return digit;
}

// Fungsi untuk mengecek apakah bilangan prima
int IsPrime(int bil) {
    if (bil < 2) return 0;
    for (int i = 2; i * i <= bil; i++) {
        if (bil % i == 0) return 0;
    }
    return 1;
}

// Menghitung jumlah bilangan prima yang memenuhi syarat
int countPrime(int A, int B) {
    int total = 0;
    for (int i = A; i <= B; i++) {
        if (IsPrime(i) && IsPrime(FindDigits(i))) {
            total++;
        }
    }
    return total;
}

// Mengubah integer ke Bilangan Bingro (biner terbalik tanpa leading zero)
int KonversiBingro(int x) {
    int result = 0;
    while (x > 0) {
        result = result * 10 + (x % 2);
        x /= 2;
    }
    return result;
}

int main() {
    int A, B;
    scanf("%d %d", &A, &B);

    int total = countPrime(A, B);
    int bingro = KonversiBingro(total);

    printf("%d\n", bingro);
    return 0;
}
