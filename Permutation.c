//permuatiom
#include<stdio.h>
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void generate(int arr[],int start,int end)
{
    if(start==end)
    {
        for(int i=0;i<=end;i++)
        {
             printf("%d",arr[i]);
        }
        printf("\n");
    }
    for(int i=start;i<=end;i++)
    {
       swap(&arr[start],&arr[i]);
       generate(arr,start+1,end);
       swap(&arr[start],&arr[i]);
    }
}
int main()
{
    int n;
    printf("enter vaue of n:");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=i+1;
    }
    printf("outputs:\n");
    generate(arr,0,n-1);
    return 0;
}
