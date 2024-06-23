#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) ((a)>(b)?a:b)
int longestCommonSubsequence(char * text1, char * text2,int start1, int start2);
int mem[7][8];



void main(void){

    char* text1=(char*)malloc(sizeof(char)*6+1);
    text1="aggtab";
    char* text2=(char*)malloc(sizeof(char)*7+1);
    text2="gxtxayb";
    for(int i=0;i<7;i++)
{
for(int j=0;j<8;j++)
mem[i][j]=-1;
}

    printf("longest is %d\n",longestCommonSubsequence(text1,text2,0,0));

}

int longestCommonSubsequence(char * text1, char * text2,int start1, int start2){
    //printf("start 1 is %d\n",start1);
    //printf("start 2 is %d\n",start2);

    int answer=0;
    if(text1[start1]=='\0'||text2[start2]=='\0') mem[start1][start2]=0;
    else if(mem[start1][start2]!=-1);//if alr stored do nothing, if not stored then store
    else{
        if(text1[start1]==text2[start2]){
            //printf("%c\n",text1[start1]);
            //printf("%c\n",text2[start2]);

         mem[start1][start2]= 1+ longestCommonSubsequence(text1,text2,start1+1,start2+1);
        }
        else mem[start1][start2]= MAX(longestCommonSubsequence(text1,text2,start1+1,start2),longestCommonSubsequence(text1,text2,start1,start2+1));

    }
    answer=mem[start1][start2];
    return answer;
}

