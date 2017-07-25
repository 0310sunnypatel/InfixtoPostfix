#include<stdio.h>
#include<ctype.h>
#include<string.h>
struct stack
{
    int data[10];
    int top;
    int count;
}s;
void initialize(struct stack *s)
{
    s->top=-1;
    s->count=0;
}
void push(struct stack *s,int ele)
{
    if(s->top==-1)
        printf("Underflow\n");
    else
    {
        s->top++;
        s->data[s->top]=ele;
    }
}
void itp(struct stack *s,char infix[],char postfix[])
{
    int i,k=0,x;
    for(i=0;infix[i]!='\0';i++)
    {
        if(isdigit(infix[i]))
            postfix[k++]=infix[i];
        else if(infix[i]=='(')
        {
            push(&s,infix[i]);
            i++;
        }
        else if(infix[i]==')')
        {
            while(x=pop(&s)!='(')
            {
                postfix[k++]=x;
            }
        }
        else
        {
            while((prec(stacktop(&s))>=prec(infix[i]))&&s->top!=-1)
            {
                x=pop(&s);
                postfix[k++]=x;
            }
            push(&s,infix[i]);
        }
        while(s->top!=-1)
        {
            x=pop(&s);
            postfix[k++]=x;
        }
        postfix[k]='\0';
    }
}
int pop(struct stack *s)
{
    int x;
    if(s->top==-1)
        printf("Stack Underflow\n");
    else
    {
        x=s->data[s->top];
        s->top--;
        return x;
    }
}
int stacktop(struct stack *s)
{
   if(s->top==-1)
    printf("Stack Underflow\n");
   else
    return s->data[s->top];
}
int prec(char x)
{
    if(infix[i]=='^')
        return 3;
    if(infix[i]=='*' || infix[i]=='/')
        return 2;
    if(infix[i]=='+' || infix[i]=='-')
        return 1;
}
void main()
{
    char infix[50],postfix[50];
   printf("Enter the infix expression:\t");
   gets(infix);
   itp(&s,infix,postfix);
   printf("The postfix expression is:\t");
   puts(postfix);
}
