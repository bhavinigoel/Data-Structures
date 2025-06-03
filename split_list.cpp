#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void splitList(struct Node* head, struct Node** front, struct Node** back) {
    if (head == NULL || head->next == NULL) {
        *front = head;
        *back = NULL;
        return;
    }

    struct Node* ptr1 = head;
    struct Node* ptr2 = head->next;

    while (ptr2 != NULL) {
        ptr2 = ptr2->next;
        if (ptr2 != NULL) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }

    *front = head;
    *back = ptr1->next;
    ptr1->next = NULL;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d  ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* frontList = NULL;
    struct Node* backList = NULL;

    // Create a sample list
    for (int i = 6; i > 0; i--) {
        struct Node* newNode = new Node();
        newNode->data = i;
        newNode->next = head;
        head = newNode;
    }

    printf("Original List: ");
    printList(head);

    splitList(head, &frontList, &backList);

    printf("Front List: ");
    printList(frontList);

    printf("Back List: ");
    printList(backList);

    return 0;
}