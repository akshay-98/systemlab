#include<stdio.h>
void findwt(int processes[10],int waittime[10],int bursttime[10],int n,int turntime[10])
{
  waittime[0]=0;

  for(int i=1;i<n;i++)
  {
    waittime[i]=waittime[i-1]+bursttime[i-1];
  }
  findtt(processes,waittime,bursttime,n,turntime);
}
void findtt(int processes[10],int waittime[10],int bursttime[10],int n,int turntime[10])
{
  printf("process  waitingtime bursttime turnaroundtime \n");
  for(int i=0;i<n;i++)
  {
    turntime[i]=waittime[i]+bursttime[i];
    printf("%d            %d            %d             %d     \n",processes[i],waittime[i],bursttime[i],turntime[i]);
  }
}
void main()
{
  int processes[10],waittime[10],n,i,bursttime[10],turntime[10],small=0,smallpos=0,temp,temp1;
  printf("Enter the number of processes");
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    processes[i]=i;
  }

  for(i=0;i<n;i++)
  {
    printf("Enter bursttime[%d]:",i);
    scanf("%d",&bursttime[i]);
  }
  for(i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(bursttime[j]>bursttime[j+1])
      {
        temp=bursttime[j];
        temp1=processes[j];
        bursttime[j]=bursttime[j+1];
        processes[j]=processes[j+1];
        bursttime[j+1]=temp;
        processes[j+1]=temp1;
      }
    }
  }
  findwt(processes,waittime,bursttime,n,turntime);
}
