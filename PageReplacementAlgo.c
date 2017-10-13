#include<stdio.h>
int a[10],fr[10],n,i,j,k,temp,fsize,c,flag,h=0,fault=0,count[10]={9999};
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
        for(i=0;i<n;i++)
        {
                count[a[i]]=0;
        }
        for(i=0;i<fsize;i++)
        {
                fr[i]=a[i];
                fault++;
                count[a[i]]++;
        }


}
initialize1()
{
        flag=0;
        fault=0;
        printf("\nEnter the length of the page reference sequence: ");
        scanf("%d",&n);

        printf("\nEnter the page refernce string: \n");
        for(i=0;i<n;i++)
                scanf("%d",&a[i]);
        printf("\nEnter the number of frames: ");
        scanf("%d",&fsize);
        int ctr=0;
        for(i=0;i<fsize;i++)
        {       fault++;
                fr[ctr]=a[i];
                if(ctr>0)
                {
                        for(j=0;j<ctr;j++)
                        {
                                if(fr[ctr]==fr[j])
                                {
                                        for(k=j;k<ctr-1;k++)
                                        {
                                                fr[k]=fr[k+1];
                                        }
                                        fault--;
                                        flag=1;
                                }
                        }

                }
        if(flag==0)
                ctr++;
        printf("\n%d\t",fault);
        }
        printf("\n");
         for(i=0;i<fsize;i++)
                printf("%d",fr[i]);

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
        printf("\nFaults: %d\n",fault);
        printf("\nThe frame is:\n");
        for(i=0;i<fsize;i++)
                printf("%d",fr[i]);


}
lru()
{
        initialize();
        for(i=fsize;i<n;i++)
        {       printf("\n");
                 for(k=0;k<fsize;k++)
                printf("%d",fr[k]);

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
                        for(j=0;j<fsize-1;j++)
                                fr[j]=fr[j+1];
                        fr[j]=a[i];
                }
        printf("\n\t%d",fault);
        }

        printf("\nThe number of faults is: %d",fault);
        printf("\nThe frame is:\n");
        for(i=0;i<fsize;i++)
                printf("%d",fr[i]);

}
lfu()
{
         initialize();
        for(i=fsize;i<n;i++)
        {       printf("\n");
                 for(k=0;k<fsize;k++)
                printf("%d",fr[k]);

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
                        printf("\n Here with:%d",a[i]);
                        printf("\nthe page being enetered:%d",a[i]);
                        count[a[i]]++;
                        fault++;
                        int leastindex=0,least=count[fr[0]];
                        for(j=0;j<fsize;j++)
                        {
                                if(count[a[j]]<least)
                                {
                                        least=count[j];
                                        leastindex=j;
                                }
                        }
                        printf("\n LeastIndex:%d",leastindex);
                        fr[leastindex]=a[i];

                }
        printf("\n\t%d",fault);
        }

        printf("\nThe number of faults is: %d",fault);
        printf("\nThe frame is:\n");
        for(i=0;i<fsize;i++)
                printf("%d",fr[i]);


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
                case 3: lfu();
                        break;
                default:printf("\nINVALID CHOICE");
                        break;
        }
        }
}
