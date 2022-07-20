#include <stdio.h>
#include<stdlib.h>
struct node {
    int info;
    struct node *link;

};

struct node *createList(struct node *start);
void DisplayList(struct node *start);
void countnodes(struct node *start);
void searchnode(struct node *start,int x);
struct node *insertinbeginning(struct node *start,int data);
void insertatend(struct node *start,int data);
void insertafter(struct node *start,int data,int x);
struct node *insertbefore(struct node *start,int data,int x);
struct node *insertatposition(struct node *start,int data,int k);
struct node *deletenode(struct node *start,int x);
struct node *reverseList(struct node *start);

 int main()
{
    struct node *start=NULL;
    int choice,data,x,k;


    start =createList(start);

    while(1)
    {
        printf("\n");
        printf("1. Display list\n");
        printf("2. insert in beginning or empty list\n");
        printf("3. insert at end\n");

         printf("4. count nodes\n");
          printf("5. search nodes\n");
           printf("6. insert after a node\n");

        printf("7. insert before a node\n");
        printf("8. insert at position \n");
        printf("9.delete a node\n");
        printf("10.reverse list\n" );
        printf("11.exit\n" );
        printf("enter your choice: \n");
        scanf("%d",&choice);
        if(choice == 11)
        break;

        switch(choice)
        {
            case 1:
                   DisplayList(start);
                   break;
            case 2:printf("Enter the element to be inserted:\n");
                           scanf("%d",&data);
                           start=insertinbeginning(start,data);
                           break;
            case 3:printf("Enter the element to be inserted:\n");
                           scanf("%d",&data);
                           insertatend(start,data);
                           break;
            case 4:
                           countnodes(start);
                           break;
            case 5:printf("enter the element to be searched\n");
                           scanf("%d",&data);
                           searchnode(start,data);
                           break;
            case 6:printf("enter the element to be inserted:");
                   scanf("%d",&data);
                   printf("enter the element after which to insert");
                   scanf("%d",&x);
                   insertafter(start,data,x);
                   break;
                                       break;
            case 7:printf("enter the element to be inserted:");
                   scanf("%d",&data);
                   printf("enter the element before which to insert");
                   scanf("%d",&x);
                   start=insertbefore(start,data,x);
                   break;
            case 8:printf("enter the element to be inserted:");
                   scanf("%d",&data);
                   printf("enter the position at which to insert");
                   scanf("%d",&k);
                   start=insertatposition(start,data,k);
                   break;
                   case 9:printf("enter the element to be deleted:");
                          scanf("%d",&x);
                          start=deletenode(start,x);
                          break;
                   case 10: start=reverseList(start);
                          break;
            default:
                    printf("wrong choice\n");
        }
    }

}
void DisplayList(struct node *start)
{
    struct node *p;
    if(start==NULL)
    {
        printf("list is empty\n");
        return;

    }
    printf("List is : \t");
    p=start;
    while(p!=NULL)
    {
        printf("%d\t",p->info);
        p=p->link;
    }
    printf("\n");

}

struct node *createList(struct node *start)
{
    int i,n,data;
    printf("Enter the number of nodes\n ");
    scanf("%d",&n);
    if(n==0)
    return start;
    printf("enter the first element to be inserted:");
    scanf("%d",&data);
    start=insertinbeginning(start,data);

    for(i=2;i<=n;i++)
    {
        printf("enter the next element to be inserted:");
    scanf("%d",&data);
    insertatend(start,data);
    }
    return start;

}
struct node *insertinbeginning(struct node *start,int data)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=start;
    start=temp;

    return start;
}
void insertatend(struct node *start,int data)
{
    struct node *temp,*p;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    p=start;
    while(p->link!=NULL)

        p=p->link;
        p->link=temp;
        temp->link=NULL;
    }

    void countnodes(struct node *start)
    {
        int n=0;
        struct node *p;
        p=start;
        while(p!=NULL)
        {
            n++;
            p=p->link;
        }
        printf("number of nodes:%d\n",n);
    }

    void searchnode(struct node *start,int x)
    {
        struct node *p;
        int pos=1;
        p=start;
        while(p!=NULL)
        {
            if(p->info==x)
            break;
            pos++;
            p=p->link;
        }
        if(p==NULL)
        {
            printf("%d is not found\n",x);
        }
        else
        {
            printf("%d is found at %d",x,pos);
        }
    }

void insertafter(struct node *start,int data,int x)
{
    struct node *p,*temp;
    p=start;
    while(p!=NULL)
    {
        if(p->info==x)
        break;
        p=p->link;
    }
    if(p==NULL)
    printf("%d is not present in the list\n",x);
    else
    {
        temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=p->link;
    p->link=temp;
    }
}
struct node  *insertbefore(struct node *start,int data,int x)
{
    struct node *p,*temp;
    if(start==NULL)
    {
        printf("list is empty");
        return start;
    }


        if(x==start->info)
        {
            temp=(struct node *)malloc(sizeof(struct node));
            temp->info=data;
            temp->link=start;
            temp=start;
            return start;
        }

        p=start;
        while(p!=NULL)
        {
            if(p->link->info==x)
             break;
        p=p->link;
        }


    {
        temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=p->link;
    p->link=temp;
    }
    return start;
}
struct node *insertatposition(struct node *start,int data,int k)
{
   struct node *p,*temp;
   int i;

   if(k==1)
   {
      temp=(struct node *)malloc(sizeof(struct node));
            temp->info=data;
            temp->link=start;
            start=temp;
            return start;
   }
   p=start;
   for(i=1;i<k-1 && p!=NULL;i++)
   p=p->link;

   if(p==NULL)
   printf("you can insert only upto %dth position\n",i);
   else
   {
       temp=(struct node *)malloc(sizeof(struct node));
            temp->info=data;
            temp->link=p->link;
            p->link=temp;
   }
   return start;
}
struct node *deletenode(struct node *start,int x)
{
  struct node *temp,*p;

  if(start==NULL)
  {
    printf("List is empty\n");
    return start;
  }
  if(start->info==x)
  {
    temp=start;
    start=start->link;
    free(temp);
    return start;
  }
  p=start;
  while(p->link!=NULL)
  {
    if(p->link->info==x)
    break;
    p=p->link;

  }
  if(p->link==NULL)
  printf(" Element %d not in list\n",x );
  else
  {
    temp=p->link;
    p->link=temp->link;
    free(temp);

  }
  return start;
}
struct node *reverseList(struct node *start)
{
  struct node *prev,*ptr,*next;
  prev=NULL;
  ptr=start;
  while (ptr!=NULL) {
    next=ptr->link;
    ptr->link=prev;
    prev=ptr;
    ptr=next;
  }
  start=prev;
  return start;
}
