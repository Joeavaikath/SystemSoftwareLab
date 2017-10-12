#include<stdio.h>
int n,m,i,j,available[10],max[10][10],allocation[10][10],need[10][10];
int request[10];
char finish[10];

int c=0;
void safety()
{
        int work[10];
        for(i=0;i<m;i++)
        {
        work[i]=available[i];
        }
        int i,j,flag=0,flag2=0;
         for(i=0;i<n;i++)
          {
          finish[i]='f';
          }
        while(c<n)
        {
        flag2=0;
        for(i=0;i<n;i++)
        {
                flag=0;
                for(j=0;j<m;j++)
                {
                  if(work[j]<need[i][j])
                    {flag=1;
                    break;
                    }
                }
                if(finish[i]=='f' && flag==0)
                {
                  printf("P%d---->",i);
                  for(j=0;j<m;j++)
                  {
                    work[j]=work[j]+allocation[i][j];
                  }  
                  finish[i]='t';
                  c++;
                  flag2=1;
                  break;
                }
        
        }
        if(flag2==0)
          break;
        }
                printf("%d",c);
                if(c==n)
                {
                        printf("\nState is safe");
                }
                else
                {
                  printf("\nNot a safe state!");
                }
}





void main()
{
        printf("\nEnter the number of processes and the number of resources: ");
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
        {
                printf("\nEnter the allocated resource data for process %d: ",i+1);
                for(j=0;j<m;j++)
                {
                        scanf("%d",&allocation[i][j]);
                }
        }
         for(i=0;i<n;i++)
          {
                  printf("\nEnter the max data for process %d:",i+1);
                  for(j=0;j<m;j++)
                        {
                        scanf("%d",&max[i][j]);
                        }
          }
        for(i=0;i<n;i++)
        {
                for(j=0;j<m;j++)
                {
                        need[i][j]=max[i][j]-allocation[i][j];
                }
        }
        printf("\nEnter the available resource values:\n");
        for(i=0;i<m;i++)
        {
                scanf("%d",&available[i]);
        }
        safety();
}
