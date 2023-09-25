// write a program to implement iteration method on a function 

#include<stdio.h>
#include<conio.h>
#include<math.h>

float f(float x)
{
    return (x*x*x - 4*x - 9);
}
float q(float x)
{
    return pow((4*x + 9),(1.0/3.0));
}
float qp(float x)
{
    return ((4.0/3.0)*(1/pow((4*x + 9),(2.0/3.0))));
}
int main()
{
    float x0,x1,x2,x3,aerr;
    int i,itr;
    printf("Enter The Roots\n");
    scanf("%f%f",&x1,&x2);
    if(qp(x1) < 1 && qp(x2) < 1){
        printf("Function is correct\n");
    }else{
        printf("Create a New Function\n");
        return(0);
    }
    if(f(x1)*f(x2) > 0){
        printf("Roots are not correct\n");
        return(0);
    }
    printf("Enter The Number of Iteration\n");
    scanf("%d",&itr);
    printf("Enter The Absolute Error\n");
    scanf("%f",&aerr);
    if(fabs(f(x1)) < fabs(f(x2))){
        x0 = x1;
        x1 = x2;
        x2 = x0;
    }else
        x0 = x2;
    printf("Iteration\tRoots\n");
    for(i=1;i<=itr;i++){
        x3 = q(x2);
        printf("%d\t\t%f\n",i,x3);
        if(fabs(x3 - x2) < aerr){
            printf("Root = %f\n",x3);
            return(0);
        }
        x2 = x3;
    }
    printf("Root = %f\n",x3);
    getch();
    return(0);
}