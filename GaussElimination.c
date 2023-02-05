#include<stdio.h>
#include<math.h>
 
 int main()
 {
    int i,j,k,n;
    float a[20][20],c,x[10],s=0.0;
    printf("Enter the order of matrix:\n");
    scanf("%d",&n);
    printf("\n Enter the elements of augmented matrix rowwise:\n\n");

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=(n+1);j++)
        {
            printf("a[%d][%d]:",i,j);
            scanf("%f",&a[i][j]);
        }

    }
    for(j=1;j<=n;j++)
    {
        for(i=1;i<=n;i++)
        {
            if(i>j)
            {
                c=a[i][j]/a[j][j];
                for(k=1;k<=n+1;k++)
                {
                    a[i][k]=a[i][k]-c*a[j][k];
                }
            }
        }
    }
    x[n]=a[n][n+1]/a[n][n];
    for(i=n-1;i>=1;i--)
    {
        s=0;
        for(j=i+1;j<=n;j++)
        {
            s=s+a[i][j]*x[j];
        }
        x[i]=(a[i][n+1]-s)/a[i][i];
    }
    printf("\n The solution is:\n");
    for(i=1;i<=n;i++)
    {
        printf("\n x%d=%.2f\t",i,x[i]);
    }return (0);
 }