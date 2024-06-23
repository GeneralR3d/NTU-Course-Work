import java.util.Scanner;

import javax.swing.plaf.synth.SynthEditorPaneUI;

import java.lang.Math;

public class Lab2p1 {
 public static void main(String[] args)
 {
    int choice;
    Scanner sc = new Scanner(System.in);
    do {
            System.out.println("Perform the following methods:");
            System.out.println("1: multiplication test");
            System.out.println("2: quotient using division by subtraction");
            System.out.println("3: remainder using division by subtraction");
            System.out.println("4: count the number of digits");
            System.out.println("5: position of a digit");
            System.out.println("6: extract all odd digits");
            System.out.println("7: quit");
            choice = sc.nextInt();
            switch (choice) {
            case 1: /* add mulTest() call */
            mulTest();
            break;
            case 2: /* add divide() call */

            System.out.println("Enter divisor:");
            int m=sc.nextInt();
            System.out.println("Enter dividend:");
            int n=sc.nextInt();
            System.out.printf("%d/%d = %d\n",m,n,divide(m, n));
            break; 
            case 3: /* add modulus() call */
            System.out.println("Enter divisor:");
            int a=sc.nextInt();
            System.out.println("Enter dividend:");
            int b=sc.nextInt();
            int c =modulus(a, b);
            System.out.println(a + " % " + b + " = "+ c);
            break; 
            case 4: /* add countDigits() call */
            System.out.println("Enter positive integer:");
            int d=sc.nextInt();
            int numOfDigits= countDigits(d);
            String printedAnswer = numOfDigits <= 0 ? "Error input!!" : String.valueOf(numOfDigits);
            System.out.println("n: "+ d + " - count = " + printedAnswer);
            break;
            case 5: /* add position() call */
            System.out.println("Enter positive integer:");
            int e=sc.nextInt();
            System.out.println("Enter digit to check:");
            int f=sc.nextInt();
            int position = position(e, f);
            System.out.println("position = "+ position);
            break; 
            case 6: /* add extractOddDigits() call */
            System.out.println("Enter positive integer:");
            long g=sc.nextLong();
            long oddDigits= extractOddDigits(g);
            String printedAns = oddDigits <= 0 ? "Error input!!" : String.valueOf(oddDigits);
            System.out.println("oddDigits = "+ printedAns);
            break; 
            case 7: System.out.println("Program terminating ….");
        } 
    } while (choice < 7);

    }
 /* add method code here */
 public static void mulTest(){

    final int NUMBER_OF_QNS=5;
    //access modifiers in java are meant for attributes, which are variables declare inside a class, not inside a method of a class
    //for variables declared inside a method, they are local variables and are thus only scoped to the method, they cannot and should not be accessed outside the method
    //so they are not considered attributes of a class, thus it doesnt make sense for them to have any access modifiers to specify who can access these and who cannot
    //static also does not make sense since static variables are used to represent class constants, again belonging to a class, and not just scoped to a method
    //even if the method is static, ie a class method, within that method all variables declared are still local to that method, so static doesnt make sense
    // the only modifier that makes sense is final, which makes the variable constant
    
    int correctAns=0;

    Scanner sc = new Scanner(System.in);

    for(int i=0;i<NUMBER_OF_QNS;i++){

        //Math.random() gives float between 0 and 1, so need to do some manipulation
        //9* float will give numbers from 0-9 after type conversion which truncates the precision
        //(Math.random() *(max - min + 1) + min)
        int num1= (int)(Math.random()* 9) + 1;
        int num2= (int)(Math.random()* 9) + 1;
        System.out.printf("How much is %d times %d? ",num1,num2);
        int answer = sc.nextInt();
        System.out.println("");
        if(answer == num1*num2) correctAns++;
    }

    System.out.printf("%d answers out of %d are correct.\n",correctAns,NUMBER_OF_QNS);


 }

 public static int divide(int m, int n){
    int quotient=0;
    while(m-n>=0){
        m-=n;
        quotient++;
    }
    return quotient;
 }

 public static int modulus(int m, int n){
    int quotient=0;
    while(m-n>=0){
        m-=n;
        quotient++;
    }

    return m;
 }

 public static int countDigits(int n){
    if(n<=0) return n;
    else{
        int numOfDigits=0;
        while(n>0){
            n= divide(n, 10);
            numOfDigits++;
        }
        return numOfDigits;
    }
 }

 public static int position(int n, int digit){
    int position =1;
    
    while(n>0){
        int lastDigit=modulus(n, 10);
        n=divide(n,10);
        if(lastDigit==digit) return position;
        else position++;
    }
    
    
    return -1;
 }

 public static long extractOddDigits(long n){

    if(n<0) return n;

    int finalNum=0;
    int digitsPlace=1;//start from ones place
    while(n>0){
        long lastDigit=n%10;
        n/=10;

        //means the digit is odd
        if(lastDigit%2!=0){
            finalNum+=digitsPlace*lastDigit;
            digitsPlace*=10;

        }
        
    }
    return finalNum==0?-1:finalNum;

 }

}
