#include <stdio.h>

int S2_recursive(int n) {
    if (n == 1)
        return 1 * 1;
    return n * n + S2_recursive(n - 1);
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

    int result = S2_recursive(n);
    printf("S(n) = %d\n", result);

    return 0;
}

