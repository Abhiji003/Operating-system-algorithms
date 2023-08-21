#include<stdio.h>
#include<stdlib.h>
void fcfs(int ord[],int req1[],int init,int n)
{
    int seek[10]={0},totaltime=0,i,j;
    ord[0]=init;
    for(j=0;j<=n;j++)
    {
        ord[j+1]=req1[j];
        seek[j]=abs(ord[j]-ord[j+1]);
    }
    printf("\nthe order of fcfs disc scheduling is:");
    for(i=0;i<n;i++)
    {
        printf("%d--->",ord[i]);
    }
    printf("%d\n",ord[i]);
    printf("FCFS total seek time is:");
    for(j=0;j<n;j++)
    {
        totaltime+=seek[j];
    }
    printf("%d",totaltime);
}

void sstf(int req[],int init,int n)
{
    int i,j,totaltime=0;
    for (i=0;i<n-1;i++) 
    {
        for (j= 0;j<n-i-1;j++) 
        {
            if (req[j]>req[j+1]) 
            {
                int temp = req[j];
                req[j] = req[j + 1];
                req[j + 1] = temp;
            }
        }
    }
    int pos;
    for (pos= 0;pos < n; pos++) 
    {
        if (req[pos]>init)
        break;
    }
    int temp1=abs(init-req[pos-1]);
    int temp2=abs(init-req[pos]);
    if(temp2<temp1)
    {
        printf("the order of SSTF is:");
        printf("%d--->",init);
        for (i = pos;i<n; i++) 
        {
            totaltime+=abs(init-req[i]);
            init=req[i];
            printf("%d--->",req[i]);
        }
        for (i = pos - 1; i >= 0; i--) 
        {
            totaltime+= abs(init-req[i]);
            init=req[i];
            printf("%d--->",req[i]);
        }
    }      
    else
    {
        printf("the order of SSTF is:");
        printf("%d--->",init);
        for (i = pos - 1; i >= 0; i--) 
        {
            totaltime+= abs(init-req[i]);
            init=req[i];
            printf("%d--->",req[i]);
        }
        for (i = pos;i<n; i++) 
        {
            totaltime+=abs(init-req[i]);
            init=req[i];
            printf("%d--->",req[i]);
        }
    }
    printf("\n Total Seek Time: %d\n",totaltime);
}

void scan(int req[],int init,int n,int limit)
{
    int i,j,totaltime=0;
    for (i=0;i<n-1;i++) 
    {
        for (j= 0;j<n-i-1;j++) 
        {
            if (req[j]>req[j+1]) 
            {
                int temp = req[j];
                req[j] = req[j + 1];
                req[j + 1] = temp;
            }
        }
    }
    int pos;
    for (pos= 0;pos < n; pos++) 
    {
        if (req[pos]>init)
            break;
    }
    printf("the order of SCAN is:");
    printf("%d--->",init);
    for (i = pos;i<n; i++) 
    {
        totaltime+=abs(init-req[i]);
        init=req[i];
        printf("%d--->",req[i]);
    }   
    printf("%d--->",limit);
    totaltime+=abs(init-limit);
    init=limit;
    for (i = pos - 1; i >= 0; i--) 
    {
        totaltime+= abs(init-req[i]);
        init=req[i];
        printf("%d--->",req[i]);
    }
    printf("\nSCAN Total Seek Time: %d\n",totaltime);
}

void cscan(int req[],int init,int n,int limit)
{
    int i,j,totaltime=0;
    for (i=0;i<n-1;i++)     
    {
        for (j= 0;j<n-i-1;j++) 
        {
            if (req[j]>req[j+1]) 
            {
                int temp = req[j];
                req[j] = req[j+1];
                req[j+1] = temp;
            }
        }
    }
    int pos;
    for (pos= 0;pos < n; pos++) 
    {
        if (req[pos]>init)
            break;
    }
    printf("the order of CSCAN is:");
    printf("%d--->",init);
    totaltime+=(limit-init);
    totaltime+=(limit);
    for (i = pos;i<n; i++) 
    {
        init=req[i];
        printf("%d--->",req[i]);
    }
    printf("%d--->0--->",limit);
    for (i =0; i<pos;i++) 
    {
        init=req[i];
        printf("%d--->",req[i]);
    }
    totaltime+=init;
    printf("\nCSCAN Total Seek Time: %d\n",totaltime);
}

void look(int req[],int init,int n,int limit)
{
    int i,j,totaltime=0;
    for (i=0;i<n-1;i++) 
    {
        for (j= 0;j<n-i-1;j++) 
        {
            if (req[j]>req[j+1]) 
            {
                int temp = req[j];
                req[j] = req[j + 1];
                req[j + 1] = temp;
            }
        }
    }
    int pos;
    for (pos= 0;pos < n; pos++) 
    {
        if (req[pos]>init)
            break;
    }
    printf("the order of LOOK is:");
    printf("%d--->",init);
    for (i = pos;i<n; i++) 
    {
        totaltime+=abs(init-req[i]);
        init=req[i];
        printf("%d--->",req[i]);
    }
    for (i = pos - 1; i >= 0; i--) 
    {
        totaltime+= abs(init-req[i]);
        init=req[i];
        printf("%d--->",req[i]);
    }
    printf("\nLOOK Total Seek Time: %d\n",totaltime);
}

void clook(int req[],int init,int n,int limit)
{
    int i,j,totaltime=0;
    for (i=0;i<n-1;i++) 
    {
        for (j= 0;j<n-i-1;j++) 
        {
            if (req[j]>req[j+1]) 
            {
                int temp = req[j];
                req[j] = req[j+1];
                req[j+1] = temp;
            }
        }
    }
    int pos;
    for (pos= 0;pos < n; pos++) 
    {
        if (req[pos]>init)
            break;
    }
    printf("the order of CLOOK is:");
    printf("%d--->",init);
    for (i = pos;i<n; i++) 
    {
        totaltime+=abs(init-req[i]);
        init=req[i];
        printf("%d--->",req[i]);
    }
    for (i =0; i<pos;i++)   
    {
        totaltime+= abs(init-req[i]);
        init=req[i];
        printf("%d--->",req[i]);
    }
    printf("\nCLOOK Total Seek Time: %d\n",totaltime);
}

void main()
{ 
    int n,i,j,req[10],req1[10],init,ord[10]={0},choice,limit;
    printf("enter the total number of requests:");
    scanf("%d",&n);
    printf("\nenter the head posiion:");
    scanf("%d",&init);
    printf("\nenter the requests:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
        req1[i]=req[i];
    }
    printf("\nenter the max limit:");
    scanf("%d",&limit);
    while(1 == 1)
    {
        printf("\nPage Replacement Algorithms\n");
        printf("1. FCFC\n2.SSTF\n3. SCAN\n4. C-SCAN\n5. LOOK\n6. C-LOOK\n7. EXIT ");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
            printf("FCFS disc scheduling\n");
            fcfs(ord,req1,init,n);
            break;
            case 2:
            printf("SSTF disc scheduling\n");
            sstf(req,init,n);
            break;
            case 3:
            printf("SCAN disc scheduling\n");
            scan(req,init,n,limit);
            break;
            case 4:
            printf("CSCAN disc scheduling\n");
            cscan(req,init,n,limit);
            break;
            case 5:
            printf("LOOK disc scheduling\n");
            look(req,init,n,limit);
            break;
            case 6:
            printf("CLOOK disc scheduling\n");
            clook(req,init,n,limit);
            break;
            case 7:
            exit(0);
            break;
            default:
            printf("Invalid choice.\n");
            break;
        }
    }
}