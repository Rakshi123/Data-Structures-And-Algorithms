#include<stdio.h>
#include<stdlib.h>
struct  node{
      int info;
    struct  node *link;
};
struct node *top;



void initializeStack();
int isEmpty();
int size();
int peek();
void push(int x);
int pop();
void display();

 int main()
{ 
    int choice,x;

    initializeStack();

    while(1)
    {
        printf("1.Push an element on the stack\n");
         printf("2.Pop an element from the stack\n");
          printf("3.Display the top element\n");
           printf("4.Display all stack element\n");
            printf("5.Display the size of element\n");
             printf("6.exit\n");
             printf("enter your choice\n");
             scanf("%d",&choice);
             if(choice==6)
             break;

             switch(choice)
             {
                case 1:printf("enter the element to be pushed\n");
                scanf("%d",&x);
                push(x);
                break;
                case 2:x=pop();
                printf("popped element is: %d\n",x);
                break;
                case 3:printf("Element at the top is:%d\n",peek());
                break;
                 case 4:display();
                break;
                 case 5:printf("Size of the stack is:%d\n",size());
                break;
                 default:
                 printf("wrong choice\n");

                       
             }
             printf("\n");
    }
    

}
void initializeStack()
{
    top=NULL ;
}
int size()
{
    int s=0;
    struct node *p=top;
    while(p!=NULL)
    {
        
        p=p->link;
        s++;
    }
    return s;

}
int isEmpty()
{
    if(top==NULL )
    return 1; 
    else 
    return 0;
}

void push(int x)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("stack overflow\n");
        return;

    }
   temp->info=x;
   temp->link=top;
   top=temp;
}
int pop()
{
    struct node *temp;
    int x;
    if(isEmpty())
    {
        printf("stack underflow\n");
        exit(1);
    }
     temp=top;
     x=temp->info;
     top=top->link;
     free(temp);
     return x;

}
int peek()
{
    if(isEmpty())
    {
        printf("stack underflow\n");
        exit(1);
    }
    return top->info;
}
void display()
{
    
     struct node *p;
     p=top;
    if(isEmpty())
    {
        printf("stack is empty\n");
        return;
    }
    printf("Stack is:\n");
    while(p!=NULL)
    {
        printf("%d",p->info);
        p=p->link;
    }
    printf("\n");
   
}