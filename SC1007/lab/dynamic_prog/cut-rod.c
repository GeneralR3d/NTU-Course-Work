#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

//memory//global var
int *r;

int cr_recursive(int *p, int n)
{
    //write your code here
    if(n==0) return 0;
    int current = -9999999;
    for(int i=1;i<=n;i++){
        current=MAX(current,p[i]+cr_recursive(p,n-i));
    }
    return current;
}

int cr_top_down_dp(int *p, int n)
{
    //write your code here
    if(n==0) return 0;
    if(r[n]!=-1)//checking if the r memoization table contains the value of OUR CURRENT length alr calculated before
    return r[n];
    int current = -9999999;
    for(int i=1;i<=n;i++){
        current=MAX(current,p[i]+cr_recursive(p,n-i));
        r[n]=current;
    }
    return current;
}

int cr_bottom_up_dp(int *p, int n)
{
    //write your code here
    for(int i=0;i<n;i++) r[i]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){//for each length costantly compare current entry w value of all prev combinations and find the max, ie if filling up 5th entry, try 1 and 4, 2 and 3, 3 and 2 , 4 and 1 and current which is 0, the store the max
            r[i]=MAX(r[i],p[j]+r[i-j]);
        }
    }
    return r[n];
}
 
void main ()
{
    int n;      //length of  rod
    int function;
    int i;
    int *p;     //price list
    
    int price_list[10] = {0,1,5,8,9,10,17,17,20,24}; //declare one more value to cover the index 0;
    
    n = sizeof(price_list) / sizeof(int) - 1;
    p = price_list;
    
    
    //allocate the memory array
    r = malloc(sizeof(int) * (n+1));
    
    printf("Choose a function (1 for recursive, 2 for top-down DP, 3 for bottom-up DP, 0 to stop): \n");
    scanf("%d",&function);
    while (function != 0)
    {
        if (function == 1)
        {
            printf("The maximun value is: %d \n", cr_recursive(p,n));
        }
        else if (function == 2)
        {
            //set all memory elements to -1
            for (i=0; i<=n; i++)
                r[i] = -1;
                
            printf("The maximun value is: %d \n", cr_top_down_dp(p,n));
        }
        else if (function == 3)
        {
            //set all memory elements to -1
            for (i=0; i<=n; i++)
                r[i] = -1;
                
            printf("The maximun value is: %d \n", cr_bottom_up_dp(p,n));
        }
        printf("Choose a function (1 for recursive, 2 for top-down DP, 3 for bottom-up DP, 0 to stop): \n");
        scanf("%d",&function);
    }
    free(r);
}