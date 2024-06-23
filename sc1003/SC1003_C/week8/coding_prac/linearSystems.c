#include<stdio.h>
#include<math.h>

int main(void)
{
    /* Write your code here */
    float a1,b1,c1,a2,b2,c2=0;
    printf("Enter a1,b1,c1,a2,b2,c2:\n");
    scanf("%f %f %f %f %f %f",&a1,&b1,&c1,&a2,&b2,&c2);

    float denom =a1*b2 - a2*b1;
    if(denom == 0)
    {
        printf("Denominator is zero!\n");
        return 1;
    }
    float x = (b2*c1 - b1*c2)/denom;
    float y = (a1*c2 - a2*c1)/denom;

    printf("x=%.2f,y=%.2f",x,y);
    return 0;

}