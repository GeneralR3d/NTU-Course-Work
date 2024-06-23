#include<stdio.h>
#include<stdlib.h>
#include<math.h>//for ceil()
//#define MAX(i, j) (((i) > (j)) ? (i) : (j))
#define MIN(i, j) (((i) < (j)) ? (i) : (j))

int collectFrequencyDistribution();
void printHistogram(int array[],int size,int spacing);
int main(void)
{
    int numberOfInts=0,numberSpacing=0,size=0;
    int p;//for scanf
    do
    {
        printf("Enter how many numbers to be generated:\n");
        p=scanf("%d",&numberOfInts);
    } 
    while (p!=1 || numberOfInts<=0);

    numberSpacing=collectFrequencyDistribution();

    size=ceil((float)100/numberSpacing);
    int histogram[100]={0};
    //generation
    for(int i=0,num=0;i<numberOfInts;i++)
    {
        num= rand()%100;
        histogram[num/numberSpacing]++;
       
    }
    //printf("Size is %d\n",size);
    printHistogram(histogram,size,numberSpacing);


    
}

int collectFrequencyDistribution(void)
{
    int user;
    int p;//for scanf
    do
    {
        printf("Enter the frequency distribution of the numbers:\n");
        p= scanf("%d",&user);
    }
    while(p!=1 || user<1 || user>10);
    return user;
}

void printHistogram(int array[],int size,int spacing)
{
    int start=0,end=0;
    for(int i=0;i<size;i++)
    {   
        end=MIN(start+spacing-1,100);
        printf("%d - %d |",start,end);
        for(int j=0,n=array[i];j<n;j++)
        {
            printf("*");
        }
        printf("\n");
        start+=spacing;

    }
}
//SUGGESTED SOLUTIONS
/*********************************************
 * **************************************************
 * *************************************************
 * 
*/

//SUGGESTED SOLUTIONS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void getFrequency(int histogram[10],int n);
void printFrequency(int histogram[10]);
int main()
{
    int frequencies[10];
    int total;

    printf("Please input the total number of random numbers:\n");
    scanf("%d",&total);
    srand(time(NULL));
    getFrequency(frequencies,total);
    printFrequency(frequencies);
    return 0;
}

// the "/" operator will divide the data(0-99) into 10 categories/groups (ie 0 to 9). Each category wil form an index for the array.
//call by reference is used
void getFrequency (int histogram[10], int n)
{
    int count;
    

    for(count=0;count<10;count++)
    {
        histogram[count]=0;
    }
    for(count=0;count<n;count++)
    {
        histogram[(rand()%100)/10]++;
    }
}

//OR THIS
void getFrequency (int histogram[10], int n)
{
   
    int category;

    for(count=0;count<10;count++)
    {
        histogram[count]=0;
    }
    for(count=0;count<n;count++)
    {
        category= (rand()%100)/10;
        histogram[category]++;
    }
}


void printFrequency( int histogram[10])
{
    int count, index;

    for(count=0;count<10;count++)
    {
        printf("%2d--%2d  |",count*10,count*10+9)
        for(index=0;index<histogram[count];index++)
        {
            putchar("*");
        }
        putchar("\n");
    }
}
