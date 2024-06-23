#include <stdio.h>
#include <stdlib.h>

//memory
int *r;


int cr_bottom_up_dp_print(int *p, int n)
{
    //write your code here
    for(int i=0;i<n;i++) r[i]=0;
    int firstpiece=0;
    int secondpiece=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){//for each length costantly compare current entry w value of all prev combinations and find the max, ie if filling up 5th entry, try 1 and 4, 2 and 3, 3 and 2 , 4 and 1 and current which is 0, the store the max
            if((p[j]+r[i-j])>r[i]){
                firstpiece=i-j;
                secondpiece=j;
                r[i]=p[j]+r[i-j];
            }
        }
    }
    printf("first piece should be %d long\n",firstpiece);
    printf("second piece should be %d long\n",secondpiece);
    return r[n];
}

 
void main ()
{
    int n;      //length of  rod
    int function;
    int i;
    int *p;     //price list
    
    int price_list[10] = {0,1,4,8,9,10,17,17,20,24}; //declare one more value to cover the index 0;
    
    n = sizeof(price_list) / sizeof(int) - 1;
    p = price_list;
    
    
    //allocate the memory array
    r = malloc(sizeof(int) * (n+1));
    
    
    //set all memory elements to -1
    for (i=0; i<=n; i++)
        r[i] = -1;
                
    printf("The maximun value is: %d \n", cr_bottom_up_dp_print(p,n));
}