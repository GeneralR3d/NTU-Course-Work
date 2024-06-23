#include <stdio.h>
#include <stdlib.h>

//////////new functions i created////////////
int dfs_ff(int start, int end, ListNode** adjlist, int tnode);
int connected(ListNode* adjlist, int vertex);

int main()
{
    int prj, std, mtr; //Project, Student and Mentor;
    scanf("%d %d %d", &std, &prj, &mtr);

    int np,nm; //number of projects and number of mentors
    int i, j;
    int temp;
    int totalnodeP = std+prj+2;
    int totalnodeM = std+mtr+2;

    ///indexing method//////////////////////////
    //starting node index 0
    int start = 0;
    //students numbered from 1 to std
    //prj from std+1 to std+prj
    //mtr from std+1 to std+mtr
    //ending nodes index
    int endP = totalnodeP-1;
    int endM = totalnodeM-1;
    //////////////////////////////////////

    //two seperate graphs
    //one for student to proj (P)
    //one for student to mentor (M)
    //initialise 2 adjlist

    //initialise some arrays to check
        //if student is assigned both mentor and proj
        //if a proj has been assigned
        //if a mentor is assigned


    //create both adjlists from user input (directional)
    //means under adjlistP[0] you can find student 1
    //but under adjlistP[1] there is no 0
    //etc

    while (1) //or can use a for loop with fixed number to terminate
    {
        //current proj match = 0
        //current mentor match = 0 

        //one round of selection
        while (dfs_ff(start, endP, adjlistP, totalnodeP)) currentprojmatch++;
        
        //filter out students that got a match w project
        //let those students choose mentor (edit adjlistM)
        while (dfs_ff(start, endM, adjlistM, totalnodeM)) currentmentormatch++;

        //filter out students that matched with both mentor and project
        //use array to store which students are done with assigning

        //loop terminating criteria

        //reset for next round
        //removing students, mentors, projects that have been chosen
    }

    //count how many students got a match
    //print n return
}

int dfs_ff(int start, int end, ListNode** adjlist, int tnode)
{
    //use a stack to find a path from start to end
    //if path found
        //reverse directions and return 1;
    //if no path return 0;
}

int connected(ListNode* adjlist, int vertex)
{
    //if vertex is connected to adjlist return 1;
    //else return 0; 
}