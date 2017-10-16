#include<stdio.h>
int i,CompletedPhilo=0;

struct fork
{
	int taken;
}ForkNo[4];

struct Philosopher{
	int left;
	int right;
}PhilNo[4];

void Dinner(int PhilID)
{
	
	if(PhilNo[PhilID].left==10 && PhilNo[PhilID].right==10)
		printf("\nPhilosopher %d has completed dinner!",PhilID+1);
	else if(PhilNo[PhilID].left==1 && PhilNo[PhilID].right==1)
	{
		printf("\nPhilosopher %d has completed dinner!",PhilID+1);
		
		PhilNo[PhilID].left=PhilNo[PhilID].right=10;
		int otherfork=PhilID-1;
		
		if(otherfork==-1)
			otherfork=3;
		ForkNo[PhilID].taken=ForkNo[otherfork].taken=0;
		printf("\n Philospher %d released fork %d and fork %d",PhilID+1,PhilID+1,otherfork+1);
		CompletedPhilo++;
	}
	else if(PhilNo[PhilID].left==1 && PhilNo[PhilID].right==0)
	{
		if(PhilID==3)
		{
			if(ForkNo[PhilID].taken==0)
			{
				ForkNo[PhilID].taken=PhilNo[PhilID].right=1;
				printf("\nFork %d taken by Philosopher %d\n",PhilID+1,PhilID+1);
			}
			else
			{
				printf("\nPhilosopher %d is waiting for fork %d\n",PhilID+1,PhilID+1);
			}
		}
		else
		{
			int dupPhilID=PhilID;
			PhilID--;
			
			if(PhilID==-1)
				PhilID=3;
			
			if(ForkNo[PhilID].taken==0)
			{
				ForkNo[PhilID].taken=PhilNo[dupPhilID].right=1;
				printf("\nFork %d taken by philosopher %d\n",PhilID+1,dupPhilID+1);
			}
			else
			{
				printf("\nPhilosopher %d is waiting for fork %d",dupPhilID+1,PhilID+1);
			}
		}
	}
	else if(PhilNo[PhilID].left==0)
	{
		if(PhilID==3)
		{
			if(ForkNo[PhilID-1].taken==0)
			{
				ForkNo[PhilID-1].taken=PhilNo[PhilID].left=1;;
				printf("\nFork %d taken by philosopher %d\n",PhilID,PhilID+1);
			}
			else
			{
				printf("\nPhilosopher %d is waiting for fork %d\n",PhilID+1,PhilID);
			}
		}
		else
		{
			if(ForkNo[PhilID].taken==0)
			{
				ForkNo[PhilID].taken=PhilNo[PhilID].left=1;
				printf("\nFork %d taken by philosopher %d\n",PhilID+1,PhilID+1);
			}	
				else
				{
					printf("\nPhilospher %d is waiting for fork %d\n",PhilID+1,PhilID+1);
				}
			
		}
	}else{}
}
	
void main()
{
	for(i=0;i<4;i++)
	 ForkNo[i].taken=PhilNo[i].left=PhilNo[i].right=0;

	while(CompletedPhilo<4)
	{
		for(i=0;i<4;i++){
			Dinner(i);
		}
		printf("\n Till now number of philosophers completed dinner is:%d\n",CompletedPhilo);
	}
}
	
			
				
				
				












