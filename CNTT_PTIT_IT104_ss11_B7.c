#include <stdio.h>
#include <stdlib.h>

// BƯỚC 1: Khai báo cấu trúc node
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// BƯỚC 2: Tạo node mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// BƯỚC 3: Thêm node vào cuối danh sách
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

// BƯỚC 5: Thêm node vào vị trí bất kỳ
void insertAtPosition(Node** head, int value, int position) {
    Node* newNode = createNode(value);

    // Trường hợp thêm vào đầu danh sách (vị trí = 1)
    if (position <= 1 || *head == NULL) {
        newNode->next = *head;
        if (*head != NULL)
            (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    Node* temp = *head;
    int i = 1;

    // Duyệt đến node trước vị trí cần chèn
    while (i < position - 1 && temp->next != NULL) {
        temp = temp->next;
        i++;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
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

    printf("Trước khi chèn:\n");
    printList(head);

    // Nhập dữ liệu từ người dùng
    int value, position;
    printf("Nhập giá trị cần chèn: ");
    scanf("%d", &value);
    printf("Nhập vị trí cần chèn (>=1): ");
    scanf("%d", &position);

    // Gọi hàm chèn
    insertAtPosition(&head, value, position);

    printf("Sau khi chèn:\n");
    printList(head);

    return 0;
}
