#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    // Bài 3
    float a, b;
    float* pa, * pb;

    // Nhập vào 2 số thực a và b
    printf("Nhập số thực a: ");
    if (scanf("%f", &a) != 1) {
        printf("Lỗi nhập số a.\n");
        return 1;
    }
    printf("Nhập số thực b: ");
    if (scanf("%f", &b) != 1) {
        printf("Lỗi nhập số b.\n");
        return 1;
    }

    // Tạo 2 con trỏ pa và pb trỏ đến a và b
    pa = &a;
    pb = &b;

    // Xuất giá trị các con trỏ pa, pb
    printf("Giá trị của a: %.2f\n", *pa);
    printf("Giá trị của b: %.2f\n", *pb);

    // Bài 9
    float tong, hieu, tich, thuong;
    float* ptong, * phieu, * ptich, * pthuong;

    // Tính toán tổng, hiệu, tích, thương
    tong = *pa + *pb;
    hieu = *pa - *pb;
    tich = *pa * *pb;
    if (*pb != 0) {
        thuong = *pa / *pb;
    }
    else {
        printf("Không thể chia cho 0!\n");
        thuong = 0; 
    }

    ptong = &tong;
    phieu = &hieu;
    ptich = &tich;
    pthuong = &thuong;

    printf("Tổng: %.2f, Địa chỉ: %p\n", *ptong, (void*)ptong);
    printf("Hiệu: %.2f, Địa chỉ: %p\n", *phieu, (void*)phieu);
    printf("Tích: %.2f, Địa chỉ: %p\n", *ptich, (void*)ptich);
    printf("Thương: %.2f, Địa chỉ: %p\n", *pthuong, (void*)pthuong);

    return 0;
}
