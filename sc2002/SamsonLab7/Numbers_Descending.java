package Lab7;

import java.util.Scanner;

public class Numbers_Descending {
    public static void main(String[] args) {
        Integer[] intList;
        int size;
        Scanner scan = new Scanner(System.in);
        System.out.print("\nHow many integers do you want to sort? ");
        size = scan.nextInt();
        intList = new Integer[size];
        System.out.println("\nEnter the numbers...");
        for (int i = 0; i < size; i++) {
            intList[i] = scan.nextInt();
        }
        Sorting.insertionSortDescending(intList); // Call the modified method for descending order
        System.out.println("\nYour numbers in sorted order (descending)...");
        for (int i = 0; i < size; i++) {
            System.out.print(intList[i] + " ");
        }
        System.out.println();
    }
}
