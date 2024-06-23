	/*edit*/

/*custom header*/

	/*end_edit*/
#include <stdio.h>
#include <string.h>
struct student{
   char name[20]; /* student name */
   double testScore; /* test score */
   double examScore; /* exam score */
   double total;  /* total = (testScore+examScore)/2 */
};
double average();
int main()
{
   printf("average(): %.2f\n", average());           
   return 0;
}
double average()
{
	/*edit*/
   /* Write your program code here */
   struct student group[50];
   char user[20];
   char*p;
   double sumOfAll=0;
   int i=0;
   while(1)
   {
       printf("Enter student name:\n");
       fgets(user,20,stdin);
       if(p=strchr(user,'\n'))
       *p='\0';
       if(strcmp(user,"END")==0)
       break;
       
       strcpy(group[i].name,user);
       
       printf("Enter test score:\n");
       scanf("%lf",&(group[i].testScore));
       
        printf("Enter exam score:\n");
       scanf("%lf",&(group[i].examScore));
       scanf("\n");
       
       group[i].total=(group[i].testScore + group[i].examScore)/2;
       printf("Student %s total = %.2lf\n",group[i].name,group[i].total);
       sumOfAll+=group[i].total;
       i++;
   }
   if(sumOfAll<1e-11)
   {
       return 0;
   }
   return sumOfAll/(i);
   
   


	/*end_edit*/
}