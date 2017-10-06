#include<stdio.h>
int a[10],fr[10],n,i,j,temp,fsize,c,flag,h=0,fault=0;
initialize()
{
        fault=0;
        printf("\nEnter the length of the page reference sequence: ");
        scanf("%d",&n);

        printf("\nEnter the page refernce string: \n");
        for(i=0;i<n;i++)
                scanf("%d",&a[i]);
        printf("\nEnter the number of frames: ");
        scanf("%d",&fsize);

        for(i=0;i<fsize;i++)
        {
                fr[i]=a[i];
                fault++;
        }


}
fifo()
{
        initialize();
        for(i=fsize;i<n;i++)
        {
                printf("\nFor data %d",a[i]);
                for(j=0;j<fsize;j++)
                {
                        if(a[i]==fr[j])
                        {
                                flag=1;
                                break;
                        }
                        flag=0;
                }
                if(flag==0)
                {
                        for(j=0;j<fsize-1;j++)
                                fr[j]=fr[j+1];

                        fr[j]=a[i];
                        fault++;
                }
                else
                        printf("\nNo fault");


        }
        printf("\nFaults: %d",fault);

}
lru()
{
        initialize();
        for(i=fsize;i<n;i++)
        {
                for(j=0;j<fsize;j++)
                {
                        if(a[i]==fr[j])
                        {
                                flag=1;
                                break;
                        }
                        flag=0;
                }
                if(flag==1)
                {
                        temp=fr[j];
                        for(;j<fsize-1;j++)
                                fr[j]=fr[j+1];
                        fr[j]=temp;
                }
                else
                {
                        fault++;
                        for(j=0;j<n;j++)
                                fr[j]=fr[j+1];
                        fr[j]=a[i];
                }
        }
        printf("%d",fault);
}

void main()
{
        while(c!=4)
        {
        printf("\nSelect which algorithm should be performed:\n1)FIFO\n2)LRU\n3)LFU\n4)EXIT ");
        scanf("%d",&c);

        switch (c)
        {
                case 1: fifo();
                        break;
                case 2: lru();
                        break;
                case 3: //lfu();
                        break;
                default:printf("\nINVALID CHOICE");
                        break;
        }
        }
}
