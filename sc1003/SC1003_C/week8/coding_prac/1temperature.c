#include <stdio.h>

int main(void)
{
    float user;
    do
    {
        printf("Enter the temperature in degree F:\n");
        scanf("%f",&user);
        printf("%f",user);
        float converted;
        converted = (user-32.0)*(5/9);
        printf("Converted degree in C: %.2f\n",converted);
        
    }
    while((int)user != -1);

    return 0;
}