#include<stdio.h>
#define MAX 10
int deque[MAX];
int left=-1,right=-1;
void input_deque(void);
void output_deque(void);
void insert_left(void);
void insert_right(void);
void delete_left(void);
void delete_right(void);
void display(void);
int main()
{
   int ch;
   printf("enter your choice\n");
   printf("1:input restricted deque\n");
   printf("2:output restricted deque\n");
   scanf("%d",&ch);
   switch(ch)
   {
        case 1 : input_deque();
                   break;
        case 2 : output_deque();
                   break;
    }
}
void input_deque()
{
   int ch;
   do
      {
        printf("\n INPUT RESTRICTED DEQUE\n");
         printf("\n 1:insert at rigth\n");
         printf("2:delete at left\n");
         printf("3:delete at right\n");
         printf("4:display\n");
         printf("enter your choice\n");
         scanf("%d",&ch);
         switch(ch)
         {
           case 1 :  insert_right();
                    break;
            case 2 : delete_left();
                      break;
                 case 3 : delxete_right();
                      break;
              case 4 : display();
                     break;
           }
          }while(ch<=4);
}
 
void output_deque()
{
   int ch;
   do
      {
        printf("\n OUTPUT RESTRICTED DEQUE\n");
         printf("\n 1:insert at rigth\n");
         printf("2:insert at left\n");
         printf("3:delete at left\n");
         printf("4:display\n");
         printf("enter your choice\n");
         scanf("%d",&ch);
         switch(ch)
         {
           case 1 :  insert_right();
                    break;
            case 2 : insert_left();
                      break;
                 case 3 : delete_left();
                      break;
              case 4 : display();
                     break;
           }
          }while(ch<=4);
}
void insert_right()
{
      int val;
       printf("enter number to insert into queue\n");
       scanf("%d",&val);
       if((left==0 && right==MAX-1) || (left==right+1))
             printf("over flow \n");
       if(left==-1)
        {
                 left=0;
                 right=0;
        }
        else
          {
                    if(right==MAX-1)
                        right=0;
                    else
                            right=right+1;
         }
         deque[right]=val;
}
void insert_left()
{
     int val;
      printf("enter number to insert into queue\n");
       scanf("%d",&val);
       if((left==0 && right==MAX-1 ) ||(left==right+1))
              printf("overflow\n");
       if(left==-1)
          {
                  left=0;
                   right=0;
          }
        else
          {
            if(left==0)
               left=MAX-1;
            else
                   left=left+1;
          }
           deque[left]=val;
}
void delete_left()
{
          if(left==-1)
                printf("underflow\n");
            printf("%d is the element to be deleted\n",deque[left]);
            if(left==right)
            {
                   left=-1;
                   right=-1;
             }
             else
             {
               if(left==MAX-1)
                     left=0;
               else
                       left=left+1;
             }
 }
void delete_right()
{
    
          if(left==-1)
                printf("underflow\n");
            printf("%d is the element to be deleted\n",deque[right]);
            if(left==right)
            {
                   left=-1;
                   right=-1;
             }
            else
            {
                if(right==0)
                    right=MAX-1;
                else
                     right=right-1;
            }
     }
void display()
{
             int front=left,rear=right;
             if(front==-1)
               printf("queue is empty\n");
             printf("elements in queue are:\n");
              if(front<=rear)
                {
                    while(front<=rear)
                        {
                           printf("%d\t",deque[front]);
                             front++;
                         }
                 }
                else
                 {
                     while(front<=MAX-1)
                    {
                       printf("%d\t",deque[front]);
                             front++;
                         }
                        front=0;
                        while(front<=rear)
                        {
                           printf("%d\t",deque[front]);
                             front++;
                         }
                   }
                     printf("\n");
}
 
 

