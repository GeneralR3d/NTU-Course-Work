#include<ctype.h>
#include<stdio.h>

int main(void)
{
    int alphabets,digits=0;
    printf("Enter your characters (# to end):\n");
    char user;

    do
    {
        user = getchar();
        if(isalpha(user)!=0)
        {
            alphabets++;
        }
        else if (isdigit(user)!=0)
        {
            digits++;
        }
    }
    while(user != '#');

    printf("The number of digits: %i\n",digits);
    printf("The number of letters: %i\n",alphabets);

    return 0;
}