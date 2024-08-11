#include <stdio.h>

// Ham de quy tinh to hop chap k cua n phan tu
int toHopChapK(int n, int k) {
    // Dieu kien dung: neu k = 0 hoac k = n thi C(n, k) = 1
    if (k == 0 || k == n) {
        return 1;
    }
    // Cong thuc de quy: C(n, k) = C(n-1, k-1) + C(n-1, k)
    return toHopChapK(n - 1, k - 1) + toHopChapK(n - 1, k);
}

int main() {
    int n, k;

    // Nhap gia tri n va k
    printf("Nhap n: ");
    scanf("%d", &n);
    printf("Nhap k: ");
    scanf("%d", &k);

    // Kiem tra dieu kien n >= k >= 0
    if (k > n || k < 0) {
        printf("Gia tri k phai nam trong khoang tu 0 den n.\n");
        return 1;
    }

    // Tinh va in ket qua to hop chap k cua n phan tu
    printf("To hop chap %d cua %d phan tu la: %d\n", k, n, toHopChapK(n, k));

    return 0;
}

