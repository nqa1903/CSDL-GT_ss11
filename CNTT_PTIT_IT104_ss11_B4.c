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

// BƯỚC 4: Hàm lấy độ dài danh sách liên kết đôi
int getLength(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// BƯỚC 5: Hàm main
int main() {
    Node* head = NULL;

    // Khởi tạo danh sách: 1 <-> 2 <-> 3 <-> 4 <-> 5
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    // Gọi hàm đếm số phần tử
    int length = getLength(head);

    // In kết quả
    printf("Danh sách liên kết có %d phần tử\n", length);

    return 0;
}
