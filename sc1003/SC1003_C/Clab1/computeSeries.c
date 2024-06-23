int factorial(int input);
#include<math.h>
#include<stdio.h>

int main(void)
{
	float x =0;
	float sum=0;

	printf("Enter x:\n");
	scanf("%f",&x);

	for(int i=1;i<=10;i++)
	{
		sum+=(pow(x,i)/factorial(i));
	}

	printf("Result = %.2f",sum+1);
	
	return 0;
}

int factorial(int input)
{
    if(input==1)
    return input;
    
    return input*factorial(input-1);
}

/*
SUGGESTED ANSWERS

#include<stdio.h>
int main()
{
	int n, denominator =1;
	float x, result =1.0, numerator =1.0;

	printf("Please enter the value of x: \n");
	scanf("%d",&x);
	for(n=1;n<=10;n++)
	{
		denominator *=n;
		numerator *=x;
		result += numerator/denominator;
	}
	printf("Result = %.2f\n",result);
	return 0;
}

*/