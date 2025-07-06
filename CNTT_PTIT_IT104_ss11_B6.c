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

// BƯỚC 4: In danh sách
void printList(Node* head) {
    printf("Danh sách hiện tại: ");
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) printf("<->");
        head = head->next;
    }
    printf("->NULL\n");
}

// BƯỚC 5: Xóa phần tử đầu tiên
void deleteHead(Node** head) {
    if (*head == NULL) {
        printf("Danh sách rỗng, không thể xóa.\n");
        return;
    }

    Node* temp = *head;         // Node cần xóa là head hiện tại
    *head = (*head)->next;      // Cập nhật head sang node kế tiếp

    if (*head != NULL)          // Nếu danh sách còn phần tử phía sau
        (*head)->prev = NULL;   // Loại bỏ liên kết ngược về node cũ

    free(temp);                 // Giải phóng bộ nhớ node bị xóa
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

    // In danh sách trước khi xóa
    printf("Trước khi xóa phần tử đầu:\n");
    printList(head);

    // Gọi hàm xóa node đầu tiên
    deleteHead(&head);

    // In danh sách sau khi xóa
    printf("Sau khi xóa phần tử đầu:\n");
    printList(head);

    return 0;
}
