/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<stdio.h>
#include<conio.h>
#include<math.h>

void main()
{
  int n;
  float e[20],p[20];
  int i;
  float ut,u,x,y;

 

  printf("\n Enter Number of Processes :: ");
  scanf("%d",&n);

  for(i=0;i<n;i++)
  {

   printf("\n Enter Execution Time for P%d ::",(i+1));
   scanf("%f",&e[i]);
   printf("\n Enter Period for P%d ::",(i+1));
   scanf("%f",&p[i]);
  }
  //calculate the utilization
  for(i=0;i<n;i++)
  {
   x=e[i]/p[i];
   ut+=x;
  }

  //calculate value of U
  y=(float)n;
  y=y*((pow(2.0,1/y))-1);
  u=y;

  if(ut<u)
  {
 printf("\n As %f < %f ,",ut,u);
 printf("\n The System is surely Schedulable sing RMA");
  }
  else
 printf("\n The system is no schedulable using Rate Monotonic scheduling");

}
