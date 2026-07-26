#include <stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10
typedef enum {
    False,
    True
} Bool;

typedef struct {
    int val[MAX_SIZE];
    int top;
} Stack;

Stack create() {
    Stack s;
    s.top = 0;
    for(int i=0;i<MAX_SIZE;i++)
    {
        s.val[i]=rand()%10;
        printf("%d ",s.val[i]);
        s.top++;
    }
    return s;
}

Bool isfull(Stack *s) {
    return s->top == MAX_SIZE;
}

Bool isempty(Stack *s) {
    return s->top == 0;
}

void push_even(Stack *s,Stack *s1) {

    for(int i=0;i<s->top;i++)
    {
        if (isfull(s1)) {
        printf("Overflow",s-> val[i]);
        break;
    }
     if(s->val[i]%2==0)
     {
        s1->val[s1->top]=s->val[i];
        printf("%d ", s1->val[s1->top]) ;
        s1->top += 1;
     }
    }
}
void push_odd(Stack *s,Stack *s2) {

    for(int i=0;i<s->top;i++)
    {
        if (isfull(s2)) {
        printf("Overflow",s-> val[i]);
        break;
    }
     if(s->val[i]%2!=0)
     {
        s2->val[s2->top]=s->val[i];
        printf("%d ", s2->val[s2->top]) ;
        s2->top += 1;
     }
    }
}
Bool pop(Stack *s, int *val) {
    if (isempty(s)) {
        printf("Underflow! Cannot pop\n");
        return False;
    }
    s->top -= 1;
    *val = s->val[s->top];

    return True;
}
int main() {
    Stack s= create();
    Stack s1;
    Stack s2;
    s1.top=0;
    s2.top=0;

    printf("\neven stack:");
    push_even(&s, &s1);
    printf("\nodd stack:");
    push_odd(&s, &s2);

    return 0;
}
