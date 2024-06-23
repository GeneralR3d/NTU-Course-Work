float luxurytax(float amount);

#include<stdio.h>

int main(void)
{
    float user,total,subtotal=0;
   int cat,COE =0;
   printf("Please enter the list price:\n");
   scanf("%f",&user);
   printf("Please enter the category:\n");
   scanf("%d",&cat);
   switch(cat)
   {
        case 1:
            COE = 70000;
            break;
        case 2:
            COE = 80000;
            break;
        case 3:
            COE = 23000;
            break;
        case 4:
            COE = 600;
            break;
   }
   subtotal = user*0.9
   total = (subtotal*1.03) + luxurytax(subtotal-100000) + COE;
   printf("Total price is $%.2f",total);
   
   return 0;
}

float luxurytax(float amount)
{
    if(amount<0)
    return 0;
    
    return amount *0.1;
}