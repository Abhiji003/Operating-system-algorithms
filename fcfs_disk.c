#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i,j,k=0;
    printf("Enter the number of requests: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the requests: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Enter the head position: ");
    int head;
    scanf("%d",&head);
    int seek_count=0;
    for(i=0;i<n;i++)
    {
        seek_count+=abs(head-arr[i]);
        head=arr[i];
    }
    printf("Total seek time: %d\n",seek_count);
    return 0;
}