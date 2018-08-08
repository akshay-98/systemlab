#include<stdio.h>
int priority[10];
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
    printf("%d            %d            %d             %d     \n",priority[i],waittime[i],bursttime[i],turntime[i]);
  }
}
void main()
{
  int processes[10],waittime[10],n,i,bursttime[10],turntime[10],temp,temp1,burst[10];
  printf("Enter the number of processes");
  scanf("%d",&n);

  for(i=0;i<n;i++)
  {
    printf("Enter the bursttime[%d]:",i);
    scanf("%d",&bursttime[i]);
  }
  printf("Enter the priority order");
  for(int i=0;i<n;i++)
  {
    scanf("%d",&priority[i]);

  }
  for(i=0;i<n;i++)
  {
    burst[i]=bursttime[priority[i]];
  }
  for(i=0;i<n;i++)
  {
    bursttime[i]=burst[i];
  }
  findwt(processes,waittime,bursttime,n,turntime);
}
