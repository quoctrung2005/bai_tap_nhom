#include <stdio.h>
int x_recursive(int n);
int y_recursive(int n);

int y_recursive(int n) {
    if (n == 0)
        return 0; // y_0 = 0
    return x_recursive(n - 1); // y_n = x_{n-1}
}
int x_recursive(int n) {
    if (n == 0)
        return 1; // x_0 = 1
    return x_recursive(n - 1) + y_recursive(n - 1); // x_n = x_{n-1} + y_{n-1}
}




int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

    int xn = x_recursive(n);
    int yn = y_recursive(n);

    printf("So hang thu %d cua day x la: %d\n", n, xn);
    printf("So hang thu %d cua day y la: %d\n", n, yn);

    return 0;
}

