#include<stdio.h>
int main()
{
    int n,arr[30];
    printf("Enter size of array:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int max=arr[i];
        for(int j=i;j<n;j++)
        {
            if(arr[j]>max)
            {
                max = arr[j];
            }
            sum+=max;
        }

    }
    printf("sum is:%d",sum);
}
