#include<stdio.h>
#include<stdlib.h>
struct  node{
      int info;
    struct  node *link;
};
struct node *front,*rear;

void initializeQueue();
int isEmpty();
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
    rear=NULL;
    front=NULL;
}
int size()
{
int s=0;
struct node *p=front;
while(p!=NULL)
{
  s++;
  p=p->link;
}
return s;
}
int isEmpty()
{
    if(front==NULL )
    return 1;
    else
    return 0;
}

void insert(int x)
{
  struct node *temp;
  temp=(struct node *)malloc(sizeof(struct node));
  if(temp==NULL)
  {
      printf("Memory not available\n");
      return;

  }
 temp->info=x;
 temp->link=NULL;

 if(front==NULL)
 front=temp;
 else
 rear->link=temp;
 rear=temp;
}
int delete()
{
    struct node *temp;
    int x;
    if(isEmpty())
    {
        printf("Queue underflow\n");
        exit(1);
    }
    temp=front;
    x=temp->info;
    front=front->link;
    free(temp);
  return x;

}
int peek()
{
    if(isEmpty())
    {
        printf("Queue underflow\n");
        exit(1);
    }
    return front->info;
}
void display()
{
  struct node *p;
    p=front;
    if(isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("initializeQueue is :\n");
    while(p!=NULL)
    {
      printf("%d\n",p->info );
    p=p->link;
  }
  printf("\n");

}
