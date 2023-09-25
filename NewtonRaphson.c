// newton raphson method
// find f'(x)
// if |f(x1)|<|f(x2)| , x0 = x1 else x0 = x2
// x2 = x1 - (f(x1)/f'(x1))


#include<stdio.h>
#include<conio.h>
#include<math.h>

float f(float x)
{
    return (x*x*x - x - 11);
}

float df(float x)
{
    return (3*x*x - 1);
}

int main()
{
    float x0,x1,x2,x3,x4,aerr ,flag = 0;
    int i = 0,maxitr;
    printf("Enter the maximum number of iterations : ");
    scanf("%d",&maxitr);
    printf("Enter the absolute error : ");
    scanf("%f",&aerr);
    do
    {
        printf("Enter the value of x1 and x2 : ");
        scanf("%f%f",&x1,&x2);
        if(f(x1)*f(x2) < 0){
            printf("The root does not lie between the given interval");
            flag = 0;
        }
        else
        {
            printf("\nWrong Values of x1 and x2");
            flag = 1;
        }
    }while(flag == 1);
    if(f(x1)*f(x2)<0){
        if(fabs(f(x1))<fabs(f(x2)))
            x0 = x1;
        else
            x0 = x2;
    }
    printf("\nEnter No. of iterations : ");
    scanf("%d",&maxitr);
    printf("Enter the absolute error : ");
    scanf("%f",&aerr);
    x4=x0;
    for(i=1;i<=maxitr;i++)
    {
        x3 = x4- (f(x4)/df(x4));
        printf("\nAfter %d iterations, root = %f",i,x3);
        x4 = x3-(f(x3)/df(x3));
        if(fabs(x3-x4) <= aerr){
            printf("\nAfter %d iterations, root = %f",i+1,x4);
            return 0;
        }
    }
    return 0;
}