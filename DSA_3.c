#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int nodeNumber;
    char bhavinichar;
    struct Node* next;
};

struct Node* head = NULL;

void insertAlphabet(char ch) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->nodeNumber = 0;
    newNode->bhavinichar = ch;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void deleteAlphabet(char ch) {
    struct Node* current = head;
    struct Node* prev = NULL;

    while (current != NULL) {
        if (current->bhavinichar == ch) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }

        prev = current;
        current = current->next;
    }
}

void printList() {
    struct Node* current = head;
    printf("Alphabets and Occurrences in Your Name:\n");
    while (current != NULL) {
        printf("%c: %d\n", current->bhavinichar, current->nodeNumber);
        current = current->next;
    }
}

void updateOccurrences() {
    struct Node* current = head;
    while (current != NULL) {
        current->nodeNumber = 0;
        struct Node* namePtr = head;
        while (namePtr != NULL) {
            if (current->bhavinichar == namePtr->bhavinichar) {
                current->nodeNumber++;
            }
            namePtr = namePtr->next;
        }
        current = current->next;
    }
}

void searchAndUpdate() {
    char alphabetToSearch;
    int choice;

    printf("Enter the alphabet to search for: ");
    scanf(" %c", &alphabetToSearch);

    struct Node* current = head;
    while (current != NULL) {
        if (current->bhavinichar == alphabetToSearch) {
            printf("'%c' found! What do you want to do?\n", alphabetToSearch);
            printf("1. Update occurrence\n");
            printf("2. Delete alphabet\n");
            printf("3. Do nothing\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1: {
                    int newOccurrence;
                    printf("Enter the new occurrence for '%c': ", alphabetToSearch);
                    scanf("%d", &newOccurrence);
                    current->nodeNumber = newOccurrence;
                    return;
                }
                case 2:
                    deleteAlphabet(alphabetToSearch);
                    return;
                case 3:
                    return;
                default:
                    printf("Invalid choice. Please try again.\n");
            }
        }
        current = current->next;
    }

    printf("'%c' not found in the list.\n", alphabetToSearch);
}

void traverseAndAddToString(char* str) {
    struct Node* current = head;
    while (current != NULL) {
        strncat(str, &(current->bhavinichar), 1);
        current = current->next;
    }
}

int main() {
    char name[100];
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Removing the trailing newline from fgets

    int i = 0;
    while (name[i] != '\0') {
        if (name[i] != ' ') {
            insertAlphabet(name[i]);
        }
        i++;
    }

    updateOccurrences();
    printList();

    // Test search and update
    searchAndUpdate();
    updateOccurrences();
    printList();

    // Traverse the linked list and add alphabets to a string
    char alphabetsString[100] = "";
    traverseAndAddToString(alphabetsString);
    printf("Alphabets in a string: %s\n", alphabetsString);

    return 0;
}