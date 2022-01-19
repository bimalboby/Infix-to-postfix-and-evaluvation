//
//  main.c
//  infix to postfix convert and postfix valuation
//
//  Created by Bimal Boby
//


#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

char array[100];
int top = -1;

void push(char x){
    array[++top] = x;
}


// pop
char pop(){
    if(top == -1)
        return -1;
    else
        return array[top--];
}



//priority
int priority(char a)
{
    if(a == '(')
        return 0;
    if(a == '+' || a == '-')
        return 1;
    if(a == '*' || a == '/')
        return 2;
    return 0;
}


//Converting
int infixtopostfix(){
    char exp[100];
    char *e, x;
    printf("\nEnter the INFIX Expression to convert :");
    scanf("%s",exp);
    printf("\n");
    e = exp;
    printf("\nInfix Expression =>  %s\n", exp);
    printf("Postfix Expression => ");
    
    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c",*e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                printf("%c", x);
        }
        else
        {
            while(priority(array[top]) >= priority(*e))
                printf("%c",pop());
            push(*e);
        }
        e++;
    }
    
    while(top != -1)
    {
        printf("%c",pop());
    }return 0;
}



// valuating the postfix Expression
int postfix_eval(){
    char exp [100];
    char *e;
    int n1,n2,n3,num;
    printf("Enter POSTFIX Expression:");
    scanf("%s",exp);
    e = exp;
    while(*e != '\0')
    {
        if(isdigit(*e))
        {
            num = *e - 48;
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();
            switch(*e)
            {
            case '+':
            {
                n3 = n1 + n2;
                break;
            }
            case '-':
            {
                n3 = n2 - n1;
                break;
            }
            case '*':
            {
                n3 = n1 * n2;
                break;
            }
            case '/':
            {
                n3 = n2 / n1;
                break;
            }
            }
            push(n3);
        }
        e++;
    }
    printf("\nEvaluation Expression %s = %d\n\n",exp,pop());
    return 0;
    
}

//MAIN FUNCTION
int main(){
   int option;
   printf("\n NAME      : BIMAL BOBY");
   printf("\n REG.NO    : 2060333");
   printf("\n EXPERIMENT: Infix to Postfix conversion and valutation of Postfix Expression");

   while(1){
     
      printf("\n\n______________ M E N U ______________\n");
      printf("|1. Convert Infix to Postfix         |\n|2. Evaluation of Postfix Expression |\n|3. Exit                             |");
      printf("\n_____________________________________");
      printf("\n \n Enter the Option:");
      scanf("%d",&option);

     switch(option){
      
              case 1:
                 infixtopostfix();
                 break;
        
             case 2:
                 postfix_eval();
                 break;
                 
                          
             case 3:
                 printf("\nEnding......\n");
                 exit(0);
             
                 
             default:
                 printf("\nInvalid option !!!\n");
      }
   }
}

