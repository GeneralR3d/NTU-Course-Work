
public class SalePerson implements Comparable{
    private String firstName;
    private String lastName;
    private int totalSales;

    // constructor
    public SalePerson(String firstName, String lastName, int totalSales){
        this.firstName = firstName;
        this.lastName = lastName;
        this.totalSales = totalSales;
    }

    // methods
    @Override
    public String toString(){
        return (this.lastName + " ," + this.firstName + " : "+ this.totalSales);
    }

    @Override
    public boolean equals(Object o){
        if(o instanceof SalePerson){
            SalePerson o1 = (SalePerson) o;
            return o1.getFirstName().equals(this.firstName) && o1.getLastName().equals(this.lastName);
        }
        return false;

    }

    @Override
    public int compareTo(Object o){
        if(o instanceof SalePerson){
                SalePerson o1 = (SalePerson) o;
                if(this.totalSales > o1.getTotalSales() ){
                    return 1;
                }
                else if( this.totalSales < o1.getTotalSales()){
                    return -1;
                }
                else{
                    return o1.getLastName().compareTo(this.lastName);
                }
        }
        return 0;
    }




    // getter
    public String getFirstName(){
        return this.firstName;
    }

    public String getLastName(){
        return this.lastName;
    }

    public int getTotalSales(){
        return this.totalSales;
    }
}