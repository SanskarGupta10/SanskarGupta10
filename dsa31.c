#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
int size;
int top;
char * arr;

};

int stackTop(struct stack * sp)
{
  return sp->arr[sp->top];

}

int isFull(struct stack * sp)
{if(sp->top == sp->size -1)
{
    return 1;
}
else{
    return 0;
}
   
}

int isEmpty(struct stack * sp)
{if(sp->top==-1)
{
    return 1;
}
else{
    return 0;
}


}

void push(struct stack * sp,char ch)
{
  if(isFull(sp))
  {
      printf("Stack overflow");
      
  }
  else
  {  sp->top =sp->top+1;
     sp->arr[sp->top] = ch;
     
  }
}

char pop(struct stack * sp)
{   char ch;
    if(isEmpty(sp))
{   printf("stack underflow\n");
    
}
else{  ch=sp->arr[sp->top];
sp->top--;
return ch;

}

}

int precedence(char ch)
{
    if(ch=='*' || ch=='/')
    {
        return 3;
    }
    else if(ch=='+' || ch=='-')
    {
        return 2;
    }
    else{
        return 0;
    }
}
 
int isOperator(char ch)
{
    if(ch=='*' || ch=='/' || ch=='+' || ch=='-')
    {
        return 1;
    }
    else 
    {
        return 0;
    }
} 
char * infixToPostfix(char * infix)
{  struct stack * sp=(struct stack *)malloc(sizeof(struct stack));
    sp->size=100;
    sp->top=-1;
    sp->arr=(char *)malloc(sp->size*sizeof(char));
    char * postfix=(char*)malloc((strlen(infix)+1)*sizeof(char));
    int i=0; //infix scanner
    int j=0; //track postfix addition
    while(infix[i] != '\0')
    {  if(!isOperator(infix[i]))
    
    {
        postfix[j]=infix[i];
        i++;
        j++;
    }
    else 
    {   if(precedence(infix[i])>precedence(stackTop(sp)))
        { push(sp,infix[i]);
         i++;
        }
        else
        {
            postfix[j]=pop(sp);
            j++;
        }
    }

    }
    while(!isEmpty(sp))
    {
        postfix[j]=pop(sp);
        j++;
    }
    postfix[j]='\0';
    return postfix;

}





int main(){

    char * infix="(x-y) + (3-4)";
    
    printf(" The postfix conversion is %s",infixToPostfix(infix));





return 0;
}