package Lab7;

import java.util.Objects;

public class SalePerson implements Comparable<SalePerson> {
    private String firstName;
    private String lastName;
    private int totalSales;

    // Constructor
    public SalePerson(String firstName, String lastName, int totalSales) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.totalSales = totalSales;
    }

    // Getters
    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public int getTotalSales() {
        return totalSales;
    }

    // toString method
    @Override
    public String toString() {
        return lastName + ", " + firstName + " : " + totalSales;
    }

    // equals method
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        SalePerson salePerson = (SalePerson) o;
        return Objects.equals(firstName, salePerson.firstName) &&
               Objects.equals(lastName, salePerson.lastName);
    }

    // compareTo method
    @Override
    public int compareTo(SalePerson o) {
        int salesComparison = Integer.compare(this.totalSales, o.totalSales);
        
        if (salesComparison != 0) {
            return salesComparison; // Compare by total sales
        } else {
            return this.lastName.compareTo(o.lastName); // Break the tie by last name in ascending order
        }
    }
}
