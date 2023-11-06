#include<stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
    float a[10][10], b[10], x[10];
    int i,j,m,n,t;
    printf("Enter The no. Of Unknowns: \n");
    scanf("%d",&n);
    printf("Enter the values of matrix A:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%f",&a[i][j]);\
            // diagonal matrix
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    if(i!=j){
                       t=a[j][j]/a[i][i];
                       for(int k=0;k<n;k++){
                           a[j][k]=a[j][k]-t*a[i][k];
                           b[j]=b[j]-t*b[i];
                       } 
                       printf("The diagonal matrix is:\n");
                       for(i=0;i<n;i++){
                           printf("\n");
                           for(j=0;j<n;j++){
                               printf("%0.4f\t",a[i][j]);
                           }
                       }
                    }
                }
            }
            printf("The solution is:\n");
            for(i=0;i<n;i++){
                x[i]=b[i]/a[i][i];
                printf("%0.4f\t",x[i]);
            }
            printf("\n");
        }
    }
}
    