#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

struct Node* findIntersection(struct Node* list1, struct Node* list2) {
    struct Node* intersection = NULL;
    struct Node* current1 = list1;

    while (current1 != NULL) {
        struct Node* current2 = list2;
        while (current2 != NULL) {
            if (current1->data == current2->data) {
                insertEnd(&intersection, current1->data);
                break;
            }
            current2 = current2->next;
        }
        current1 = current1->next;
    }

    return intersection;
}

void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    int n1, n2, num;

    printf("Enter the number of elements in the first list: ");
    scanf("%d", &n1);
    printf("Enter the elements of the first list:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &num);
        insertEnd(&list1, num);
    }

    printf("Enter the number of elements in the second list: ");
    scanf("%d", &n2);
    printf("Enter the elements of the second list:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &num);
        insertEnd(&list2, num);
    }

    printf("First list: ");
    displayList(list1);
    printf("Second list: ");
    displayList(list2);

    struct Node* intersection = findIntersection(list1, list2);

    printf("Intersection of the two lists: ");
    displayList(intersection);

    while (list1 != NULL) {
        struct Node* temp = list1;
        list1 = list1->next;
        free(temp);
    }
    while (list2 != NULL) {
        struct Node* temp = list2;
        list2 = list2->next;
        free(temp);
    }
    while (intersection != NULL) {
        struct Node* temp = intersection;
        intersection = intersection->next;
        free(temp);
    }
  return 0;
}

