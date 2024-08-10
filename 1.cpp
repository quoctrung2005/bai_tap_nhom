#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Hàm tính S(n) cho bài 9
double S1_dequy(int n) {
    if (n == 1) return 1.0 / (1 * 2 * 3);
    return 1.0 / (n * (n + 1) * (n + 2)) + S1_dequy(n - 1);
}

double S1_khudequy(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        sum += 1.0 / (i * (i + 1) * (i + 2));
    }
    return sum;
}

int S2_dequy(int n) {
    if (n == 1) return 1;
    return n * n + S2_dequy(n - 1);
}

int S2_khudequy(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i * i;
    }
    return sum;
}

int S3_dequy(int n) {
    if (n == 1) return 1;
    return (n * (n + 1)) / 2 + S3_dequy(n - 1);
}

int S3_khudequy(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += (i * (i + 1)) / 2;
    }
    return sum;
}

double S4_dequy(int n) {
    if (n == 1) return -(1 + 2) / (2.0);
    return pow(-1, n) * ((2 * n - 1) + 2 * n) / (double)(2 * n) + S4_dequy(n - 1);
}

double S4_khudequy(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        sum += pow(-1, i) * ((2 * i - 1) + 2 * i) / (double)(2 * i);
    }
    return sum;
}

// Hàm tính toán Fibonacci cho bài 10
int fib(int x) {
    if (x <= 2) return 1;
    return fib(x - 1) + fib(x - 2);
}

void fibonacci_dequy(int m, int n) {
    for (int i = 1; ; i++) {
        int f = fib(i);
        if (f > n) break;
        if (f >= m) printf("%d ", f);
    }
}

void fibonacci_khudequy(int m, int n) {
    int a = 1, b = 1, c;
    if (a >= m && a <= n) printf("%d ", a);
    while (1) {
        c = a + b;
        if (c > n) break;
        if (c >= m) printf("%d ", c);
        a = b;
        b = c;
    }
}

// Hàm tìm số Fibonacci lớn nhất nhỏ hơn n cho bài 11
int fibonacci_max_dequy(int n) {
    int i = 1;
    while (fib(i) < n) i++;
    return fib(i - 1);
}

int fibonacci_max_khudequy(int n) {
    int a = 1, b = 1, c = 1;
    while (c < n) {
        a = b;
        b = c;
        c = a + b;
    }
    return b;
}

// Hàm tính xn và yn cho bài 12
void tinh_xy(int n, int* x, int* y) {
    if (n == 0) {
        *x = 1;
        *y = 0;
    }
    else {
        int xnm1, ynm1;
        tinh_xy(n - 1, &xnm1, &ynm1);
        *x = xnm1 + ynm1;
        *y = 3 * xnm1 + 2 * ynm1;
    }
}

// Hàm tính giá trị phần tử thứ n của cấp số nhân cho bài 13
int gia_tri_cs_nhan(int n, int a, int q) {
    if (n == 1) return a;
    return q * gia_tri_cs_nhan(n - 1, a, q);
}

// Hàm tính biểu thức U(n) cho bài 14
int U(int n) {
    if (n < 6) return n;

    int U[6];
    for (int i = 0; i < 6; i++)
        U[i] = i;

    for (int i = 6; i <= n; i++) {
        int temp = U[0] + U[1] + U[2] + U[3] + U[4];
        for (int j = 0; j < 5; j++)
            U[j] = U[j + 1];
        U[5] = temp;
    }

    return U[5];
}

int main() {
    int choice, n, m, a, q, x, y;

    while (1) {
        printf("\nChon bai can chay:\n");
        printf("9: Tinh cac bieu thuc S(n)\n");
        printf("10: Xuat day so Fibonacci thuoc doan [m, n]\n");
        printf("11: Tim so Fibonacci lon nhat nho hon n\n");
        printf("12: Tinh so hang thu n cua 2 day x_n va y_n\n");
        printf("13: Tim gia tri phan tu thu n cua cap so nhan\n");
        printf("14: Tinh bieu thuc U(n)\n");
        printf("0: Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
        case 9:
            printf("Nhap n: ");
            scanf("%d", &n);
            printf("S1_dequy(%d) = %.5lf\n", n, S1_dequy(n));
            printf("S1_khudequy(%d) = %.5lf\n", n, S1_khudequy(n));
            printf("S2_dequy(%d) = %d\n", n, S2_dequy(n));
            printf("S2_khudequy(%d) = %d\n", n, S2_khudequy(n));
            printf("S3_dequy(%d) = %d\n", n, S3_dequy(n));
            printf("S3_khudequy(%d) = %d\n", n, S3_khudequy(n));
            printf("S4_dequy(%d) = %.5lf\n", n, S4_dequy(n));
            printf("S4_khudequy(%d) = %.5lf\n", n, S4_khudequy(n));
            break;

        case 10:
            printf("Nhap m va n: ");
            scanf("%d%d", &m, &n);
            printf("Fibonacci day (de quy): ");
            fibonacci_dequy(m, n);
            printf("\nFibonacci day (khu de quy): ");
            fibonacci_khudequy(m, n);
            break;

        case 11:
            printf("Nhap n: ");
            scanf("%d", &n);
            printf("Fibonacci lon nhat nho hon %d (de quy) = %d\n", n, fibonacci_max_dequy(n));
            printf("Fibonacci lon nhat nho hon %d (khu de quy) = %d\n", n, fibonacci_max_khudequy(n));
            break;

        case 12:
            printf("Nhap n: ");
            scanf("%d", &n);
            tinh_xy(n, &x, &y);
            printf("x_%d = %d, y_%d = %d\n", n, x, n, y);
            break;

        case 13:
            printf("Nhap n, a va q: ");
            scanf("%d%d%d", &n, &a, &q);
            printf("Gia tri phan tu thu %d cua cap so nhan = %d\n", n, gia_tri_cs_nhan(n, a, q));
            break;

        case 14:
            printf("Nhap n: ");
            scanf("%d", &n);
            printf("U(%d) = %d\n", n, U(n));
            break;

        case 0:
            exit(0);

        default:
            printf("Lua chon khong hop le.\n");
        }
    }

    return 0;
}
