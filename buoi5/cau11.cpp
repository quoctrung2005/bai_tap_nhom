#include <stdio.h>

// a. Tinh so cach chia m >= 2n
int chiaQua_a(int m, int n) {
    if (n == 1) {
        return 1; // Neu chi co 1 hoc sinh, chi co 1 cach chia
    }
    if (m < 2 * n - 1) {
        return 0; // Neu so phan thuong khong du chia cho n hoc sinh
    }
    // Chia theo dieu kien m >= 2n
    return chiaQua_a(m - 1, n) + chiaQua_a(m - 1, n - 1);
}

// b. Tinh so cach chia khi m = n
int chiaQua_b(int m, int n) {
    return 1; // Khi m = n, moi hoc sinh nhan 1 phan thuong, chi co 1 cach chia
}

// c. Tinh so cach chia khi m > 2n va moi hoc sinh deu co qua
int chiaQua_c(int m, int n) {
    if (n == 1) {
        return m; // Neu chi co 1 hoc sinh, co m cach chia
    }
    if (m < 2 * n - 1) {
        return 0; // Neu so phan thuong khong du chia
    }
    // Chia theo dieu kien moi hoc sinh deu co qua
    return chiaQua_c(m - 1, n) + chiaQua_c(m - 2, n - 1);
}

int main() {
    int m, n;

    printf("Nhap so phan thuong m: ");
    scanf("%d", &m);
    printf("Nhap so hoc sinh n: ");
    scanf("%d", &n);

    // a. Tinh so cach chia m >= 2n
    if (m >= 2 * n) {
        printf("So cach chia m >= 2n: %d\n", chiaQua_a(m, n));
    } else {
        printf("Khong the chia voi m >= 2n.\n");
    }

    // b. Tinh so cach chia khi m = n
    if (m == n) {
        printf("So cach chia khi m = n: %d\n", chiaQua_b(m, n));
    } else {
        printf("Khong the chia voi m = n.\n");
    }

    // c. Tinh so cach chia khi m > 2n va moi hoc sinh deu co qua
    if (m > 2 * n) {
        printf("So cach chia khi m > 2n va moi hoc sinh deu co qua: %d\n", chiaQua_c(m, n));
    } else {
        printf("Khong the chia voi m > 2n.\n");
    }

    return 0;
}

