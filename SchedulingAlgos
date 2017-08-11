#include<stdio.h>
int wt[10],tat[10],bt[10];
double avgw=0,avgt=0;
void priorities(int P[][5],int *N)
{
  int i,j;
  for(i=0;i<*N;i++)
        {
                int swaps=0;
                for(j=0;j<*N-i-1;j++)
                {
                        if(P[j][4]>P[j+1][4])
                        {
                                int t=P[j][0];
                                int t2=P[j][1];
                                int t3=P[j][4];
                                P[j][0]=P[j+1][0];
                                P[j][1]=P[j+1][1];
                                P[j][4]=P[j+1][4];
                                P[j+1][0]=t;
                                P[j+1][1]=t2;
                                P[j+1][4]=t3;
                                swaps++;
                        }
                }
                if (swaps==0)
                        break;
        }
        return;
}
void sjf(int P[][5],int *N)
{
  int i,j;
  for(i=0;i<*N;i++)
        {
                int swaps=0;
                for(j=0;j<*N-i-1;j++)
                {
                        if(P[j][1]>P[j+1][1])
                        {
                                int t=P[j][0];
                                int t2=P[j][1];
                                P[j][0]=P[j+1][0];
                                P[j][1]=P[j+1][1];
                                P[j+1][0]=t;
                                P[j+1][1]=t2;
                                swaps++;
                        }
                }
                if (swaps==0)
                        break;
        }
        return;
}
void endpart(int P[][5],int *N)
{
    int i,j;
  double aw=0,at=0;
   P[0][2]=0;
        P[0][3]=P[0][1];
        for(i=1;i<*N;i++)
        {
                P[i][2]=P[i-1][2]+P[i-1][1];
                P[i][3]=P[i][2]+P[i][1];
        }
        printf("\nDisplaying the processes: ");
        printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
        for(i=0;i<*N;i++)
        {
        printf("\n%d\t\t%d\t\t%d\t\t%d\n",P[i][0],P[i][1],P[i][2],P[i][3]);
        aw+=P[i][2];
        at+=P[i][3];
        }
        printf("\nAverage waiting time is: %f",aw/(*N));
        printf("\nAverage turnaround time is: %f\n",at/(*N));

}
void insert(int P[][5],int *N)
{ int i;
  printf("\nEnter the burst times and priorities: ");
        for(i=0;i<*N;i++)
        {
                printf("\nProcess %d:",i+1);
                P[i][0]=i+1;
                scanf("%d",&P[i][1]);
                scanf("%d",&P[i][4]);
        }
}
int findwaitingtime()
{
  int count,j,n,time,remain,flag=0,time_quantum;
  int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10];
  printf("Enter the number of processes:\t ");
  scanf("%d",&n);
  remain=n;
  for(count=0;count<n;count++)
  {
    printf("Enter Burst Time for process %d\n",count+1);
    scanf("%d",&bt[count]);
    printf("Enter Arrival Time for process %d\n",count+1);
    scanf("%d",&at[count]);
    rt[count]=bt[count];
  }
  printf("Enter the time quantum:\t");
  scanf("%d",&time_quantum);
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
  time=count=0;
  while(remain!=0)
  {
    //Case where remaining time less than the time quantum
    if(rt[count]<=time_quantum && rt[count]>0)
    {
      time+=rt[count];
      rt[count]=0;
      flag=1;
    }
    //Case if remaining time greater than time quantum
    else if(rt[count]>0)
    {
      rt[count]-=time_quantum;
      time+=time_quantum;
    }
    if(rt[count]==0 && flag==1)
    {
      remain--;
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]);
      wait_time+=time-at[count]-bt[count];
      turnaround_time+=time-at[count];
      flag=0;
    }
    if(count==n-1)
      count=0;
    else if(at[count+1]<=time)
      count++;
    else
      count=0;
  }
  printf("\nAverage Waiting Time is : %f\n",wait_time*1.0/n);
  printf("\nAvg Turnaround Time is : %f",turnaround_time*1.0/n);

  return 0;
}

void main()
{
        int c,i,j,swaps,N,q,A[10][5]={0};
        printf("Enter the number of processes: ");
        scanf("%d",&N);
        printf("Enter the choice: 1)FCFS 2)SJF 3)Priorities 4)Round-Robin");
        scanf("%d",&c);
        switch (c)
        {
          case 1:insert(A,&N);
                  endpart(A,&N);
                  break;
          case 2:printf("Running shortest-job-first: \n");
                 insert(A,&N);
                 sjf(A,&N);
                 endpart(A,&N);
                 break;
          case 3:printf("Running priorities function: \n");
                 insert(A,&N);
                 priorities(A,&N);
                 endpart(A,&N);
                 break;
          case 4:findwaitingtime();
                  break;
        }

}
