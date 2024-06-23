#include<stdio.h>

int main(void)
{
    int height=0;
    printf("Enter the height:\n");
    scanf("%d",&height);
    
    printf("Pattern:\n");
    
    for(int i=1;i<=height;i++)
    {
        int display=display_num(i);

        
        for(int j=0;j<i;j++)
        {
            printf("%d",display);
        }
        printf("\n");
    }
	
	return 0;
	
}

int display_num(int input)
{
    if(input%3==0)
    {
        return 3;
    }
    else
    {
        return input%3;
    }
}

/*
SUGGESTED SOLUTIONS
#include<stdio.h>
int main()
{
    int row, col, height;
    int num=0;
    printf("Enter the height:\n");
    scanf("%d",&height);

    printf("Pattern:\n");
    for(row=0;row<height;row++)
    {
        for(col=0;col<row+1;col++)
        {
            printf("%d",num+1);
        }
        num= (num+1)%3;
        printf("\n");
    }
}*/