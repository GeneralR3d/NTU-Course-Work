#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

int extractnum(char* s);
int main(int argc, char* argv[])
{
    // to store the execution time of code
    double time_spent = 0.0;
 
    clock_t begin = clock();

    if(argc!=2)
    {
        printf("Usage: ./RNgenerator TEXTFILE.txt\n");
        return 1;
    }

    FILE* out = fopen(argv[1],"w");
    if(out==NULL)
    {
        printf("Error opening file\n");
        return 2;
    }

    int SIZE= extractnum(argv[1]);
    if(SIZE==0)
    {
        printf("Enter no. of elements in sorted file:\n");
        scanf("%d",&SIZE);
    }

    srand(time(NULL));

    // int mult=28922;//Linear congruential generator
    // int mod = pow(2,31)-1;
    // int increment= 1;

    //int num=838390;
    long one;
    long two;
    for(int i=0;i<SIZE;i++)
    {
        one=rand();
        two=rand();
        // num=(mult* num + increment) %mod; //Linear congruential generator
        fprintf(out,"%d\n",(one*two)%SIZE);

    }


    fclose(out);
    
    
    clock_t end = clock();
    
    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("The elapsed time is %f seconds", time_spent);

}
int extractnum(char* s)
{
    for(int i=0,n=strlen(s);i<n;i++)
    {
        if(isdigit(s[i]))
        return atoi(&s[i]);
    }
    return 0;
}

