#include<stdio.h>
#include <string.h>
#define MAX_SIZE 50
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
      return False;
    }
     s->top-=1;
    *val=s->val[s->top];

    return True;
}
int main()
{
    Stack s1=create();
    char ch1[MAX_SIZE];
    char ch2[MAX_SIZE];
    char popval1;
    char popval2;

    printf("Enter a string1:");
    if(fgets(ch1,sizeof(ch1),stdin)!=NULL)
    {
       int len = strlen(ch1);
       for(int i=0;i<len;i++)
       {
           if(ch1[i]=='\n')
           {
               continue;
           }
           if(ch1[i]=='#')
           {
               pop(&s1,&popval1);
           }
           else
            {
            push(&s1,ch1[i]);
           }
       }
    }
    while(!isempty(&s1))
    {
    pop(&s1,&popval1);
    printf("%c",popval1);
    }
    printf("\nEnter a string2:");
    if(fgets(ch2,sizeof(ch2),stdin)!=NULL)
    {
       int len = strlen(ch2);
       for(int i=0;i<len;i++)
       {
           if(ch2[i]=='\n')
           {
               continue;
           }
           if(ch2[i]=='#')
           {
               pop(&s1,&popval2);
           }
           else
           {
            push(&s1,ch2[i]);
           }
       }
    }
    while(!isempty(&s1))
    {
    pop(&s1,&popval2);
    printf("%c",popval2);
    }
    if(popval1==popval2)
    {
        printf("\nsame");
    }
    else{
        printf("\nnot same");
    }
    return 0;
}

