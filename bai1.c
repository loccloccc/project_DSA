//
// Created by loc on 31/07/2025.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//menu
void menu() {
    printf("======================================\n");
    printf("============== Menu ==================\n");
    printf("1 . CREATE request.\n");
    printf("2 . PROCESS .\n");
    printf("3 . UNDO .\n");
    printf("4 . VIEW .\n");
    printf("5 . HISTORY .\n");
    printf("6 . CLEAR HISTORY.\n");
    printf("7 . THOAT.\n");
    printf("======================================\n");
}
// xay dung cac cau truc
typedef struct Request {
    char username[100];
    char issuer[100];
    char timestamp[100];
}Request;
// dslk
typedef struct Node {
    Request* data;
    struct Node* next;
}Node;
Node *head = NULL;
// stack
typedef struct Stack {
    Node* top;
}Stack;
void initStack(Stack* s) {
    s->top = NULL;
}
int isEmptyStack(Stack* s) {
    return s->top == NULL;
}
void push(Stack* s , Request* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
}
Request* pop(Stack* s) {
    if (isEmptyStack(s)) {
        printf("danh sach rong.\n");
        return NULL;
    }
    Node* temp = s->top;
    s->top = temp->next;
    free(temp->data);
    free(temp);
}
void display(Stack* s) {
    if (isEmptyStack(s)) {
        printf("danh sach rong.\n");
        return;
    }
    Node* temp = s->top;
    while (temp!=NULL) {
        printf("Ten nguoi yeu cau : " , temp->data->username);
        printf("Noi dung yeu cau : " , temp->data->issuer);
        printf("Thoi gian : " , temp->data->timestamp);
        temp = temp->next;
    }
}
// queue
typedef struct Queue {
    Node* rear;
    Node* front;
}Queue;
//
void initQueue(Queue* q) {
    q->rear = q->front = NULL;
}
int isEmptyQueue(Queue* q) {
    return q->rear == NULL;
}
void enQueue(Queue* q , Request* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->rear = q->front = newNode;
    }
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}
void displayQueue(Queue* q) {
    if (isEmptyQueue(q)) {
        printf("danh sach rong.\n");
        return;
    }
    Node* current = q->front;
    while (current != NULL) {
        printf("Ten nguoi yeu cau : %s\n" , current->data->username);
        printf("Noi dung yeu cau : %s\n " , current->data->issuer);
        printf("Thoi gian : %s\n" , current->data->timestamp);
        current = current->next;
    }

}
// xoa toan bo lich su
void clearHistory(Node* head) {
    if (head == NULL) {
        printf("danh sach rong.\n");
        return;
    }
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp->data);
        free(temp);
    }
    printf("Xoa lich su thanh cong .\n");
}
// in lich su
void displayHistory(Node* head) {
    if (head == NULL) {
        printf("danh sach rong.\n");
        return;
    }else {
        Node* current = head;
        while (current != NULL) {
            printf("Ten nguoi yeu cau : %s\n" , current->data->username);
            printf("Noi dung yeu cau : %s\n" , current->data->issuer);
            printf("Thoi gian yeu cau : %s\n" , current->data->timestamp);
            current = current->next;
        }
    }
}
Node* createNode(Request* r) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = r;
    newNode->next = NULL;
    return newNode;
}
Node* add(Request* r) {
    Node* newNode = createNode(r);
    if (head == NULL) {
        head = newNode;
        return newNode;
    }
    Node* current = head;
    while (current != NULL) current = current->next;
    current->next = newNode;
    return head;
}
void deQueue(Stack* undo ,Queue* q) {
    if (isEmptyQueue(q)) {
        printf("Danh sach rong.\n");
        return;
    }
    Node* temp = q->front;
    q->front = q->front->next;
    q->rear = q->front;
    push(undo,temp->data);
    free(temp->data);
    free(temp);
    printf("Xu li thanh cong .\n");
}
// void undo(Stack* undo , Queue* q) {
//     if (isEmptyStack(undo)) {
//         printf("danh sach rong .\n");
//         return;
//     }
//
//     enQueue(q,pop(undo));
//     printf("Hoan tac thanh cong .\n");
// }




int main(){
    Request *data;
    data = (Request*)malloc(sizeof(Request));
    Stack undo;
    Queue q;
    initStack(&undo);
    initQueue(&q);
    int choice;
    do {
        menu();
        printf("Lua chon cua ban : ");
        scanf("%d",&choice);
        getchar();
        switch (choice) {
            case 1:
                printf("Nhap ten :");
                fgets(data->username,100,stdin);
                data->username[strcspn(data->username,"\n")] = '\0';
                printf("nhap noi dung : ");
                fgets(data->issuer,100,stdin);
                data->issuer[strcspn(data->issuer,"\n")] = '\0';
                printf("nhap thoi gian :");
                fgets(data->timestamp,100,stdin);
                data->timestamp[strcspn(data->timestamp,"\n")] = '\0';
                enQueue(&q,data);
                head = createNode(data);
                printf("Them yeu cau thanh cong.\n");
                break;
            case 2:
                deQueue(&undo,&q);
                break;
            case 3:
                printf("......\n");
                break;
            case 4:
                displayQueue(&q);
                break;
            case 5:
                displayHistory(head);
                break;
            case 6:
                clearHistory(head);
                break;
            case 7:
                printf("thoat thanh cong.\n");
                break;
            default:
                printf("khong co lua chon nay ...\n");
        }
    }while (choice != 7);

    return 0;
}