#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
      int sno;
      char sname[20];
      int marks;
      struct node *next;
};
struct node *start=NULL;
struct node *create_ll(struct node *);
//struct node *display(struct node *);
int main()
{
   start=create_ll(start);
    printf("linked list created\n");
   //start=display(start);
}
struct node *create_ll(struct node *start)
{
   struct node *new_node,*ptr;
   int n,mark;
   char name[20];
     printf("enter -1 to terminate\n");
    printf("enter id :\n");
    scanf("%d",&n);
   while(n!=-1)
   {
     printf("enter marks\n");
   scanf("%d",&mark);
   printf("enter name\n");
   scanf("%s",name);
       if(start==NULL)
       {
          new_node=(struct node*)malloc(sizeof(struct node*));
	 new_node->sno=n;
         strcpy(new_node->sname,name);
         new_node->marks=mark;
         new_node->next=NULL;
         start=new_node;
	}
      else
      {
          ptr=start;
          while(ptr->next!=NULL)
             ptr=ptr->next;
            new_node=(struct node*)malloc(sizeof(struct node*));
	 new_node->sno=n;
        strcpy(new_node->sname,name);
         new_node->marks=mark;
         ptr->next=new_node;
         new_node->next=NULL;
         
       }
       printf("enter n value:\n");
       scanf("%d",&n);
 }
     return start;
}
/*struct node *display(struct node *start)
{
   struct node *ptr;
   ptr=start;
   while(ptr!=NULL)
       {
              printf("%d\t%s\t%d\n",ptr->sno,ptr->sname,ptr->marks);
              ptr=ptr->next;
       }
       printf("%d\t%s\t%d\n",ptr->sno,ptr->sname,ptr->marks);
          return start;
}*/
