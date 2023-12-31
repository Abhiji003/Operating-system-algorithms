#include<stdio.h>
#include<stdlib.h>

int num_process,i,j,k;
int num_resource=3;
int max[10][3], alloc[10][3],available[10][3],f[10],ans[10];
int need[10][3],ind=0,f[10],avail[3],c=0,req[10],t_inst[5];
int t_alloc[5]={0,0,0,0,0};
char ch;
void safety()
{
    for(k=0;k<num_process;k++)
    {
        for(i=0;i<num_process;i++)
        {
            if(f[i]==0)
            {
                int flag = 0;
                for(j=0; j<num_resource; j++)
                {
                    if(need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    ans[ind++] = i;
                    for(int y=0; y<num_resource; y++)
                    {
                        avail[y] += alloc[i][y];
                    }
                    for(int k=0; k<num_resource; k++)
                        available[c][k] = avail[k];
                    c++;    
                    f[i] = 1;
                }
            }
        }
    }
    int flag=1;
    for(i=0;i<num_process;i++)
    {
        if(f[i]==0)
        {
            flag=0;
            printf("The following system is not safe\n");
            break;
        }
    }
    if(flag==1)
    {
        printf("Safe sequence is:\n");
        for(i=0;i<num_process - 1;i++)
            printf(" P%d ->",ans[i]);
        printf(" P%d",ans[num_process - 1]);
    }
}

void table()
{
    printf(" TABLE \n");
    printf("Process\tAllocation\tNeed\tAvailable\tMax\n");
    for(i=0;i<num_process;i++)
    {
        printf("P%d",i);
        printf("\t"); 
        for(j=0;j<num_resource;j++)
        {
            printf(" %d",alloc[i][j]);
        }
        printf("\t\t");
        for(j=0;j<num_resource;j++)
        {
            printf(" %d",need[i][j]);
        }
        printf("\t");
        for(j=0;j<num_resource;j++)
        {
            printf(" %d",available[i][j]);
        }
        printf("    \t");
        for(j=0;j<num_resource;j++)
        {
            printf(" %d",max[i][j]);
        }
        printf("\n");
    }
    printf("\nAvailabe memory:");
    for(j=0;j<num_resource;j++)
    {
        printf("%d ",available[num_process][j]);
    }
}

void resource_req()
{
    int x;
    printf("\nWoud you like to make a resource request?(y/n):\n");
    scanf(" %c",&ch);
    if(ch=='y')
    {
        printf("\nEnter the process name which needs additional resource:");
        scanf("%d", &x);

        for(i = 0; i < num_resource; i++)
        {
            printf("\nResource request for resource %d :", i + 1);
            scanf("%d", &req[i]);
        }
        int flag1 = 0, flag2 = 0;
        for (i = 0; i < num_resource; i++)
        {
            if (req[i] > need[x][i])
                flag1 = 1;
        }
        if (flag1 == 0)
        {
            for (i = 0; i < num_resource; i++)
            {
                if (req[i] > avail[i])
                    flag2 = 1;
            }
            if (flag2 == 0)
            {
                for (i = 0; i < num_resource; i++)
                {
                    avail[i] = available[0][i];
                    avail[i] -= req[i];
                    alloc[x][i] += req[i];
                    need[x][i] -= req[i];
                    available[0][i] = avail[i];
                }
            }
            table();
            safety();
        }    
    }
    else
    {
        table();
        safety();
    }
    
}

int main()
{
    printf("Enter number of processes:");
    scanf("%d",&num_process);
    printf("\n");
    printf("Enter the number of resource: ");
    scanf("%d",&num_resource);
    printf("\n");
    printf("Enter allocated spaces: \n");
    for(i=0;i<num_process;i++)
    {
        printf("P%d = ",i);
        for(j=0;j<num_resource;j++)
        {  
            scanf("%d",&alloc[i][j]);
            t_alloc[j]+=alloc[i][j];
        }
        printf("\n");
    }
    for(i=0;i<num_resource;i++)
        printf("%d",t_alloc[i]);
    printf("Enter the maximum space\n");
    for(i=0;i<num_process;i++)
    {
        printf("P%d = ",i);
        for(j=0;j<num_resource;j++)
        {
            scanf("%d",&max[i][j]);
        }
        printf("\n");
    }
    printf("Enter total insatnce:");
    for(i=0;i<num_resource;i++)
    {
        scanf("%d",&t_inst[i]);
    }
    printf("\n");    
    for(i=0;i<num_resource;i++)
    {
        available[c][i]=t_inst[i]-t_alloc[i];
        avail[i]=available[c][i]; 
    }   
    c++;
    printf("\n");
    for(k=0;k<num_process;k++)
        f[k]=0;
    for(i=0;i<num_process;i++)
    {
        for(j=0;j<num_resource;j++)
            need[i][j]=max[i][j] - alloc[i][j];
    }
    
    safety();
    table();
    resource_req();
    return 0;
}
