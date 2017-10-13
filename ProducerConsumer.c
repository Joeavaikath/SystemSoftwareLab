#include<stdio.h>
int empty,x=0,mutex=1,full=0;

void producer()
{
        mutex=wait(mutex);
        full=signal(full);
        empty=wait(empty);
        x++;
        printf("\nProducer produces into buffer item:%d",x);
        mutex=signal(mutex);
}

void consumer()
{
        mutex=wait(mutex);
        empty=signal(empty);
        full=wait(full);
        printf("\nConsumer consumes from buffer item:%d",x);
        x--;
        mutex=signal(mutex);
}

int wait(int a)
{
        return(--a);
}

int signal(int a)
{
        return(++a);
}

void main()
{

        int c;
        printf("\nEnter the size of buffer:");
        scanf("%d",&empty);
        printf("\nEnter what process run:\n1)Producer\n2)Consumer\n3)Exit");
        while(1)
        {
                printf("\nEnter the choice:");
                scanf("%d",&c);
                switch (c)
                {
                        case 1: if((mutex==1)&&(empty!=0))
                                producer();
                                else
                                        printf("\nBuffer full!!");
                                break;
                        case 2: if((mutex==1)&&(full!=0))
                                consumer();
                                else
                                        printf("\nBuffer empty!!");
                                break;
                        case 3: exit(0);
                                break;
                }
        }
}

