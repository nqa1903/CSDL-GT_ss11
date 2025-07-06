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

// BƯỚC 5: Xóa phần tử tại vị trí bất kỳ
void deleteAtPosition(Node** head, int position) {
    if (*head == NULL || position <= 0) {
        printf("Vị trí không hợp lệ hoặc danh sách rỗng.\n");
        return;
    }

    Node* temp = *head;

    // Trường hợp xóa node đầu tiên
    if (position == 1) {
        *head = temp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(temp);
        return;
    }

    int i = 1;
    while (i < position && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Vị trí vượt quá độ dài danh sách.\n");
        return;
    }

    // Cập nhật liên kết giữa các node
    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
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

    printf("Trước khi xóa:\n");
    printList(head);

    // Nhập vị trí cần xóa
    int position;
    printf("Nhập vị trí muốn xóa (>=1): ");
    scanf("%d", &position);

    // Gọi hàm xóa
    deleteAtPosition(&head, position);

    printf("Sau khi xóa:\n");
    printList(head);

    return 0;
}
