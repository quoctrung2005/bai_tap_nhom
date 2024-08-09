#include <stdio.h>
int A_recursive(int n) ;
int sum_A(int n);

int sum_A(int n) {
    if (n == 1)
        return 1; // A1 = 1
    return sum_A(n - 1) + A_recursive(n - 1);
}


int A_recursive(int n) {
    if (n == 1)
        return 1; // A1 = 1
    return n * sum_A(n);
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

    int result = A_recursive(n);
    printf("Gia tri cua A(%d) la: %d\n", n, result);

    return 0;
}

