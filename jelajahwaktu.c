#include <stdio.h>
#include <string.h>

/**
 * @brief Struktur untuk merepresentasikan tanggal.
 */
typedef struct {
    int day;
    int month;
    int year;
} Date;

/**
 * @brief Fungsi untuk mengecek apakah tahun adalah tahun kabisat.
 */
int isLeapYear(int year) {
    if (year % 100 == 0 && year % 400 == 0){
        return 1;
    }
    else if (year % 100 != 0 && year % 4 == 0){
        return 1;
    }
    else{
        return 0;
    }
}

/**
 * @brief Fungsi untuk mendapatkan jumlah hari dalam bulan tertentu.
 */
int getDaysInMonth(int month, int year) {
    int kabisat = isLeapYear(year);
    if (month == 2){
        if (kabisat == 1){
            return 29;
        } else {
            return 28;
        }
    }
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        return 31;
    }
    else{
        return 30;
    }
}

/**
 * @brief Fungsi untuk menghitung jumlah hari sejak 1 Januari tahun 1.
 */
int daysSinceBeginning(Date date) {
    int days = 0;
    for (int i = 1; i < date.year; i++){
        if (isLeapYear(i) == 1){
            days = days + 366;
        }
        else{
            days = days + 365;
        }
    }
    for (int i = 1; i < date.month; i++){
        days = days + getDaysInMonth(i,date.year);
    }
    days = days + date.day;
    return days;
}

/**
 * @brief Fungsi untuk menambahkan n hari ke tanggal.
 */
Date addDays(Date date, int n) {
    while (n > 0) {
        int daysInMonth = getDaysInMonth(date.month, date.year);
        int remainingDays = daysInMonth - date.day;

        if (n <= remainingDays) {
            date.day += n;
            n = 0;
        } else {
            n -= (remainingDays + 1);
            date.day = 1;
            date.month++;
            if (date.month > 12) {
                date.month = 1;
                date.year++;
            }
        }
    }
    return date;
}

/**
 * @brief Fungsi untuk mendapatkan indeks hari dalam seminggu.
 */
int getDayOfWeekAsIndex(Date date) {
    int hari = daysSinceBeginning(date);
    int a = hari % 7;
    return a; 
}

/* FUNGSI - FUNGSI DI BAWAH INI TIDAK PERLU DIUBAH */

static const char *months[] = {"Januari",   "Februari", "Maret",    "April",
                               "Mei",       "Juni",     "Juli",     "Agustus",
                               "September", "Oktober",  "November", "Desember"};
static const char *days[] = {"Minggu", "Senin", "Selasa", "Rabu",
                             "Kamis",  "Jumat", "Sabtu"};

const char *getDayOfWeek(Date date) {
    int dayIndex = getDayOfWeekAsIndex(date);
    return days[dayIndex];
}

void printDate(Date date) {
    printf("%s, %d %s %d\n", getDayOfWeek(date), date.day,
           months[date.month - 1], date.year);
}

int getMonthNumber(const char *monthStr) {
    for (int i = 0; i < 12; i++) {
        if (strcmp(monthStr, months[i]) == 0) {
            return i + 1;
        }
    }
    return -1;
}

Date parseDate(const char *dateStr) {
    Date date;
    char monthStr[15];
    sscanf(dateStr, "%d %s %d", &date.day, monthStr, &date.year);
    date.month = getMonthNumber(monthStr);

    if (date.month == -1) {
        printf("Bulan tidak valid!\n");
    }
    return date;
}

/**
 * @brief Fungsi utama untuk menjalankan program.
 */
int main() {
    char inputDate[30];
    int n;

    fgets(inputDate, sizeof(inputDate), stdin);
    inputDate[strcspn(inputDate, "\n")] = 0;
    scanf("%d", &n);

    Date date;
    date = parseDate(inputDate);

    date = addDays(date, n);
    printDate(date);

    return 0;
}
