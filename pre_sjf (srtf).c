#include <stdio.h>
void main()
{
	int n,q=0,opt,i,j=0,totalwt=0,totaltat=0,totalrt=0,prev;
	float totalbt=0;
	printf("Enter the number of processes:");
	scanf("%d",&n);
	int at[n],bt[n],compt[n],burst[n],tat[n],wt[n],time=0,count=0,current;
	for (i=0;i<n;i++)
	{
		printf("\nEnter the arrival time of process %d:",i);
		scanf("%d",&at[i]);
		printf("\nEnter the burst time of process %d:",i);
		scanf("%d",&bt[i]);
		burst[i]=bt[i];
	}
	time=at[0];
	current=-1;
	printf("\nGANTT CHART\nP0\t0");
	while (count!=n)
	{
		i=(current+1)%n;
		while (i!=current)
		{
			if (bt[i]!=0 && at[i]<=time)
			{
				current=i;
				break;
			}
			i=(i+1)%n;
		}
		while(bt[current]!=0 && j<q)
		{
			bt[current]--;
			j++;
		}
		while(j!=0)
		{
			j--;
			time++;
		}
		if (bt[current]==0)
		{
			count++;
			compt[current]=time;
			tat[current]=compt[current]-at[current];
			wt[current]=tat[current]-burst[current];
		}
		printf("\nP%d\t%d",current,time);
	}
	printf("\nPROCESS ID\tARRIVAL TIME\tBURST TIME\tCOMPLETION TIME\tTURNAROUND TIME\t WAITING TIME\n");
	for (i=0;i<n;i++)
	{
		totalwt+=wt[i];
		totaltat+=tat[i];
		totalbt+=burst[i];
		totalrt+=rt[i];
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t %d\n",i,at[i],burst[i],compt[i],tat[i],wt[i]);
	}
	printf("\nAverage waiting time:%d\n",(totalwt/n));
	printf("Average turnaround time:%d\n",(totaltat/n));
	printf("Throughput:%f\n",((float)n)/totalbt);
	printf("Average response time:%f\n",((float)totalrt)/n);
}
	
