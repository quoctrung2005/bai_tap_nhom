//#include <stdio.h>
//#include <ctype.h>
//#include <string.h>  
//
//void inKyTu(const char* str) {
//    while (*str) {
//        printf("%c ", *str);
//        str++;
//    }
//    printf("\n");
//}
//
//void chuyenThanhChuHoa(char* str) {
//    while (*str) {
//        if (islower((unsigned char)*str)) {
//            *str = *str - 'a' + 'A';  
//        }
//        str++;
//    }
//}
//
//void vietHoaDauMoiTu(char* str) {
//    int batDauTuMoi = 1;  
//    while (*str) {
//        if (isspace((unsigned char)*str)) {
//            batDauTuMoi = 1;
//        }
//        else if (batDauTuMoi) {
//            if (islower((unsigned char)*str)) {
//                *str = *str - 'a' + 'A'; 
//            }
//            batDauTuMoi = 0;
//        }
//        str++;
//    }
//}
//
//int main() {
//    char st[100];
//
//    printf("Nhập chuỗi: ");
//    fgets(st, sizeof(st), stdin);
//
//    char* newline = strchr(st, '\n');
//    if (newline) {
//        *newline = '\0';
//    }
//
//    // a. Xuất giá trị từng ký tự của st thông qua con trỏ
//    printf("Các ký tự trong chuỗi là: ");
//    inKyTu(st);
//
//    // b. Chuyển các ký tự của chuỗi về dạng chữ hoa
//    chuyenThanhChuHoa(st);
//    printf("Chuỗi sau khi chuyển thành chữ hoa: %s\n", st);
//
//    // c. Chuyển các ký tự đầu mỗi từ về dạng chữ hoa
//    vietHoaDauMoiTu(st);
//    printf("Chuỗi sau khi viết hoa ký tự đầu mỗi từ: %s\n", st);
//
//    return 0;
//}
