

public class PlaneSeat{
    private int seatId;
    private boolean assigned;
    private int customerId;

    //constructor
    public PlaneSeat(int seatId){
        this.seatId=seatId;
        assigned=false;
    }

    //getter
    public int getSeatID(){
        return this.seatId;
    }

    public int getCustomerID(){
        return this.customerId;
    }

    public boolean isOccupied(){
        return this.assigned;
    }

    //setter
    public void assign(int customerId){
        this.customerId=customerId;
        assigned=true;
    }

    public void unAssign(){
        this.customerId=-1;
        assigned = false;
    }
}