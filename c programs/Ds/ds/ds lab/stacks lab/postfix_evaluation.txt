#include<stdio.h>
#define MAX 20
int top=-1;
float st[MAX];
void push(float [],float);
float pop(float []);
float eval_postfix(char []);
int main()
{
    char exprs[20];
    printf("enter the postfix expression to evaluate:");
    scanf("%s",exprs);
    float val;
    val=eval_postfix(exprs);
    printf("\ntotal expression value is: %f",val);
    return 0;
}
float eval_postfix(char exprs[])
{
    int i=0;float sen_val;
    float op1,op2,val;
    while(exprs[i]!='\0')
    {
        if(isdigit(exprs[i]))
        {
            sen_val=(float)(exprs[i]-'0');
            push(st,sen_val);
        }
        else
        {
            op1=pop(st);
            op2=pop(st);
            switch(exprs[i])
            {
                case '+':val=op2+op1;
                break;
                case '-':val=op2-op1;
                break;
                case '*':val=op2*op1;
                break;
                case '/':val=op2/op1;
                break;
                case '%':val=(int)op2 % (int)op1;
                break;
            }
            push(st,val);
        }
        i++;
    }
    return (pop(st));
}
void push(float st[],float value)
{
    if(top==MAX-1)
    {
        printf("\nOVER FLOW");
    }
    else
    {
        top+=1;
        st[top]=value;
    }
}
float pop(float st[])
{
    float val=-1;
    if(top==-1)
    {
        printf("\nUNDER FLOW");
    }
    else
    {
        val=st[top];
        top-=1;
    }
    return val;
}
