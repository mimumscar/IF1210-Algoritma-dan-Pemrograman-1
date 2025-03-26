#include <stdio.h>
#include <math.h>
#include "NimonsBruteforce.h"

// Memperbaiki: Jika angka == 0, kembalikan 1 (artinya "0" dianggap memiliki 1 digit).
int length(int angka) {
    if (angka == 0) {
        return 1; 
    }
    double dummy = angka;
    int length = 0;
    while (dummy >= 1) {
        dummy = dummy / 10;
        length++;
    }
    return length;
}

// Mengambil digit ke-index dari kanan menggunakan rekursi FindDigit yang sudah ada.
// Jika index == 1, cukup ambil (angka % 10).
// Jika tidak, delegasikan ke FindDigit(angka, index).
int getDigit(int angka, int index) {
    int panjang = length(angka);
    if (index > panjang || index < 1) {
        return -1;
    }
    else if (index == 1) {
        return (angka % 10);
    }
    else {
        return FindDigit(angka, index);
    }
}

// Menghapus digit ke-index dari kanan. 
// Perbaikan: kita susun ulang digit tanpa digit ke-index agar tidak memunculkan angka keliru.
int removeDigit(int angka, int index) {
    int panjang = length(angka);
    if (index > panjang || index < 1) {
        return angka;
    }
    
    int hasil = 0, faktor = 1;
    // Ekstraksi digit dari kanan ke kiri, lewati digit ke-index
    for (int i = 1; i <= panjang; i++) {
        int temp = angka % 10;  // Ambil digit paling kanan
        angka /= 10;            // Buang digit paling kanan
        if (i != index) {       // Jika bukan digit yang dihapus
            hasil += temp * faktor;
            faktor *= 10;
        }
    }
    return hasil;
}

// Logika FindDigit seperti semula, tapi pastikan ambil digit ke-index dengan benar.
int FindDigit(int angka, int index) {
    if (index == 1) {
        return (angka % 10);
    } else {
        int pembagi = pow(10, index - 1);
        // Perbaikan: ambil digit ke-(index) dari kanan = (angka / pembagi) % 10
        return (angka / pembagi) % 10;
    }
}

// Fungsi rekursif untuk mencari semua kombinasi angka
void cariKombinasi(int angka, int current, int panjangAwal) {
    // Jika panjang current sudah sama dengan panjang awal, cetak.
    if (length(current) == panjangAwal) {
        printf("%d\n", current);
        return;
    }

    int panjang = length(angka);

    // Loop i = 1 hingga panjang, artinya kita mengambil digit ke-i dari kanan
    // lalu menghapusnya, dan menambahkannya ke current
    for (int i = 1; i <= panjang; i++) {
        int digit = FindDigit(angka, i);       // Ambil digit ke-i dari kanan
        int angkaTersisa = removeDigit(angka, i); // Hapus digit ke-i

        // Bentuk angka baru dengan menempelkan digit di belakang current
        cariKombinasi(angkaTersisa, current * 10 + digit, panjangAwal);
    }
}

// Fungsi utama untuk memulai pencarian kombinasi
void NimonBruteforce(int angka) {
    int panjang = length(angka);
    cariKombinasi(angka, 0, panjang);
}
