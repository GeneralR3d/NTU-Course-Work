#include<stdio.h>

int main(void)
{
    printf("Enter a character: \n");
    char user = getchar();
    
    if (user>=65 && user<=90)
    {
        printf("Upper case letter\n");
    }
    else if (user>=97 && user<=122)
    {
        printf("Lower case letter\n");
    }
    else if (user>=48 && user<=57)
    {
        printf("Digit\n");
    }
    else
    {
        printf("Other character\n");
    }

return 0;
}