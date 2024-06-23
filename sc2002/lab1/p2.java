import java.util.Scanner;

public class p2{
    enum Grade{A,B,C,X};
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter your salary in dollars($): ");
        int salary = sc.nextInt();
        System.out.print("\n");
        System.out.print("Enter your merit points: ");
        int points = sc.nextInt();
        System.out.print("\n");
        System.out.print("Grade- ");
        Grade result =findGrade(salary, points);
        if(result==Grade.X)
            System.out.println("Inavlid grade.");
        else
            System.out.println(result);


    }

    public static Grade findGrade(int salary, int points){
        if (salary>899) return Grade.X;
        if(salary<500) return Grade.X;
        Grade grade;
        if (salary >=800)
            grade=Grade.A;
        else if(salary>=700)
            if(points<20) grade=Grade.B;
            else grade=Grade.A;
        else if(salary>=650)
            grade=Grade.B;
        else if(salary>=600)
            if(points<10) grade=Grade.C;
            else grade=Grade.B;
        else grade=Grade.C;

        return grade;

    }
}