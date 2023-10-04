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

struct Node* insertSorted(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL || data <= head->data) {
        newNode->next = head;
        return newNode;
    }
    struct Node* current = head;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

struct Node* mergeSortedLists(struct Node* l1, struct Node* l2) {
    struct Node* mergedList = NULL;
    while (l1 != NULL || l2 != NULL) {
        if (l1 != NULL && (l2 == NULL || l1->data <= l2->data)) {
            mergedList = insertSorted(mergedList, l1->data);
            l1 = l1->next;
        } else if (l2 != NULL) {
            mergedList = insertSorted(mergedList, l2->data);
            l2 = l2->next;
        }
    }
    return mergedList;
}

void displaySorted(struct Node* head) {
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

    printf("Enter the number of elements in the first sorted list: ");
    scanf("%d", &n1);
    printf("Enter the elements of the first sorted list:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &num);
        list1 = insertSorted(list1, num);
    }

    printf("Enter the number of elements in second sorted list: ");
    scanf("%d", &n2);
    printf("Enter the elements of the second sorted list:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &num);
        list2 = insertSorted(list2, num);
    }

    printf("First sorted list: ");
    displaySorted(list1);
    printf("Second sorted list: ");
    displaySorted(list2);

    struct Node* mergedList = mergeSortedLists(list1, list2);

    printf("Merged sorted list: ");
    displaySorted(mergedList);

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
    while (mergedList != NULL) {
        struct Node* temp = mergedList;
        mergedList = mergedList->next;
        free(temp);
    }

    return 0;
}

