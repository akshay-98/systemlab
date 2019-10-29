#include<stdio.h>
#include<string.h>
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
    printf("%d            %d            %d             %d     \n",i,waittime[i],bursttime[i],turntime[i]);
  }
}
void main()
{
  int processes[10],waittime[10],n,i,bursttime[10],turntime[10];
  printf("Enter the number of processes");
  scanf("%d",&n);

  for(i=0;i<n;i++)
  {
    printf("Enter the bursttime[%d]:",i);
    scanf("%d",&bursttime[i]);
  }
  findwt(processes,waittime,bursttime,n,turntime);
}
