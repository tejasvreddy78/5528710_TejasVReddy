#include <stdio.h>

int isLeap(int year){
    if (year % 400 == 0) return 1;
    if (year % 100 == 0) return 0;
    if (year % 4 == 0) return 1;
    return 0;
}

int daysInMonth(int month, int year){
    switch(month){
        case 1: return 31;
        case 2: return isLeap(year) ? 29 : 28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
        default: return 30;
    }
}

long long toNumber(int d, int m, int y){
    long long num = d;
    num = num * 100 + m;
    num = num * 10000 + y;
    return num;
}

int isLucky(int d, int m, int y){
    long long val = toNumber(d, m, y);
    return (val % 4 == 0 || val % 7 == 0);
}

void nextDate(int *d, int *m, int *y){
    *d = *d + 1;
    if (*d > daysInMonth(*m, *y)){
        *d = 1;
        *m = *m + 1;
        if (*m > 12) {
            *m = 1;
            *y = *y + 1;
        }
    }
}

int main() {
    int d1,m1,y1, d2,m2,y2;
    scanf("%d-%d-%d %d-%d-%d", &d1, &m1, &y1, &d2, &m2, &y2);

    int count = 0;
    while (1) {
        if (isLucky(d1, m1, y1)) {
            count++;
        }
        if (d1 == d2 && m1 == m2 && y1 == y2) {
            break;
        }
        nextDate(&d1, &m1, &y1);
    }
    printf("%d", count);
    return 0;
}
