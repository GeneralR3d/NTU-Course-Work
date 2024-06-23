#include<stdio.h>
#include <stdlib.h>

int main(void)
{
    float user;
    do
    {
        printf("Enter the temperature in degree F:\n");
        scanf("%f",&user);
        printf("%f",user);
        float converted;
        converted = (5.0/9);
        printf("Converted degree in C: %f\n",converted);
        
    }
    while((int)user != -1);

}
