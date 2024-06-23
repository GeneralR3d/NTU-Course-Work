import java.util.Scanner;
public class Strings
{
// --------------------------------------------
// Reads in an array of Strings, sorts them,
// then prints them in sorted order.
// --------------------------------------------
public static void main (String[] args)
{
	String[] StringList;
	int size;
	Scanner scan = new Scanner(System.in);
	System.out.print ("\nHow many Strings do you want to sort? ");
	size = scan.nextInt();
	StringList = new String[size];
	System.out.println ("\nEnter the Strings...");
	for (int i = 0; i < size; i++)
    StringList[i] = scan.next();
		Sorting.insertionSort(StringList);
		System.out.println ("\nYour Strings in sorted order...");
	for (int i = 0; i < size; i++)
		System.out.print(StringList[i] + " ");
	System.out.println ();
	}
}