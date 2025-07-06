#include <stdio.h>
#include <stdlib.h>

// BƯỚC 1: Khai báo cấu trúc cho một phần tử trong danh sách liên kết đôi
typedef struct Node {
    int data;              // Dữ liệu của phần tử
    struct Node* next;     // Con trỏ trỏ tới phần tử tiếp theo
    struct Node* prev;     // Con trỏ trỏ tới phần tử trước đó
} Node;

// BƯỚC 2: Hàm tạo một node mới với dữ liệu cho trước
Node* createNode(int value) {
    // Cấp phát bộ nhớ cho node mới
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Không thể cấp phát bộ nhớ.\n");
        exit(1); // Thoát chương trình nếu cấp phát thất bại
    }

    // Gán giá trị và thiết lập liên kết ban đầu
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// BƯỚC 3: Hàm thêm phần tử vào cuối danh sách liên kết đôi
void append(Node** head, int value) {
    // Tạo node mới
    Node* newNode = createNode(value);

    // Nếu danh sách đang rỗng, gán node mới làm phần tử đầu
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Duyệt đến phần tử cuối cùng trong danh sách
    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    // Gán node mới vào cuối danh sách
    temp->next = newNode;
    newNode->prev = temp; // Thiết lập liên kết ngược
}

// BƯỚC 4: Hàm in danh sách từ đầu đến cuối (chiều xuôi)
void printListForward(Node* head) {
    printf("Danh sách xuôi: ");
    while (head != NULL) {
        printf("%d ", head->data); // In giá trị từng phần tử
        head = head->next;
    }
    printf("\n");
}

// BƯỚC 5: Hàm in danh sách từ cuối về đầu (chiều ngược)
void printListBackward(Node* head) {
    // Duyệt đến phần tử cuối
    while (head != NULL && head->next != NULL)
        head = head->next;

    printf("Danh sách ngược: ");
    while (head != NULL) {
        printf("%d ", head->data); // In ngược các giá trị
        head = head->prev;
    }
    printf("\n");
}

// BƯỚC 6: Hàm main – Tạo danh sách và hiển thị kết quả
int main() {
    Node* head = NULL; // Khởi tạo danh sách rỗng

    // Thêm 5 phần tử bất kỳ vào danh sách
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    // In danh sách theo chiều xuôi và ngược
    printListForward(head);
    printListBackward(head);

    return 0;
}
