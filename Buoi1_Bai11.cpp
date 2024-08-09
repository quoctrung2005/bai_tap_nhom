//#include <stdio.h>
//#include <limits.h>
//#include <math.h>
//#include <stdbool.h>
//#define _CRT_SECURE_NO_WARNINGS
//// a. Tìm phần tử lớn nhất của mảng và xuất ra phần tử lớn nhất cùng địa chỉ của nó
//void timPhanTuLonNhat(int* arr, int size) {
//    if (size <= 0) {
//        printf("Mảng rỗng.\n");
//        return;
//    }
//
//    int* maxPtr = arr;
//    for (int i = 1; i < size; i++) {
//        if (*(arr + i) > *maxPtr) {
//            maxPtr = arr + i;
//        }
//    }
//
//    printf("Phần tử lớn nhất là: %d\n", *maxPtr);
//    printf("Địa chỉ của phần tử lớn nhất là: %p\n", (void*)maxPtr);
//}
//
//// b. Xuất địa chỉ của phần tử chẵn lớn nhất và phần tử lẻ nhỏ nhất
//void timPhanTuChanLe(int* arr, int size) {
//    if (size <= 0) {
//        printf("Mảng rỗng.\n");
//        return;
//    }
//
//    int* chanMax = NULL, * leMin = NULL;
//    int chanMaxVal = INT_MIN, leMinVal = INT_MAX;
//
//    for (int i = 0; i < size; i++) {
//        if (*(arr + i) % 2 == 0) { // Số chẵn
//            if (*(arr + i) > chanMaxVal) {
//                chanMaxVal = *(arr + i);
//                chanMax = arr + i;
//            }
//        }
//        else { // Số lẻ
//            if (*(arr + i) < leMinVal) {
//                leMinVal = *(arr + i);
//                leMin = arr + i;
//            }
//        }
//    }
//
//    if (chanMax) {
//        printf("Địa chỉ của phần tử chẵn lớn nhất là: %p\n", (void*)chanMax);
//    }
//    else {
//        printf("Không có phần tử chẵn trong mảng.\n");
//    }
//
//    if (leMin) {
//        printf("Địa chỉ của phần tử lẻ nhỏ nhất là: %p\n", (void*)leMin);
//    }
//    else {
//        printf("Không có phần tử lẻ trong mảng.\n");
//    }
//}
//
//// c. Xóa phần tử có giá trị 0
//void xoaPhanTu0(int* arr, int* size) {
//    int i, j;
//    for (i = 0; i < *size; i++) {
//        if (*(arr + i) == 0) {
//            for (j = i; j < *size - 1; j++) {
//                *(arr + j) = *(arr + j + 1);
//            }
//            (*size)--;
//            i--;
//        }
//    }
//}
//
//// d. Thêm phần tử x vào sau phần tử đầu tiên
//void themPhanTuSauDau(int* arr, int* size, int x) {
//    if (*size >= 100) { // Giới hạn kích thước mảng
//        printf("Mảng đã đầy.\n");
//        return;
//    }
//
//    for (int i = *size; i > 1; i--) {
//        *(arr + i) = *(arr + i - 1);
//    }
//    *(arr + 1) = x;
//    (*size)++;
//}
//
//// e. Tính tổng các phần tử là số chính phương
//int tinhTongChinhPhuong(int* arr, int size) {
//    int sum = 0;
//    for (int i = 0; i < size; i++) {
//        int root = sqrt(*(arr + i));
//        if (root * root == *(arr + i)) {
//            sum += *(arr + i);
//        }
//    }
//    return sum;
//}
//
//// a. Xuất các số cực tiểu trong mảng
//void xuatSoCucTieu(int* arr, int size) {
//    if (size <= 0) {
//        printf("Mảng rỗng.\n");
//        return;
//    }
//
//    bool found = false;
//    for (int i = 0; i < size; i++) {
//        if ((i == 0 || *(arr + i) < *(arr + i - 1)) &&
//            (i == size - 1 || *(arr + i) < *(arr + i + 1))) {
//            printf("Số cực tiểu: %d tại vị trí %d\n", *(arr + i), i);
//            found = true;
//        }
//    }
//    if (!found) {
//        printf("Không có số cực tiểu trong mảng.\n");
//    }
//}
//
//// b. Xóa phần tử tại vị trí k
//void xoaPhanTuTaiViTri(int* arr, int* size, int k) {
//    if (k < 0 || k >= *size) {
//        printf("Vị trí không hợp lệ.\n");
//        return;
//    }
//
//    for (int i = k; i < *size - 1; i++) {
//        *(arr + i) = *(arr + i + 1);
//    }
//    (*size)--;
//}
//
//// c. Thêm phần tử x tại vị trí k
//void themPhanTuTaiViTri(int* arr, int* size, int k, int x) {
//    if (k < 0 || k > *size || *size >= 100) {
//        printf("Vị trí không hợp lệ hoặc mảng đã đầy.\n");
//        return;
//    }
//
//    for (int i = *size; i > k; i--) {
//        *(arr + i) = *(arr + i - 1);
//    }
//    *(arr + k) = x;
//    (*size)++;
//}
//
//// d. Chuyển số chẵn lên đầu mảng, số lẻ xuống cuối mảng
//void chuyenChanLenDau(int* arr, int size) {
//    int left = 0, right = size - 1;
//
//    while (left < right) {
//        while (left < right && *(arr + left) % 2 == 0) {
//            left++;
//        }
//        while (left < right && *(arr + right) % 2 != 0) {
//            right--;
//        }
//        if (left < right) {
//            int temp = *(arr + left);
//            *(arr + left) = *(arr + right);
//            *(arr + right) = temp;
//            left++;
//            right--;
//        }
//    }
//}
//
//// e. Kiểm tra mảng có chứa chẵn lẻ xen kẽ không?
//int kiemTraChanLeXenKe(int* arr, int size) {
//    if (size < 2) return 0; // Không đủ phần tử để kiểm tra
//
//    int chan = *(arr + 0) % 2 == 0;
//    for (int i = 1; i < size; i++) {
//        if ((*(arr + i) % 2 == 0) == chan) {
//            return 0; // Không xen kẽ
//        }
//        chan = !chan; // Đảo ngược kiểm tra cho phần tử tiếp theo
//    }
//    return 1; // Xen kẽ
//}
//
//int main() {
//    int arr[100], size, x, k;
//
//    // Nhập kích thước mảng
//    printf("Nhập số lượng phần tử trong mảng: ");
//    scanf("%d", &size);
//
//    // Nhập các phần tử của mảng
//    printf("Nhập các phần tử của mảng:\n");
//    for (int i = 0; i < size; i++) {
//        scanf("%d", &arr[i]);
//    }
//
//    // a. Tìm phần tử lớn nhất
//    timPhanTuLonNhat(arr, size);
//
//    // b. Tìm phần tử chẵn lớn nhất và phần tử lẻ nhỏ nhất
//    timPhanTuChanLe(arr, size);
//
//    // c. Xóa phần tử có giá trị 0
//    xoaPhanTu0(arr, &size);
//    printf("Mảng sau khi xóa phần tử 0:\n");
//    for (int i = 0; i < size; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//
//    // d. Thêm phần tử x vào sau phần tử đầu tiên
//    printf("Nhập phần tử x cần thêm: ");
//    scanf("%d", &x);
//    themPhanTuSauDau(arr, &size, x);
//    printf("Mảng sau khi thêm phần tử %d vào sau phần tử đầu tiên:\n", x);
//    for (int i = 0; i < size; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//
//    // e. Tính tổng các phần tử là số chính phương
//    int sum = tinhTongChinhPhuong(arr, size);
//    printf("Tổng các phần tử là số chính phương: %d\n", sum);
//
//    // a. Xuất các số cực tiểu
//    xuatSoCucTieu(arr, size);
//
//    // b. Xóa phần tử tại vị trí k
//    printf("Nhập vị trí phần tử cần xóa: ");
//    scanf("%d", &k);
//    xoaPhanTuTaiViTri(arr, &size, k);
//    printf("Mảng sau khi xóa phần tử tại vị trí %d:\n", k);
//    for (int i = 0; i < size; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//
//    // c. Thêm phần tử x tại vị trí k
//    printf("Nhập vị trí để thêm phần tử: ");
//    scanf("%d", &k);
//    printf("Nhập phần tử cần thêm: ");
//    scanf("%d", &x);
//    themPhanTuTaiViTri(arr, &size, k, x);
//    printf("Mảng sau khi thêm phần tử %d tại vị trí %d:\n", x, k);
//    for (int i = 0; i < size; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//
//    // d. Chuyển số chẵn lên đầu mảng và số lẻ xuống cuối mảng
//    chuyenChanLenDau(arr, size);
//    printf("Mảng sau khi chuyển số chẵn lên đầu và số lẻ xuống cuối:\n");
//    for (int i = 0; i < size; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//
//    // e. Kiểm tra mảng có chứa chẵn lẻ xen kẽ không
//    if (kiemTraChanLeXenKe(arr, size)) {
//        printf("Mảng chứa chẵn lẻ xen kẽ.\n");
//    }
//    else {
//        printf("Mảng không chứa chẵn lẻ xen kẽ.\n");
//    }
//
//    return 0;
//}
