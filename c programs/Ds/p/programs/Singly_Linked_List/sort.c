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
struct node *sortlist(struct node *p)
{
struct node *temp1,*temp2,*min,*prev,*q;
q = NULL;
while(p != NULL)
{
prev = NULL;
min = temp1 = p;
temp2 = p -> link;
while ( temp2 != NULL )
{
if(min -> data > temp2 -> data)
{
min = temp2;
prev = temp1;
}
temp1 = temp2;
temp2 = temp2-> link;
}
if(prev == NULL)
p = min -> link;
else
prev -> link = min -> link;
min -> link = NULL;
if( q == NULL)
q = min;
else
{
temp1 = q;
while( temp1 -> link != NULL)
temp1 = temp1 -> link;
temp1 -> link = min;
}
}
return (q);
}
void printlist ( struct node *p )
{
printf("The data values in the list are\n");
while (p!= NULL)
{
printf("%d\t",p-> data);
p = p-> link;
}
printf("\n");
}
void main()
{
int n;
int x;
struct node *start = NULL ;
printf("Enter the nodes to be created \n");
scanf("%d",&n);
while ( n-- > 0 )
{
printf( "Enter the data values to be placed in a node\n");
scanf("%d",&x);
start = insert ( start,x);
}
printf("The created list is\n");
printlist ( start );
start = sortlist(start);
printf("The sorted list is\n");
printlist ( start );
}

