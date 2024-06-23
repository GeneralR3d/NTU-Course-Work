import java.util.Scanner;

import javax.swing.plaf.synth.SynthStyle;
public class CalculatorEx {
    
    private static double result;

    //constructor that does nothing
    public CalculatorEx(){
        ;
    }

    //main
    public static void main(String[]args){
        System.out.println("Calculator is on");
        System.out.println("result= "+resultValue());
        Scanner sc = new Scanner(System.in);
        do{
            char operator = sc.nextLine().charAt(0);
            switch(operator){
                case '+':
                case '-':
                case '*':
                case '/':
                    doCalculation(char op):
                    break;
                case 'q':
                    break;
                default:
                    throw UnknownOperatorException(operator);
            }
            
        }while
    }

    public static double resultValue(){
        return result;
    }

    public static doCalculation(char op){

    }
}   
