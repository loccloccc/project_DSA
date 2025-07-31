//
// Created by loc on 31/07/2025.
//
#include<stdio.h>
#include<stdio.h>
#include<string.h>

void menu() {
    printf("=================================\n");
    printf("=============== menu ============\n");
    printf("1 . Them tu.\n");
    printf("2 . Tra nghia.\n");
    printf("3 . Hien thi danh sach tu.\n");
    printf("4 . Cap nhap tu cu.\n");
    printf("5 . Thoat.\n");
}
int main() {
    int choice;
    do {
        menu();
        printf("lua chon cua ban : ");
        scanf("%d" , &choice);
        switch (choice) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                printf("Thoat thanh cong .\n");
                break;
            default:
                printf("khong co lua chon nay .\n");
        }
    }while (choice!=5);
}