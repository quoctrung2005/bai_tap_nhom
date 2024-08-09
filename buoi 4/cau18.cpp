#include <stdio.h>


int sum_x(int n) {
    if (n == 0)
        return 1; // x0 = 1
    if (n == 1)
        return 1 + 2; // x0 + x1 = 1 + 2
    return n * 1 + (n - 1) * 2 + sum_x(n - 1);
}


int x_recursive(int n) {
    return sum_x(n);
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

    int result = x_recursive(n);
    printf("Gia tri cua x(%d) la: %d\n", n, result);

    return 0;
}

