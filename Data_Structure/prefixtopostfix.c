#include <stdio.h>
#define MAX 10
typedef enum {
    False,
    True
} Bool;
typedef struct {
    char val[MAX];
    int top;
} Stack;
Stack create()
{
    Stack s;
    s.top = 0;
    return s;
}
Bool isfull(Stack *s)
{
    return s->top == MAX ? True : False;
}
Bool isempty(Stack *s)
{
    return s->top == 0 ? True : False;
}
void push(Stack *s, char val)
{
    if(isfull(s))
        return;
    s->val[s->top] = val;
    s->top++;
}
Bool pop(Stack *s, char *val)
{
    if(isempty(s))
        return False;
    s->top--;
    *val = s->val[s->top];
    return True;
}
int priority(char ch)
{
    if(ch == '+' || ch == '-')
        return 1;
    if(ch == '*' || ch == '/')
        return 2;
    if(ch == '^')
        return 3;
    return 0;
}
void postfix(Stack *s)
{
    char infix[MAX], post[MAX];
    char ch;
    int i = 0, j = 0;
    scanf("%s", infix);
    while(infix[i] != '\0')
    {
        ch = infix[i];
        if((ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z') ||
           (ch >= '0' && ch <= '9'))
        {
            post[j++] = ch;
        }
        else if(ch == '(')
        {
            push(s, ch);
        }
        else if(ch == ')')
        {
            while(!isempty(s) && s->val[s->top-1] != '(')
            {
                pop(s, &ch);
                post[j++] = ch;
            }
            pop(s, &ch);
        }
        else
        {
            while(!isempty(s) &&
                  priority(s->val[s->top-1]) >= priority(ch))
            {
                pop(s, &ch);
                post[j++] = ch;
            }
            push(s, ch);
        }
        i++;
    }
    while(!isempty(s))
    {
        pop(s, &ch);
        post[j++] = ch;
    }
    post[j] = '\0';
    printf("Postfix: %s", post);
}
int main()
{
    Stack s1 = create();
    postfix(&s1);
    return 0;
}

