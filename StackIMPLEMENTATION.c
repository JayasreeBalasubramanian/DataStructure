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
    printf("Pushed value is: %d\n", val);
}
Bool pop(Stack *s, int *val) {
    if (isempty(s)) {
        printf("Underflow! Cannot pop\n");
        return False;
    }
    s->top -= 1;
    *val = s->val[s->top];
    printf("Popped value is: %d\n", *val);
    return True;
}
int peek(Stack *s) {
    if (isempty(s)) {
        printf("Underflow! Cannot peek\n");
        return -9999;
    }
    return s->val[s->top - 1];
}
int main()
{
    Stack s1 = create();
    push(&s1, 10);
    push(&s1, 20);
    push(&s1, 30);
    int x;
    pop(&s1, &x);
    push(&s1, 30);
    printf("Peek value is: %d\n", peek(&s1));
    return 0;
}
