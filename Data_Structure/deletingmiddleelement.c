#include <stdio.h>
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
    return s;
}
Bool isfull(Stack *s) {
    return s->top == MAX_SIZE ? True : False;
}
Bool isempty(Stack *s) {
    return s->top == 0 ? True : False;
}
void push(Stack *s, int val) {
    if (isfull(s)) {
        printf("Overflow! Cannot push %d\n", val);
        return;
    }
    s->val[s->top] = val;
    s->top += 1;

}
Bool pop(Stack *s, int *val) {
    if (isempty(s)) {
        return False;
    }
    s->top -= 1;
    *val = s->val[s->top];
    return True;
}

int main()
{
    Stack s1 = create();
    Stack s2 = create();
    int n;
    printf("enter no fo elements to be entered in the stack:");
    scanf("%d",&n);
    int arr[n];
    printf("enter the integers to be pushed into the stack:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++)
    {
       push(&s1,arr[i]);
    }
    int a;
    for(int i=0;i<n/2;i++)
    {
        pop(&s1,&a);
        push(&s2,a);
    }
    pop(&s1,&a);
    printf("After removing middle element:");
    while(!isempty(&s1))
    {
       pop(&s1,&a);
       push(&s2,a);
    }
    while(!isempty(&s2))
    {
       pop(&s2,&a);
       printf("%d ",a);
    }

    return 0;
}
