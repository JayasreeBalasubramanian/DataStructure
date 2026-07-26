//TOWER OF HANOI
#include<stdio.h>
void tower(int n,int from,int aux,int to)
{
    if(n==1)
    {
        printf("Move disk 1 from %d to %d\n", from, to);
        return;
    }
    tower(n-1,from,to,aux);
    printf("move disk %d from %d to %d\n",n,from,to);
    tower(n-1,aux,from,to);
    }
int main()
{
  int n;
  printf("enter n:");
  scanf("%d",&n);
  tower(n,1,2,3);
}
