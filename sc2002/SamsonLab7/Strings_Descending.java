package Lab7;
import java.util.Scanner;

public class Strings_Descending {
    public static void main(String[] args) {
        String[] stringList;
        int size;
        Scanner scan = new Scanner(System.in);
        System.out.print("\nHow many strings do you want to sort? ");
        size = scan.nextInt();
        stringList = new String[size];
        scan.nextLine(); // Consume the newline character
        System.out.println("\nEnter the strings...");
        for (int i = 0; i < size; i++) {
            stringList[i] = scan.nextLine();
        }
        Sorting.insertionSortDescending(stringList); // Call the modified method for descending order
        System.out.println("\nYour strings in sorted order (descending)...");
        for (int i = 0; i < size; i++) {
            System.out.println(stringList[i]);
        }
    }
}
