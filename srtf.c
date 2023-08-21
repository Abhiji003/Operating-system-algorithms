#include<stdio.h>
#include<stdlib.h>
int main() {
    int n,i,c;
    int j, time = 0, totalwt = 0, totaltat = 0, totalrespt = 0, current = -1;
    float throughput;
    int at[n],bt[n],rt[n],ct[n],wt[n],tat[n],respt[n],pid[n];
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("\nEnter the arrival time and burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("\nProcess P%d\n", i);
        pid[i]= i;
        printf("Arrival time: ");
        scanf("%d", &at[i]);
        printf("Burst time: ");
        scanf("%d", &bt[i]);
    }
    printf("Performing Preemptive SJF(SRTF)\n");
    for (i = 0; i < n; i++) {
        rt[i] = bt[i];
        respt[i]=-1;
    }
    while (1) {
        int shortest = 99, index = -1;
        for (i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] <= shortest && rt[i] > 0) {
                shortest = rt[i]; 
                index = i;  
            }
        }
        if (index == -1) {
            printf("waiting...");
            time++;
            continue;
        }
        if (current != index) {
            printf("Process P%d starts at time %d\n", pid[index], time);
            if(respt[index]==-1)
            	{respt[index] = time - at[index];}
            current = index;
        }
        rt[index]--;
        time++;
        if (rt[index] == 0) {
            ct[index] = time;
            wt[index] = ct[index] - at[index] - bt[index];
            tat[index] = ct[index] - at[index];
            totalwt += wt[index];
            totaltat += tat[index];
            totalrespt += respt[index];
            current = -1;
        }
        int f = 1;
        for (i = 0; i < n; i++) {
            if (rt[i] > 0) {
                f = 0;
                break;
            }
        }
        if (f) 
         break;
    }

    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\tResponse Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], at[i], bt[i], ct[i], wt[i], tat[i], respt[i]);
    }
    printf("\nAverage waiting time: %f\n", (float)totalwt / n);
    printf("Average turnaround time: %f\n", (float)totaltat / n);
    printf("Average response time: %f\n", (float)totalrespt / n);
    throughput = (float)n / time;
    printf("Throughput: %f processes per unit time\n", throughput);
    return 0;
    }  
