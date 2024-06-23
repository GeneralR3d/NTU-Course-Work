	/*edit*/

/*custom header*/
#include <string.h>
	/*end_edit*/
#include <stdio.h>
typedef struct {
   char name[20]; 
   int age;
} Person;
void readData(Person *p);
Person findMiddleAge(Person *p);
int main() 
{
   Person man[3], middle;   
  
   readData(man);
   middle = findMiddleAge(man);
   printf("findMiddleAge(): %s %d\n", middle.name, middle.age);
   return 0;
}
void readData(Person *p) 
{
	/*edit*/
	/* Write your code here */
	//assumming 3 people given in question

	char buffer[30];
	char *q;
	
	for(int i=0;i<3;i++)
	{
	    printf("Enter person %d:\n",i+1);
	    fgets(buffer,30,stdin);
	    if(q=strchr(buffer,'\n'))
	    *q='\0';
	    sscanf(buffer,"%s %d",&p[i].name,&p[i].age);    //suggested solution is just to use 2 scanf, string first then int, so its permissible

        //or
        //scanf("%s %d",&p[i].name,&p[i].age);
	 
	    
	    
	}

	/*end_edit*/
}
Person findMiddleAge(Person *p) 
{
	/*edit*/
	/* Write your code here */
    if(p[0].age>=p[1].age && p[0].age<=p[2].age)
    {
        return p[0];
    }
    else if(p[1].age>=p[0].age && p[1].age<=p[2].age)
    {
        return p[1];
    }
    else
    {
        return p[2];
    }


	/*end_edit*/
}

//SUGGESTED SOLUTIONS
Person findMiddleAge(Person* p)
{
    int i, max,min;
    max=min=p[0].age;
    for(i=1;i<3;i++)//get max and min first
    {
        if(p[i].age>max)
        max=p[i].age;
        else if(p[i].age<min)
        min=p[i].age;

    }
    for(i=0;i<3;i++)//then check the middle value
    {
        if(p[i].age !=max && p[i].age != min)
        return p[i]
    }
}