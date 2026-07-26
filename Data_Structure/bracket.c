#include<stdio.h>
#define MAX_SIZE 10
typedef enum
{
   False,True
}Bool;
typedef struct
{
    char val[MAX_SIZE];
    int top;
}Stack;
Stack create()
{
    Stack s;
    s.top=0;
    return s;
}
Bool isfull(Stack *s)
{
    return s->top==MAX_SIZE;
}
Bool isempty(Stack *s)
{
    return s->top==0;
}
void push(Stack *s,char val)
{
    if(isfull(s))
    {
      printf("overflow");
      return;
    }
    s->val[s->top]=val;
    s->top+=1;
}
Bool pop(Stack *s,char *val)
{
    if(isempty(s))
    {
      printf("underflow");
      return False;
    }
     s->top-=1;
    *val=s->val[s->top];

    return True;
}
int main()
{
    Stack s1=create();
    char ch[MAX_SIZE];
    char popval;
    Bool balanced = True;
    printf("Enter a string:");
    if(fgets(ch,sizeof(ch),stdin)!=NULL)
    {
        for(int i=0;ch[i]!='\0';i++)
        {
            if(ch[i]=='('||ch[i]=='['||ch[i]=='{')
                {
                  push(&s1,ch[i]);
                }
            else if(ch[i]==')'||ch[i]==']'||ch[i]=='}')
            {
                if (!pop(&s1, &popval))
                {
                    balanced = False;
                    break;
                }
                if ((ch[i] == ')' && popval != '(') ||
                    (ch[i] == ']' && popval != '[') ||
                    (ch[i] == '}' && popval != '{'))
                {
                    balanced = False;
                    break;
                }
            }
       }
    }
    if (balanced)
    {
        printf("balanced\n");
    }
    else
    {
        printf("not balanced\n");
    }
    return 0;
}

