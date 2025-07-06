#include <stdio.h>
#include <stdlib.h>

// BƯỚC 1: Khai báo cấu trúc node cho danh sách liên kết đôi
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// BƯỚC 2: Tạo node mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Không thể cấp phát bộ nhớ.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// BƯỚC 3: Thêm phần tử vào cuối danh sách
void append(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// BƯỚC 4: Thêm phần tử vào đầu danh sách
void insertAtHead(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;   // Trỏ node mới tới node hiện tại đầu tiên
        (*head)->prev = newNode; // Trỏ node cũ về node mới
        *head = newNode;         // Cập nhật lại head
    }
}

// BƯỚC 5: Hàm in danh sách
void printList(Node* head) {
    printf("Danh sách hiện tại: ");
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) printf("<->");
        head = head->next;
    }
    printf("->NULL\n");
}

// BƯỚC 6: Hàm main
int main() {
    Node* head = NULL;

    // Tạo danh sách ban đầu: 1<->2<->3<->4<->5
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    // In danh sách ban đầu
    printf("Trước khi thêm:\n");
    printList(head);

    // Nhập số nguyên cần thêm vào đầu
    int value;
    printf("Nhập số nguyên cần thêm vào đầu danh sách: ");
    scanf("%d", &value);

    // Thêm vào đầu danh sách
    insertAtHead(&head, value);

    // In danh sách sau khi thêm
    printf("Sau khi thêm:\n");
    printList(head);

    return 0;
}
