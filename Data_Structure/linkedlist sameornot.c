
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
int sameornot(NODE *l1, NODE *l2)
{
    while (l1 != NULL && l2 != NULL) {
        if (l1->data != l2->data) {
            return 0;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    if (l1 == NULL && l2 == NULL) {
        return 1;
    }
    return 0;
}
int main()
{
    NODE *l1 = makenode(100);
    NODE *l2 = makenode(100), *l3 = NULL;
    l1->next = makenode(500);
    l1 = insertHead(l1, 10);
    l2 = insertTail(l2, 500);
    l2 = insertHead(l2, 10);
    l2 = insertTail(l2, 500);
    printf("\nList 1 : ");
    display(l1);
    printf("\n\n");
    printf("\nList 2 : ");
    display(l2);
    printf("\n\n");
    l3 = insertHead(l3, 2000);
    printf("\nList 3 : ");
    display(l3);
    printf("\n\n");
    if(sameornot(l1, l2)) {
        printf("\nBoth are in same order");
    }
    else {
        printf("\nBoth are in different order");
    }
    return 0;
}
