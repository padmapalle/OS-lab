/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<stdio.h>

void main()
{
    int i,pid[10],n,burst[10],wt[10],ta[10];
    float avgwt=0,avgta=0;
    printf("enter the number of processes\n");
    scanf("%d",&n);
    printf("enter the process id and it's burst time\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&pid[i]);
        scanf("%d",&burst[i]);
    }
    wt[0]=0;
    printf("according first come first serve schedule\n");
    for(i=0;i<n;i++)
    {
        printf("processor id %d\t",pid[i]);
        printf("burst time %d\n",burst[i]);
    }
    for(i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+burst[i-1];
    }
    for(i=0;i<n;i++)
    {
        ta[i]=wt[i]+burst[i];
    }
    for(i=0;i<n;i++)
    {
        avgwt+=wt[i];
        avgta+=ta[i];
    }
    avgwt=avgwt/n;
    avgta=avgta/n;
    printf("\nAverage waiting time is %f\n",avgwt);
    printf("\nAverage turnaround time is %f\n",avgta);

}
