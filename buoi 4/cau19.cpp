#include <stdio.h>


int A_recursive(int n) {
    if (n == 1)
        return 1; // A1 = 1

    if (n % 2 == 0) { // n là s? ch?n
        int k = n / 2;
        return k + A_recursive(k) + 2;
    } else { // n là s? l?
        int k = (n - 1) / 2;
        return k * k + A_recursive(k) * A_recursive(k + 1) + 1;
    }
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

    int result = A_recursive(n);
    printf("Gia tri cua A(%d) la: %d\n", n, result);

    return 0;
}

