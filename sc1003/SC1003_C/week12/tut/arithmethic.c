#include<stdio.h>

typedef struct{
    float operand1;
    float operand2;
    char op;
}bexpression;

float compute1(bexpression expr);
float compute2(bexpression* expr);
int main(void)
{
    bexpression expr;
    printf("Enter operand 1: ");
    scanf("%f",&expr.operand1);

    printf("Enter operand 2: ");
    scanf("%f",&expr.operand2);

    printf("Enter operation: ");
    do
    {
    expr.op=getchar();
    }while(expr.op=='\n');

    printf("Result 1: %.3f\n",compute1(expr));
    printf("Result 2: %.3f\n",compute2(&expr));
}

float compute1(bexpression expr)
{
    switch(expr.op)
    {
        case '+'://no need break as im just returning straight away
        return expr.operand1 + expr.operand2;
        case '-':
        return expr.operand1 - expr.operand2;
        case '*':
        return expr.operand1 * expr.operand2;
        case '/':
        return expr.operand1 / expr.operand2;
        default:
        return 0.0;
    }
}

float compute2(bexpression* expr)
{
    switch(expr->op)
    {
        case '+':
        return expr->operand1 + expr->operand2;
        case '-':
        return expr->operand1 - expr->operand2;
        case '*':
        return expr->operand1 * expr->operand2;
        case '/':
        return expr->operand1 / expr->operand2;
        default:
        return 0.0;
    }
}


/*SUGGESTED SOLUTIONS
*
*
*
*
*
*
*
*/
int main()
{
    bexpression e;
    int choice;
    printf("Select one of the following options:\n");
    printf("1. compute1()\n");
    printf("2. compute2()\n");
    printf("3. exit()\n");

    do{
        printf("Enter choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        printf("Enter expression (op1 op2 op):\n");
        scanf("%f %f %c",&e.operand1,&e.operand2,&e.op);
        printf("Compute1(): %.2f\n",compute1(e));
        break;
        
        case 2:
        printf("Enter expression (op1 op2 op):\n");
        scanf("%f %f %c",&e.operand1,&e.operand2,&e.op);
        printf("Compute2(): %.2f\n",compute2(e));
        break;
        }
    }while(choice<3);
    return 0;
}