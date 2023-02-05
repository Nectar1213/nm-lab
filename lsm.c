#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
void main()
{
float a,b,x[10],y[10],sumx=0,sumy=0,sumxy=0,sumxx=0;
float Y[10],X[10],A;
int i,n,choice;

printf("Enter nth term\n");
scanf("%d",&n);
printf("Enter value of x and y\n");
for(i=0;i<n;i++)
{
scanf("%f%f",&x[i],&y[i]);
}
printf("Fit the curve of the form\n1.y=a+bx\n2.y=aexp(bx)\n3.Exit\n");
printf("Enter choice : ");
scanf("%d",&choice);
switch(choice)
{
case 1:
for(i=0;i<n;i++)
{
sumx=sumx+x[i];
sumy=sumy+y[i];
sumxy=sumxy+x[i]*y[i];
sumxx=sumxx+x[i]*x[i];
}

b=(n*sumxy-sumx*sumy)/(n*sumxx-sumx*sumx);
a=(sumy-b*sumx)/n;
printf("a=%f\tb=%f\n",a,b);
break;


case 2:
for(i=0;i<n;i++)
{
Y[i]=log(y[i]);
}
for(i=0;i<n;i++)
{
sumx=sumx+x[i];
sumy=sumy+Y[i];
sumxy=sumxy+x[i]*Y[i];
sumxx=sumxx+x[i]*x[i];
}

b=(n*sumxy-sumx*sumy)/(n*sumxx-sumx*sumx);
A=(sumy-b*sumx)/n;
a=exp(A);
printf("a=%f\tb=%f\n",a,b);
break;

case 3:
exit(0);

default:
printf("Enter correct choice\n");
}
getch();
}