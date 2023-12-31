
#include<stdio.h>
#include<stdlib.h>


int i,n,m;

int findLRU(int time[])
{
   int i, minimum = time[0], pos = 0;
 
   for (i = 1; i < n; ++i)
   {
      if (time[i] < minimum)
      {
         minimum = time[i];
         pos = i;
      }
   }
 
   return pos;
}

void LRU(int prs[])
{
  int frames[10], counter = 0, time[10], flag1, flag2, i, j, pos, faults = 0,hit=0;
  for (i = 0; i < n; i++)
   {
      frames[i] = -1;
   }
   printf("Ref string\t  page frames\n");
   for (i = 0; i < m; i++)
   {
      printf("%d\t\t",prs[i]);
      flag1 = flag2 = 0;
 
      for (j = 0; j < n; j++)
      {
         if (frames[j] == prs[i])
         {
         	hit++;
            counter++;
            time[j] = counter;
            flag1 = flag2 = 1;
            break;
         }
      }
 
      if (flag1 == 0)
      {
         for (j = 0; j < n; j++)
         {
            if (frames[j] == -1)
            {
               counter++;
               faults++;
               frames[j] = prs[i];
               time[j] = counter;
               flag2 = 1;
               break;
            }
         }
      }
 
      if (flag2 == 0)
      {
         pos = findLRU(time);
         counter++;
         faults++;
         frames[pos] = prs[i];
         time[pos] = counter;
      }
 
      
 
      for (j = 0; j < n; ++j)
      {
        if(frames[j] != -1)
     	    printf("%d\t", frames[j]);
        else   
            printf("--\t");
      }
      printf("\n");
   }
 
   printf("\nTotal Page Faults = %d\n", faults);
   printf("No of hits:%d\n",hit);
 	printf("Hit Ratio:%d/%d\n",hit,m);
 	printf("Miss Ratio:%d/%d\n",faults,m);	
}

void FIFO(int prs[])
{
  int frame[50],j,avail,count=0,k,hit=0;
  for(i=0;i<n;i++)
  {
    frame[i]=-1;
    
  }
  j=0;
  printf("Ref string\t  page frames\n");
 for(i=0;i<m;i++)
 {
   printf("%d\t\t",prs[i]);
   avail=0;
   for(k=0;k<n;k++)
   {
    if(frame[k]==prs[i])
    {
    	hit++;
     	avail=1; 
    }
   }
    if(avail==0)
    {
     frame[j]=prs[i];
     j=(j+1)%n;
     count++;
     for(k=0;k<n;k++)
     {
       if(frame[k]==-1)
            printf("--\t");
       else
            printf("%d\t",frame[k]);
     }
    }
   printf("\n");
 }
 
 printf("\nTotal no of page faults:%d\n",count);
 printf("No of hits:%d\n",hit);
 printf("Hit Ratio:%d/%d\n",hit,m);
 printf("Miss Ratio:%d/%d\n",count,m);
} 

int findLFU(int time[])
{
   int i, minimum = time[0], pos = 0;
 
   for (i = 0; i < n; ++i)
   {
      if (time[i] < minimum)
      {
         minimum = time[i];
         pos = i;
      }
   }
 
   return pos;
}

void LFU(int prs[])
{
   int frames[10], counter = 0, time[10], flag1, flag2, i, j, pos, faults = 0,hit=0;
  for (i = 0; i < n; ++i)
   {
      frames[i] = -1;
   }
   printf("Ref string\t  page frames\n");
   for (i = 0; i < m; ++i)
   {
      printf("%d\t\t",prs[i]);
      flag1 = flag2 = 0;
 
      for (j = 0; j < n; ++j)
      {
         if (frames[j] == prs[i])
         {
         	hit++;
            counter++;
            time[j] = counter;
            flag1 = flag2 = 1;
            break;
         }
      }
 
      if (flag1 == 0)
      {
         for (j = 0; j < n; ++j)
         {
            if (frames[j] == -1)
            {
               counter++;
               faults++;
               frames[j] = prs[i];
               time[j] = counter;
               flag2 = 1;
               break;
            }
         }
      }
 
      if (flag2 == 0)
      {
         pos = findLFU(time);
         counter++;
         faults++;
         frames[pos] = prs[i];
         time[pos] = counter;
      }
 
      
 
      for (j = 0; j < n; ++j)
      {
        if(frames[j] != -1)
     	    printf("%d\t", frames[j]);
        else   
            printf("--\t");
      }
      printf("\n");
   }
 
   printf("\nTotal Page Faults = %d\n", faults);
   printf("No of hits:%d\n",hit);
 	printf("Hit Ratio:%d/%d\n",hit,m);
 	printf("Miss Ratio:%d/%d\n",faults,m);
}

void optimal(int prs[])
{
	int frames[10], flag1, flag2, i, j, pos, faults = 0,hit=0,temp[10],flag3,max,k;
	for (i = 0; i < n; ++i)
   	{
      frames[i] = -1;
  	 }
  	 printf("Ref string\t  page frames\n");
  	 for(i=0;i<m;i++)
  	 {
  	 	printf("%d\t\t",prs[i]);
  		flag1=flag2=0;
		for(j=0;j<n;j++)
		{
			if(frames[j]==prs[i])
			{
				hit++;
				flag1=flag2=1;
				break;	
			}  	
		} 
		if(flag1==0)
		{
			for(j=0;j<n;j++)
			{
				if(frames[j]==-1)
				{
					faults++;
					frames[j]=prs[i];
					flag2=1;
					break;
				}
			}
		}
		if(flag2 == 0){
         flag3 =0;
        
            for(j = 0; j < n; ++j){
             temp[j] = -1;
            
             for(k = i + 1; k < m; ++k){
             if(frames[j] == prs[k]){
             temp[j] = k;
             break;
             }
             }
            }
            
            for(j = 0; j < n; ++j){
             if(temp[j] == -1){
             pos = j;
             flag3 = 1;
             break;
             }
            }
            
            if(flag3 ==0){
             max = temp[0];
             pos = 0;
            
             for(j = 1; j < n; ++j){
             if(temp[j] > max){
             max = temp[j];
             pos = j;
             }
             }            
            }
			frames[pos] = prs[i];
			faults++;
					
		}
		for (j = 0; j < n; ++j)
      	{
            if(frames[j] != -1)
         	    printf("%d\t", frames[j]);
            else   
                printf("--\t");
      	}
      	printf("\n");	
	}
	printf("\nTotal Page Faults = %d\n", faults);
   printf("No of hits:%d\n",hit);
 	printf("Hit Ratio:%d/%d\n",hit,m);
 	printf("Miss Ratio:%d/%d\n",faults,m);
}

int main()
{
 int prs[50],k;
 printf("Enter no.of page frames:\n");
 scanf("%d",&n);
 printf("Enter no.of page reference string\n");
 scanf("%d",&m);
 printf("Enter page reference string:\n");
 for(i=0;i<m;i++)
 {
   scanf("%d",&prs[i]);
 }
 while(1)
 {

   printf("Choose an option\n1. FIFO\n2. LRU\n3. LFU\n4. Optimal\n5. Exit\n");
   scanf("%d", &k);
    switch(k)
    {
        case 1:
           FIFO(prs);
           break;
        case 2:
           LRU(prs);
           break;
        case 3: 
           LFU(prs);
           break;
    	case 4:
    		optimal(prs);
    		break;
        case 5:
           exit(0);
        default:
            printf("Invalid choice!\n");
    }
 }
 return 0;
}