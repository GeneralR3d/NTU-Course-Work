#include <stdio.h>
#include<math.h>

double calDistanceByValue(double x1, double x2, double y1, double y2);
void calDistanceByReference(double x1, double x2, double y1, double y2,double*dist);
int main(void)
{
    double x1=0,x2=0,y1=0,y2=0,distance=0;

    printf("Enter x and y coordinates of point1 (e.g. a,b):\n");
    scanf("%lf,%lf",&x1,&y1);
    printf("Enter x and y coordinates of point2 (e.g. a,b):\n");
    scanf("%lf,%lf",&x2,&y2);

    //distance = calDistanceByValue(x1,x2,y1,y2);
    calDistanceByReference(x1,x2,y1,y2,&distance);
    printf("The distance between 2 points is: %lf\n",distance);
}


double calDistanceByValue(double x1, double x2, double y1, double y2)
{
    return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

void calDistanceByReference(double x1, double x2, double y1, double y2,double* dist)
{
    *dist = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}