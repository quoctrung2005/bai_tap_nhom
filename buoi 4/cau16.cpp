#include <stdio.h>


int Y_recursive(int n) {
    if (n == 1)
        return 1; // Y1 = 1
    if (n == 2)
        return 2; // Y2 = 2
    if (n == 3)
        return 3; // Y3 = 3
    return Y_recursive(n - 1) + 2 * Y_recursive(n - 2) + 3 * Y_recursive(n - 3);
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

    int result = Y_recursive(n);
    printf("Gia tri cua Y(%d) la: %d\n", n, result);

    return 0;
}

