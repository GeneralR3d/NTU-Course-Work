#include<stdio.h>
#include<math.h>

struct circle{
    double radius;
    double x;
    double y;
};
int intersect(struct circle c1, struct circle c2);
int contain(struct circle c1, struct circle c2);
int main(void)
{
    struct circle c1;
    struct circle c2;

    printf("Enter the radius and coordinates of the 2 circles\n");
        do
        {
        printf("Enter radius of c1: ");
        scanf("%lf",&c1.radius);
        }while(c1.radius<1);


        printf("Enter x coordinate of c1 center: ");
        scanf("%lf",&c1.x);
        printf("Enter y coordinate of c1 center: ");
        scanf("%lf",&c1.y);

        do
        {       
        printf("Enter radius of c2: ");
        scanf("%lf",&c2.radius);
        }while(c2.radius<1);


        printf("Enter x coordinate of c2 center: ");
        scanf("%lf",&c2.x);
        printf("Enter y coordinate of c2 center: ");
        scanf("%lf",&c2.y);

        if(contain(c1,c2))
        {
            printf("C1 contains C2 and they also intersect!");
            return 0;
        }
        else if(intersect(c1,c2))
        {
            printf("C1 and C2 intersects each other!");
            return 0;
        }
        else
        {
            printf("C1 and C2 do not intersect!");
            return 0;
        }

}

int intersect(struct circle c1, struct circle c2)
{
    //(x2-x1)^2+(y2-y1)^2 whole thing square root <= radius1 + radius2
    return sqrt(pow(c1.x-c2.x,2)+pow(c1.y-c2.y,2)) <= (c1.radius+c2.radius);
}
int contain(struct circle c1, struct circle c2)
{
    // radius 1 >= (x2-x1)^2+(y2-y1)^2 whole thing square root + radius2
    return c1.radius >= (sqrt(pow(c1.x-c2.x,2)+pow(c1.y-c2.y,2)) + c2.radius);
}









/*SUGGESTED SOLUTIONS
*
*
*
*
*
*
*
*/
int main()
{
    int choice, result;
    do
    {
    printf("Enter choice:\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        printf("Enter circle 1 (radius x y): \n");
        scanf("%lf %lf %lf",&c1.radius,&c1.x,&c1.y);
        printf("Enter circle 2 (radius x y): \n");
        scanf("%lf %lf %lf",&c2.radius,&c2.x,&c2.y);

        result = intersect(c1,c2);
        if(result ==1)
            printf("intersect(): intersect\n");
        else if(result ==0);
            printf("intersect(): not intersect\n");
        else
            printf("intersect(): error\n");

        break;

        case 2:
        printf("Enter circle 1 (radius x y): \n");
        scanf("%lf %lf %lf",&c1.radius,&c1.x,&c1.y);
        printf("Enter circle 2 (radius x y): \n");
        scanf("%lf %lf %lf",&c2.radius,&c2.x,&c2.y);

        result = contain(&c1,&c2);
        if(result ==1)
            printf("contain(): contain\n");
        else if(result ==0);
            printf("contain(): not contain\n");
        else
            printf("contain(): error\n");

        break;

    }
    while (choice <3);
    return 0;
   
    

}

int intersect(struct circle c1, struct circle c2)
{
    double a,b;
    a=c1.x-c2.x;
    b=c1.y-c2.y;
    return sqrt(a*a + b*b) <= (c1.radius + c2.radius);
}

int contain(struct circle* c1, struct circle* c2)
{
    double a,b;
    a=c1->x - c2->x;
    b=c1->y - c2->y;
    return (c1->radius >= (c2->radius + sqrt(a*a + b*b)));
}