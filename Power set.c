//powerset
#include<stdio.h>
void powerset(int arr[],int n,int index,int subset[],int size)
{
    if(index==n)
    {
        if(size==0)
        {
            printf("{}");
        }
        else
        {
            printf("{");
            for(int i=0;i<size;i++)
            {
                printf("%d",subset[i]);
                 if (i < size - 1) printf(",");
            }
            printf("}\n");
        }
        return;
    }
    powerset(arr,n,index+1,subset,size);
    subset[size]=arr[index];
    powerset(arr,n,index+1,subset,size+1);
}
int main()
{
    int n;
    printf("enter value of n:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int subset[n];
    powerset(arr,n,0,subset,0);
}
