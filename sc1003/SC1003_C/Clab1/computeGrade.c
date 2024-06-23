#include<std.io.h>

int main(void)
{

	int ID=0;
   int mark=0;
   
   while(ID!=-1)
   {
    printf("Enter Student ID:\n");
    scanf("%d",&ID);
    
    printf("Enter Mark:\n");
    scanf("%d",&mark);
    
    switch((mark+5)/10)
    {
        case 1:
        case 2:
        case 3:
        case 4:
        printf("Grade = F\n");
        break;
        
        case 5:
        printf("Grade = D\n");
        break;
        
        case 6:
        printf("Grade = C\n");
        break;
        
        case 7:
        printf("Grade = B\n");
        break;
        
        case 8:
        case 9:
        case 10:
        printf("Grade = A\n");
        break;
        
        default:
        printf("Error number please key in properly!\n");
    }
	
	}
	
	return 0;
	
	}