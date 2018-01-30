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
void printlist ( struct node *p,int t )
{
float sum=0;
printf("The data values in the list are\n");
while (p!= NULL)
{
sum+=p-> data;
p = p-> link;
}
printf("Average is %.2f",(sum/t));
}
main()
{
int n;
int x,t;
struct node *start = NULL ;
printf("Enter the nodes to be created \n");
scanf("%d",&n);
t=n;
while ( n-- > 0 )
{
printf( "Enter the data values to be placed in a node\n");
scanf("%d",&x);
start = insert ( start,x);
}
printf("The created list is\n");
printlist ( start,t );
printf("\n");
}
