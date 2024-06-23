#include<stdio.h>
#include<stdlib.h>
  

typedef struct {
   int id;           /* staff identifier */  
   int totalLeave;   /* the total number of days of leave allowed */  
   int leaveTaken;   /* the number of days of leave taken so far */ 
} leaveRecord;

void getInput(leaveRecord list[],int *n);
int mayTakeLeave(leaveRecord list[], int id, int leave, int n);
void printList(leaveRecord list[], int n);
int main(void)
{
    int numberOfRecords=0, choice;
    int staffID, requestedLeave, approved;
    leaveRecord* list = (leaveRecord*)malloc(sizeof(leaveRecord));//malloc to allocate space for 1 record first

    printf("NTU LEAVE CHECKING PROGRAM:\n");
    printf("1: getInput()\n");
    printf("2: mayTakeLeave()\n");
    printf("3: printList()\n");
    printf("4: quit\n");


do
    {
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                printf("1: getInput()\n");
                getInput(list,&numberOfRecords);
                list = (leaveRecord*)realloc(list,(numberOfRecords+1)*sizeof(leaveRecord));//subsequently grow the array
                break;
            case 2:
                printf("mayTakeLeave():\n");
                printf("Enter staff ID: ");
                scanf("%d",&staffID);
                printf("Enter number of days of leave you want to take: ");
                scanf("%d",&requestedLeave);

                approved= mayTakeLeave(list,staffID,requestedLeave,numberOfRecords);
                if(approved==-1)
                printf("This person does not exist!\n");
                else if(approved==1)
                printf("Leave APPROVED!\n");
                else
                printf("Leave NOT APPROVED! You dont have so many days abang\n");

                break;
            case 3:
                printf("printList():\n");
                printList(list,numberOfRecords);
                break;
            case 4:
                break;
        }
    } 
    while (choice!=4);

    free(list);
}

void getInput(leaveRecord list[],int *n)
{
        printf("Enter staff identifier: ");
        scanf("%d",&list[*n].id);
        printf("Enter total number of days of leave: ");
        scanf("%d",&list[*n].totalLeave);
        printf("Enter number of days of leave taken: ");
        scanf("%d",&list[*n].leaveTaken);

        *n += 1;
        return;
}
//suggested solutions is better!
int mayTakeLeave(leaveRecord list[], int id, int leave, int n)
{
    int result;
    int i;
    int match=0;
    for(i=0;i<n;i++)
    {
        if(id==list[i].id)
        {
        match=1;
        break;//actually can include the checking inside here also
        }
    }
    if(!match)
    return -1;

    if((list[i].leaveTaken + leave)<=list[i].totalLeave )
    {
        result =1;
        list[i].leaveTaken+=leave;
    }
    else
    {
        result =0;
    }
    return result;
}
void printList(leaveRecord list[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Staff number %d is %d\n",i+1,list[i].id);
        printf("Total number of leave days: %d\n",list[i].totalLeave);
        printf("Number of days of leave taken: %d\n",list[i].leaveTaken);
    }
}

/*SUGGESTED SOLUTIONS
*
*
*
*
*
*
*/
#inlcude<stdio.h>
#define INIT_VALUE 1000
typedef struct {
    int id;
    int totalLeave;
    int leaveTaken;
}leaveRecord;

void getInput(leaveRecord list[],int *n);
int mayTakeLeave(leaveRecord list[], int id, int leave, int n);
void printList(leaveRecord list[], int n);

int main()
{
    leaveRecord listRec[10];// this one initialises the size of the array to be 10, means the max number of records this system can hold is fixed to be 10
    int len;
    int id,leave,canTake=INIT_VALUE;
    int choice;

    printf("NTU LEAVE CHECKING PROGRAM:\n");
    printf("1: getInput()\n");
    printf("2: mayTakeLeave()\n");
    printf("3: printList()\n");
    printf("4: quit\n");

    do{
        printf("Enter choice:\n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                getInput(listRec,&len);
                printList(listRec,len);
                break;
            case 2:
                printList(listRec,len);
                break;
            case 3:
                printf("Please input id, leave to be taken:\n");
                scanf("%d %d",&id,&leave);
                canTake=mayTakeLeave(listRec,id,leave,len);
                
                if(canTake==1)
                    printf("The staff %d can take leave\n",id);
                else if(canTake==0)
                    printf("The staff %d cannot take leave\n",id);
                else if(canTake==-1)
                    printf("The staff %d is not the list\n",id);
                else
                    printf("error!\n");
                break;
        }
    }while(choice<4);
    return 0;
}
//this implementation gets all the records in one go, using while loop
void getInput(leaveRecord list[],int *n)
{
    int total;
    int *n =0;
    printf("Enter the number of staff records:\n");
    scanf("%d",&total);

    while(*n!=total)
    {
        printf("Enter id, totalleave, leavetaken:\n");
        scanf("%d %d %d",&list[*n].id,&list[*n].totalLeave,&list[*n].leaveTaken);

        (*n)++;
    }
}
//bug:?? never upodate the leaveTaken for that person
int mayTakeLeave(leaveRecord list[], int id, int leave, int n)
{
    int p;
    for(p=0;p<n;p++)
    {
        if(list[p].id==id)
        return (list[p].totalLeave >= (list[p].leaveTaken + leave));
    }
    return -1;
}

