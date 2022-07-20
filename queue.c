#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int a[MAX];
int front,rear;

void initializeQueue();
int isEmpty();
int isFull();
int size();
int peek();
void insert(int x);
int delete();
void display();

 int main()
{
    int choice,x;

    initializeQueue();

    while(1)
    {
        printf("1.Insert an element on the Queue\n");
         printf("2.delete an element from the Queue\n");
          printf("3.Display the front element\n");
           printf("4.Display all Queue element\n");
            printf("5.Display the size of Queue\n");
             printf("6.exit\n");
             printf("enter your choice\n");
             scanf("%d",&choice);
             if(choice==6)
             break;

             switch(choice)
             {
                case 1:printf("enter the element to be insert\n");
                scanf("%d",&x);
                insert(x);
                break;
                case 2:x=delete();
                printf("deleted element is: %d\n",x);
                break;
                case 3:printf("Element at the front is:%d\n",peek());
                break;
                 case 4:display();
                break;
                 case 5:printf("Size of the Queue is:%d\n",size());
                break;
                 default:
                 printf("wrong choice\n");


             }
             printf("\n");
    }


}
void initializeQueue()
{
    rear=-1;
    front=-1;
}
int size()
{
    if(isEmpty())
    return 0 ;
    else
    return rear-front+1;
}
int isEmpty()
{
    if(front==-1 || front==rear+1 )
    return 1;
    else
    return 0;
}
int isFull()
{
    if(rear==MAX-1)
    return 1;
    else
    return 0;
}
void insert(int x)
{
    if(isFull())
    {
        printf("Queue overflow\n");
        return;

    }
    if(front==-1)
    front=0;
    rear=rear+1;
    a[rear]=x;
}
int delete()
{
    int x;
    if(isEmpty())
    {
        printf("Queue underflow\n");
        exit(1);
    }
    x=a[front];
    front=front+1;
    return x;

}
int peek()
{
    if(isEmpty())
    {
        printf("Queue underflow\n");
        exit(1);
    }
    return a[front];
}
void display()
{
    int i;
    if(isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("initializeQueue is :\n");
    for(i=front;i<=rear;i++)
    printf("%d\n",a[i]);
    printf("\n");
}
