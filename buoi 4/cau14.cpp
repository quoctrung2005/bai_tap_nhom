#include <stdio.h>


int U_recursive(int n) {
    if (n < 6)
        return n;
    return U_recursive(n - 5) + U_recursive(n - 4) + U_recursive(n - 3) + U_recursive(n - 2) + U_recursive(n - 1);
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

    int result = U_recursive(n);
    printf("Gia tri cua U(%d) la: %d\n", n, result);

    return 0;
}

