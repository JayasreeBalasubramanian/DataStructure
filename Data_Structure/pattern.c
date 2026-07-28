#include<stdio.h>
#define MAX 50
typedef enum
{
    False, True
}Bool;
typedef struct
{
    char val[MAX];
    int front, rear;
}Q;
void create(Q *q)
{
    q->front = 0;
    q->rear = 0;
}
Bool isfull(Q *q)
{
    return ((q->rear + 1) % MAX == q->front);
}
Bool isempty(Q *q)
{
    return (q->front == q->rear);
}
Bool insert(Q *q, char data)
{
    if(isfull(q))
        return False;

    q->rear = (q->rear + 1) % MAX;
    q->val[q->rear] = data;

    return True;
}
Bool deleteval(Q *q, char *data)
{
    if(isempty(q))
        return False;

    q->front = (q->front + 1) % MAX;
    *data = q->val[q->front];

    return True;
}
Bool pattern1(Q *q)
{
    char str[MAX], ch;
    int i = 0;
    scanf("%s", str);
    while(!isfull(q) && str[i] != '.')
    {
        insert(q, str[i]);
        i++;
    }
    if(str[i] != '.')
        return False;
    i++;
    while(!isempty(q) && str[i] != '\0')
    {
        deleteval(q, &ch);
        i++;
    }
    if(!isempty(q))
        return False;
    return True;
}
Bool pattern2(Q *q)
{
    char str[MAX], ch;
    int i = 0;
    scanf("%s", str);
    while(!isfull(q) && str[i] != '.')
    {
        insert(q, str[i]);
        i++;
    }
    if(str[i] != '.')
        return False;
    i++;
    while(!isempty(q) && str[i] != '.')
    {
        deleteval(q, &ch);
        i++;
    }
    if(str[i] != '.')
        return False;
    i++;
    while(!isfull(q) && str[i] != '\0')
    {
        insert(q, str[i]);
        i++;
    }
    while(!isempty(q))
    {
        deleteval(q, &ch);
    }
    return True;
}
Bool pattern3(Q *q)
{
    char str[MAX], ch;
    int i = 0, j;
    scanf("%s", str);
    while(!isfull(q) && str[i] != '.')
    {
        insert(q, str[i]);
        i++;
    }
    if(str[i] != '.')
        return False;
    i++;
    while(!isempty(q) && str[i] != '.')
    {
        deleteval(q, &ch);
        i++;
    }
    if(str[i] != '.')
        return False;
    i++;
    j = i;
    while(str[j] != '\0')
    {
        j++;
    }
    j--;
    while(j >= i && !isfull(q))
    {
        insert(q, str[j]);
        j--;
    }
    while(!isempty(q))
    {
        deleteval(q, &ch);
    }
    return True;
}
Bool pattern4(Q *q)
{
    char str[MAX], ch;
    int i = 0;

    scanf("%s", str);

    while(!isfull(q) && str[i] != '=')
    {
        insert(q, str[i]);
        i++;
    }

    if(str[i] != '=')
        return False;

    i++;

    while(!isempty(q) && str[i] != '\0')
    {
        deleteval(q, &ch);

        if(ch != str[i])
            return False;

        i++;
    }

    if(!isempty(q) || str[i] != '\0')
        return False;

    return True;
}

int main()
{
    Q q;
    int choice;
    printf("1. w.w\n");
    printf("2. w.w.w\n");
    printf("3. w.w.wreverse\n");
    printf("4. w=wreverse\n");
    printf("Enter choice: ");
    scanf("%d",&choice);
    create(&q);
    if(choice == 1)
    {
        if(pattern1(&q))
            printf("Valid");
        else
            printf("Invalid");
    }
    else if(choice == 2)
    {
        if(pattern2(&q))
            printf("Valid");
        else
            printf("Invalid");
    }
    else if(choice == 3)
    {
        if(pattern3(&q))
            printf("Valid");
        else
            printf("Invalid");
    }
    else if(choice == 4)
    {
        if(pattern4(&q))
            printf("Valid");
        else
            printf("Invalid");
    }
    else
    {
        printf("Invalid choice");
    }
    return 0;
}
