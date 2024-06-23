float tenpercent(float amount);
float twentypercent(float amount);
float thirtypercent(float amount);

#include<stdio.h>
int main(void)
{
      /* Write your code here */
   #define RATE 6
   int hours=0;
   float gross,tax,taxable=0;
   
    printf("Enter hours of work:\n");
    scanf("%i",&hours);
    if(hours>40)
    {
        gross = 40*RATE + (hours-40)*RATE*1.5;
    }
    else
    {
        gross = hours*RATE;
    }
    taxable = gross;
    tax += tenpercent(taxable);
    taxable -= 1000;
    tax += twentypercent(taxable);
    taxable -=500;
    tax += thirtypercent(taxable);
    
    printf("Gross pay=%.2f\n",gross);
    printf("Tax=%.2f\n",tax);
    printf("Net pay=%.2f",gross-tax+1-1);
    
    return 0;
}
float tenpercent(float amount)
{
    if (amount <0)
    {
    return 0;
    }
    
    if((amount * 0.1)>100)
    {
        return 100;
    }
    else
    {
        return amount *0.1;
    }
}

float twentypercent(float amount)
{
    if (amount <0)
    {
    return 0;
    }
    
    if((amount * 0.2)>100)
    {
        return 100;
    }
    else
    {
        return amount *0.2;
    }
}

float thirtypercent(float amount)
{
    if (amount <0)
    {
    return 0;
    }
    
    return amount * 0.3;
}