#include <stdio.h>


int X_recursive(int n) {
    if (n == 1)
        return 1; // X1 = 1
    if (n == 2)
        return 1; // X2 = 1
    return X_recursive(n - 1) + (n - 1) * X_recursive(n - 2);
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

    int result = X_recursive(n);
    printf("Gia tri cua X(%d) la: %d\n", n, result);

    return 0;
}

