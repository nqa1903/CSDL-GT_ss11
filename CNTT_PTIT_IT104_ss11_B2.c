#include <stdio.h>
#include <stdlib.h>

// BƯỚC 1: Định nghĩa cấu trúc cho một phần tử trong danh sách liên kết đôi
typedef struct Node {
    int data;              // Dữ liệu của node
    struct Node* next;     // Con trỏ trỏ tới node tiếp theo
    struct Node* prev;     // Con trỏ trỏ tới node trước đó
} Node;

// BƯỚC 2: Hàm tạo một node mới với giá trị cho trước
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Cấp phát bộ nhớ cho node mới
    if (newNode == NULL) {
        printf("Không thể cấp phát bộ nhớ.\n");
        exit(1); // Thoát nếu lỗi bộ nhớ
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// BƯỚC 3: Hàm thêm node vào cuối danh sách
void append(Node** head, int value) {
    Node* newNode = createNode(value); // Tạo node mới

    // Nếu danh sách đang rỗng, gán node mới làm phần tử đầu tiên
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Duyệt đến cuối danh sách
    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    // Nối node mới vào cuối danh sách
    temp->next = newNode;
    newNode->prev = temp; // Thiết lập liên kết ngược
}

// BƯỚC 4: Hàm duyệt và in toàn bộ danh sách liên kết đôi
void traverseList(Node* head) {
    int count = 1; // Biến đếm số thứ tự node
    while (head != NULL) {
        printf("Node %d: %d\n", count, head->data);
        head = head->next; // Di chuyển tới node tiếp theo
        count++;
    }
}

// BƯỚC 5: Hàm main – Tạo danh sách và gọi hàm duyệt
int main() {
    Node* head = NULL; // Khởi tạo danh sách rỗng

    // Thêm 5 phần tử bất kỳ vào danh sách
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    // Duyệt và in dữ liệu từng phần tử
    traverseList(head);

    return 0;
}
