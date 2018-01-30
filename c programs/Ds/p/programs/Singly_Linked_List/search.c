# include <stdio.h>
# include <stdlib.h>
struct node
{
int data;
struct node *link;
};
struct node *insert(struct node *p, int n)
{
struct node *temp;
if(p==NULL)
{
p=(struct node *)malloc(sizeof(struct node));
if(p==NULL)
{
printf("Error\n");
exit(0);
}
p-> data = n;
p-> link = NULL;
}
else
{
temp = p;
while (temp-> link!= NULL)
temp = temp-> link;
temp-> link = (struct node *)malloc(sizeof(struct node));
if(temp -> link == NULL)
{
printf("Error\n");
exit(0);
}
temp = temp-> link;
temp-> data = n;
temp-> link = NULL;
}
return(p);
}
void searcher(struct node *list,int search)
{
int k=0;
while (list!= NULL)
{
if(list-> data==search)
{
k=1;
break;
}
list = list-> link;
}
if(k==1)
printf("Element found\n");
else
printf("Element Not found\n");
}
main()
{
int n;
int x,search;
struct node *start = NULL ;
printf("Enter the nodes to be created \n");
scanf("%d",&n);
while ( n-- > 0 )
{
printf( "Enter the data values to be placed in a node\n");
scanf("%d",&x);
start = insert ( start,x);
}
printf("Enter the element to search :");
scanf("%d",&search);
searcher(start,search);
}

