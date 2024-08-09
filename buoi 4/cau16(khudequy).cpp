#include <stdio.h>

// Hàm kh? ğ? quy ğ? tính giá tr? c?a Y(n)
int Y_iterative(int n) {
    if (n == 1)
        return 1; // Y1 = 1
    if (n == 2)
        return 2; // Y2 = 2
    if (n == 3)
        return 3; // Y3 = 3

    int Y[100]; // Gi? s? n < 100, có th? ği?u ch?nh kích thı?c n?u c?n
    Y[1] = 1;
    Y[2] = 2;
    Y[3] = 3;

    for (int i = 4; i <= n; i++) {
        Y[i] = Y[i - 1] + 2 * Y[i - 2] + 3 * Y[i - 3];
    }

    return Y[n];
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

    int result = Y_iterative(n);
    printf("(khu de quy )Gia tri cua Y(%d) la: %d\n", n, result);

    return 0;
}

