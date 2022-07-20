#include <stdio.h>

int main()
{
    int a,b;
    printf("variables before swapping\n");
    scanf("%d %d",&a,&b);
    a=a+b;
    b=a-b;
    a=a-b;

     printf("variables after swapping %d %d\n",a,b);


    return 0;
}
