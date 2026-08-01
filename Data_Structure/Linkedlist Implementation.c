#include <stdio.h>
#include <malloc.h>

typedef struct node {
    int data;
    struct node *next;
} NODE;

NODE *makenode(int data) {
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void display(NODE *l) {
    while(l) {
        printf("%5d", l->data);
        l = l->next;
    }
}

NODE *insertHead(NODE *l, int data) {
    NODE *temp = makenode(data);
    temp->next = l;
    return temp;
}

NODE *insertTail(NODE *l, int data) {
    NODE *temp = makenode(data);
    if (l == NULL) {
        return temp;
    }
    NODE *current = l;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = temp;
    return l;
}
int countNodes(NODE *l) {
    int count = 0;
    while (l != NULL) {
        count++;
        l = l->next;
    }
    return count;
}
int sumNodes(NODE *l) {
    int sum = 0;
    while (l != NULL) {
        sum += l->data;
        l = l->next;
    }
    return sum;
}
int searchElement(NODE *l, int key) {
    int position = 1;
    while (l != NULL) {
        if (l->data == key) {
            return position;
        }
        l = l->next;
        position++;
    }
    return 0;
}
int main() {
    NODE *l1 = makenode(100);
    NODE *l2 = NULL, *l3 = NULL;
    l1->next = makenode(500);
    l1 = insertHead(l1, 1000);
    l2 = insertTail(l2, 500);
    printf("\nList 1 : ");
    display(l1);
    printf("\n\n");
    printf("\nNode Count: %d | Sum: %d\n\n", countNodes(l1), sumNodes(l1));
    printf("\nList 2 : ");
    display(l2);
    printf("\n\n");
    l3 = insertHead(l3, 2000);
    printf("\nList 3 : ");
    display(l3);
    printf("\n\n");
    int key;
    printf("Enter the element to search: ");
    scanf("%d", &key);
    int pos = searchElement(l1, key);
    if (pos != 0) {
        printf("Element %d found at position: %d\n", key, pos);
    } else {
        printf("Element %d not found in the list.\n", key);
    }
    return 0;
}
