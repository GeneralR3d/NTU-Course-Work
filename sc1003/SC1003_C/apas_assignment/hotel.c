#include<stdio.h>
#include<string.h>
#include<strings.h>
#include<stdlib.h>
#define MAX 5

typedef struct
{
    int roomID;
    int status;
    char customerName[20];
} Room;

void listOccupiedRooms(Room* Hotel);
void assignRoom(Room* Hotel);
void removeRoom(Room* Hotel);
void findCustomer(Room* Hotel);
int main(void)
{
    //create choice and array of rooms called Hotel
    int choice;
    Room Hotel[MAX];
    char user[5];

    //populate the Hotel with roomID,all rooms unoccupied
    for(int i=0;i<MAX;i++)
    {
        Hotel[i].roomID=i+1;
        Hotel[i].status=0;
        //Hotel[i].customerName=NULL;
    }
    
    

    printf("NTU HOTEL ROOM RESERVATION PROGRAM:\n");
    printf("1: listOccupiedRooms()\n");
    printf("2: assignRoom()\n");
    printf("3: removeRoom()\n");
    printf("4: findCustomer()\n");
    printf("5: quit\n");

    do
    {
        printf("Enter your choice:\n");
        fgets(user,5,stdin);
        choice=atoi(user);
        switch (choice)
        {
            case 1:
                printf("listOccupiedRooms():\n");
                listOccupiedRooms(Hotel);
                break;
            case 2:
                printf("assignRoom():\n");
                assignRoom(Hotel);
                break;
            case 3:
                printf("removeRoom():\n");
                removeRoom(Hotel);
                break;
            case 4:
                printf("findCustomer():\n");
                findCustomer(Hotel);
                break;
            case 5:
                break;
        }
    } 
    while (choice!=5);
    
    
}

void listOccupiedRooms(Room* Hotel)
{
    //assume it is empty first
    int empty=1;
    for(int i=0;i<MAX;i++)
    {
        if(Hotel[i].status ==1)
        {
            printf("roomID: %d\n",Hotel[i].roomID);
            printf("customer name: %s\n",Hotel[i].customerName);
            empty=0;
        }
    }
    if(empty)
    {
        printf("The hotel is empty\n");
    }
    return;    
    
}

void assignRoom(Room* Hotel)
{
    //check if the hotel is full, assume it is full first
    int full=1,selectedRoom=-1,OK=0;
    char* p;
    char user[5];


    for(int i=0;i<MAX;i++)
    {
        if(Hotel[i].status ==0)
        {
            full=0;
            break;
        }
    }
    
    if(full)
    {
        printf("The hotel is full\n");
        return;
    }

    //get user selectedRoom and check if that room is occupied
    while(!OK)
    {
        printf("Enter a roomID between 1 and %d:\n",MAX);
        fgets(user,5,stdin);
        selectedRoom=atoi(user);
        if(selectedRoom>MAX || selectedRoom<1)
        {
            continue;
        }

        if(Hotel[selectedRoom-1].status == 1)
        {
            printf("Occupied! Enter another roomID\n");
            continue;
        }

        printf("Enter customer name:\n");
        fgets(Hotel[selectedRoom-1].customerName,20,stdin);
        if(p=strchr(Hotel[selectedRoom-1].customerName,'\n'))
        {
            *p='\0';
        }
        Hotel[selectedRoom-1].status=1;
        OK=1;
        printf("The room has been assigned successfully\n");

    } 
    return;
}

//if empty will return 1
void removeRoom(Room* Hotel)
{
    //check if the hotel is empty, assume it is empty first
    int empty=1,selectedRoom=-1,OK=0;
    char user[5];
    for(int i=0;i<MAX;i++)
    {
        if(Hotel[i].status !=0)
        {
            empty=0;
            break;
        }
    }
    if(empty)
    {
        printf("All the rooms are empty\n");
        return;
    }

    //get user selectedRoom and check if that room is occupied
    while(!OK)
    {
        printf("Enter a roomID between 1 and %d:\n",MAX);
        fgets(user,5,stdin);
        selectedRoom=atoi(user);
        if(selectedRoom>MAX || selectedRoom<1)
        {
            continue;
        }

        if(Hotel[selectedRoom-1].status == 0)
        {
            printf("Empty! Enter another roomID for removal\n");
            continue;
        }

        
        Hotel[selectedRoom-1].status=0;
        //Hotel[selectedRoom-1].customerName=NULL;
        OK=1;
        printf("Removal is successful\n");

    } 
    return;

    
    
}
void findCustomer(Room* Hotel)
{
    char name[20];
    char* p;

    printf("Enter customer name:\n");
    fgets(name,20,stdin);
    if(p=strchr(name,'\n'))
    {
        *p='\0';
    }
    for(int i=0;i<MAX;i++)
    {
        if(strcasecmp(Hotel[i].customerName,name)==0)
        {
            printf("The target customer name is found\n");
            printf("roomID: %d\n",Hotel[i].roomID);
            printf("customer name: %s\n",Hotel[i].customerName);
            return;
        }
    }
    printf("The target customer name is not found\n");
    return;

}