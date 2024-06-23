	/*edit*/

/*custom header*/

	/*end_edit*/
#include <stdio.h>
#include <string.h>
#define MAX 100
typedef struct {
   char name[40];
   char telno[40];
   int id;
   double salary;
} Employee;
void printEmp(Employee *emp, int size);
int readin(Employee *emp);
int search(Employee *emp, int size, char *target);
int addEmployee(Employee *emp, int size, char *target);
int main()
{
   Employee emp[MAX];
   char name[40], *p;
   int size, choice, result;
   
   printf("Select one of the following options: \n");
   printf("1: readin() \n");     
   printf("2: search() \n");
   printf("3: addEmployee() \n");
   printf("4: print() \n");
   printf("5: exit() \n");      
   do {
      printf("Enter your choice: \n");
      scanf("%d", &choice);//this scanf generates a invisble '\n' which will affect all future string reads, including fgets
      switch (choice) {
         case 1:           
            size = readin(emp);        
            break;               
         case 2:           
            printf("Enter search name: \n");
            scanf("\n");
            fgets(name, 40, stdin); //before every string read must keep track of the flow, which part of the script leads to here etc. If the prev read from stdin was not fgets, it means it left at '\n' and we need to remove it before this fgets statement
            if (p=strchr(name,'\n')) *p = '\0';
            result = search(emp,size,name);   
            if (result != 1) 
               printf ("Name not found! \n");     
            break;               
         case 3:           
            printf("Enter new name: \n");
            scanf("\n");
            fgets(name, 40, stdin); //before every string read must keep track of the flow, which part of the script leads to here etc. If the prev read from stdin was not fgets, it means it left at '\n' and we need to remove it before this fgets statement
            if (p=strchr(name,'\n')) *p = '\0';
            result = search(emp,size,name);  
            if (result != 1)
               size = addEmployee(emp, size, name);     
            else 
               printf("The new name has already existed in the database\n");
            break;         
         case 4:
            printEmp(emp, size);
            break;
         default: 
            break;
      } 
   } while (choice < 5);
   return 0;
}
void printEmp(Employee *emp, int size) 
{
   int i;
   
   printf("The current employee list: \n");
   if (size==0) 
      printf("Empty array\n");
   else
   {
      for (i=0; i<size; i++) 
         printf("%s %s %d %.2f\n",emp[i].name,emp[i].telno,emp[i].id,
 	emp[i].salary); 
   }
}
int readin(Employee *emp)
{
	/*edit*/
   /* Write your code here */
   char user[40];
   char* p;
   int size=0;
 
   while(1)
   {
       printf("Enter name:\n");
       scanf("\n");
       fgets(user,40,stdin);//before every string read must keep track of the flow, which part of the script leads to here etc. If the prev read from stdin was not fgets, it means it left at '\n' and we need to remove it before this fgets statement
       if(p=strchr(user,'\n'))
       *p='\0';
       if(strcmp(user,"#")==0)
       break;
       
       strcpy(emp->name,user);
       
       printf("Enter tel:\n");
       fgets(user,40,stdin);//before every string read must keep track of the flow, which part of the script leads to here etc. If the prev read from stdin was not fgets, it means it left at '\n' and we need to remove it before this fgets statement
       if(p=strchr(user,'\n'))
       *p='\0';
        strcpy(emp->telno,user);
        
       
       printf("Enter id:\n");
       scanf("%d",&(emp->id));
       printf("Enter salary:\n");
       scanf("%lf",&(emp->salary));
       emp++;
       size++;
    }
    return size;

	/*end_edit*/
}
int search(Employee *emp, int size, char *target)
{
	/*edit*/
   /* Write your code here */
    for(int i=0;i<size;i++)
   {
       if(strcmp(target,emp[i].name)==0)
       {
           printf("Employee found at index location: %d\n",i);
           printf("%s %s %d %.2lf\n",emp[i].name,emp[i].telno,emp[i].id,emp[i].salary);
           return 1;
       }
   }
   return 0;




	/*end_edit*/
}
int addEmployee(Employee *emp, int size, char *target)
{
	/*edit*/
   /* Write your code here */
   char user[40];
   char*p;
   if(size==MAX)
   {
       printf("Database is full\n");
       return size;
   }
   strcpy(emp[size].name,target);
   
   printf("Enter tel:\n");
   fgets(user,40,stdin);//before every string read must keep track of the flow, which part of the script leads to here etc. If the prev read from stdin was not fgets, it means it left at '\n' and we need to remove it before this fgets statement
   if(p=strchr(user,'\n'))
   *p='\0';
    strcpy(emp[size].telno,user);
    
   
   printf("Enter id:\n");
   scanf("%d",&(emp[size].id));
   printf("Enter salary:\n");
   scanf("%lf",&(emp[size].salary));
   
   printf("Added at position: %d\n",size);
   
   return size+1;

	/*end_edit*/
}