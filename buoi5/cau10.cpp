#include <stdio.h>

// Ham de quy tim kiem nhi phan
int timKiemNhiPhan(int arr[], int left, int right, int x) {
    // Neu left vuot qua right, phan tu khong ton tai trong mang
    if (left > right) {
        return -1;  // Khong tim thay phan tu
    }

    int mid = left + (right - left) / 2;  // Tinh chi so giua mang

    // Neu phan tu o vi tri giua chinh la gia tri can tim
    if (arr[mid] == x) {
        return mid;
    }

    // Neu phan tu can tim nho hon phan tu o giua, tim ben trai
    if (arr[mid] > x) {
        return timKiemNhiPhan(arr, left, mid - 1, x);
    }

    // Neu phan tu can tim lon hon phan tu o giua, tim ben phai
    return timKiemNhiPhan(arr, mid + 1, right, x);
}

int main() {
    int n, x;

    // Nhap so luong phan tu cua mang
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n];

    // Nhap cac phan tu da sap xep cua mang
    printf("Nhap cac phan tu da sap xep cua mang: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Nhap phan tu can tim
    printf("Nhap phan tu can tim: ");
    scanf("%d", &x);

    // Goi ham tim kiem nhi phan
    int ketQua = timKiemNhiPhan(arr, 0, n - 1, x);

    // In ket qua
    if (ketQua == -1) {
        printf("Khong tim thay phan tu %d trong mang.\n", x);
    } else {
        printf("Phan tu %d duoc tim thay tai vi tri %d.\n", x, ketQua);
    }

    return 0;
}

