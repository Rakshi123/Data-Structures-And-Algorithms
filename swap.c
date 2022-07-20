#include <stdio.h>

int main()
{
    int a,b,temp;
    printf("variables before swapping\n");
    scanf("%d %d",&a,&b);
    temp=a;
    a=b;
    b=temp;
   
     printf("variables after swapping %d %d\n",a,b);
    

    return 0;
}