#include<stdio.h>

int i,j,pos,head,temp,max,pro[20],n,diff=0,seek=0;
char s;

void fcfs()
{
        for(i=0;i<n;i++)
        {
                diff=abs(pro[i+1]-pro[i]);
                seek+=diff;
        }
        printf("\n%d %d",seek,seek/n);
}

void d_scan()
{
        printf("\nEnter the maximum number of cylinders: ");
        scanf("%d",&max);
        for(i=0;i<n+1;i++)
        {
                for(j=0;j<n-i;j++)
                {
                        if(pro[j]>pro[j+1])
                        {
                                temp=pro[j];
                                pro[j]=pro[j+1];
                                pro[j+1]=temp;
                        }
                }
        }

        for(i=0;i<n+1;i++)
        {
                printf("<%d>",pro[i]);
        }

        for(i=0;i<n;i++)
        {
                 if(head==pro[i])
                        break;
        }
        pos=i;
        printf("%d",pro[pos]);
        for(i=pos;i<n;i++)
        {
                diff=pro[i+1]-pro[i];
                seek+=diff;
        }
        seek+=max-pro[i];
        seek+=pro[0];
        for(i=0;i<pos-1;i++)
        {
                diff=pro[i+1]-pro[i];
                seek+=diff;
        }
        seek+=max;

        printf("\n%d %d",seek,seek/n);



}

void dn_scan()
{
         printf("\nEnter the maximum number of cylinders: ");
          scanf("%d",&max);
          for(i=0;i<n+1;i++)
          {
                  for(j=0;j<n-i;j++)
                  {
                         if(pro[j]>pro[j+1])
                          {
                                  temp=pro[j];
                                  pro[j]=pro[j+1];
                                  pro[j+1]=temp;
                         }
                  }
          }
        for(i=0;i<n;i++)
        {
                if(head==pro[i])
                        break;
        }
        pos=i;
        for(i=pos;i<n;i++)
        {
                diff=pro[i+1]-pro[i];
                seek+=diff;
        }
        seek+=max-pro[i];
        seek+=abs(max-pro[pos-1]);
        for(i=pos-1;i>0;i--)
        {
                diff=abs(pro[i-1]-pro[i]);
                seek+=diff;
        }
        printf("\n%d \n%d\n",seek,seek/n);


}

void main()
{
        printf("\nEnter the total number of processes: ");
        scanf("%d",&n);

        printf("\nEnter the cylinder numbers: ");
        for(i=1;i<n+1;i++)
                scanf("%d",&pro[i]);
        printf("\nEnter the head position: ");
        scanf("%d",&pro[0]);
        head=pro[0];

        printf("\nEnter the algorithm to perform: \n1)FCFS\n2)SCAN\n3)C-SCAN\n\n");
        scanf("%c",&s);
        scanf("%c",&s);

        switch (s)
        {
                case '1':       fcfs();
                        break;

                case '2':dn_scan();
                        break;
                case '3': d_scan();
                        break;
        }
}
