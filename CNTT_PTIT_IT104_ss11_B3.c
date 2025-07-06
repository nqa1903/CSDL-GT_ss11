#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// BƯỚC 1: Định nghĩa cấu trúc node của danh sách liên kết đôi
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// BƯỚC 2: Tạo một node mới
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

// BƯỚC 4: Duyệt và in danh sách
void traverseList(Node* head) {
    int count = 1;
    while (head != NULL) {
        printf("Node %d: %d\n", count, head->data);
        head = head->next;
        count++;
    }
}

// BƯỚC 5: Hàm tìm kiếm trong danh sách liên kết đôi
bool search(Node* head, int target) {
    while (head != NULL) {
        if (head->data == target)
            return true; // Tìm thấy
        head = head->next;
    }
    return false; // Không tìm thấy
}

// BƯỚC 6: Hàm main
int main() {
    Node* head = NULL;

    // Khởi tạo danh sách liên kết đôi: 1 <-> 2 <-> 3 <-> 4 <-> 5
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    // In danh sách
    printf("Danh sách hiện tại:\n");
    traverseList(head);

    // Nhập số cần tìm
    int x;
    printf("Nhập số cần tìm: ");
    scanf("%d", &x);

    // Kiểm tra và in kết quả
    if (search(head, x)) {
        printf("True\n");  // Số có trong danh sách
    } else {
        printf("False\n"); // Số không có trong danh sách
    }

    return 0;
}
