/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//round robin//
#include <stdio.h>
#include<stdlib.h>

int main()
{
    int n,i,j,bt[10],rt[10],at[10],ts,sequ[10];
    int remain,sumwt=0,sumtat=0,time,flag=0,index=0;
 printf("number of process");
 scanf("%d",&n);
 remain=n;

 for(i=0;i<n;i++)
 {
     printf("enter the burst time");
 scanf("%d",&bt[i]);
 printf("enter the arrival time: ");
 scanf("%d",&at[i]);
 rt[i]=bt[i];
 }
 printf("enter the time slice:");
 scanf("%d",&ts);
 
 for(time=0,i=0;remain!=0;)
 {
     if(rt[i]<=ts&&rt[i]>0)
     {
         time+=rt[i];
         rt[i]=0;
         flag=1;
     }
     else if(rt[i]>0)
     {
         rt[i]-=ts;
         time+=ts;
         
     }
     
     if(rt[i]==0&&flag==1)
     {
         sequ[index++]=i;
         remain--;
         
         sumwt+=time-at[i]-bt[i];
         sumtat+=time-at[i];
         flag=0;
     }
     
     if(i==n-1)
     i=0;
     else if(at[i+1]<=time)
     
         i++;
     
     else
     i=0;
 
 }
 printf("total waiting time=%d\n",sumwt);
 printf("total tat time=%d\n",sumtat);
 printf("average waiting time=%.2f\n",(float)sumwt/n);
 printf("avg tat time=%.2f\n",(float)sumtat/n);
 //gantt chart//
 printf("\n------------------------------\n");
 for(int i=0 ; i < index ; i++)
 printf("|P%d\t|",sequ[i] + 1);
 printf("\n------------------------------\n");
 return 0;
}