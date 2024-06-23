public class Plane{
    private PlaneSeat[] seat;
    private int numEmptySeat;
    public static final int MAX_SEATS = 12;

    public Plane(){
        seat= new PlaneSeat[MAX_SEATS];
        for(int i=0;i<MAX_SEATS;i++){
            seat[i]=new PlaneSeat(i+1);
        }
        numEmptySeat = MAX_SEATS;
    }

    private PlaneSeat[] sortSeats(){

        PlaneSeat[] copySeat = seat.clone();

        //insertion sort
        for(int i=1;i<copySeat.length;i++){
            for(int j=i;j>0;j--){
                if(copySeat[j].getCustomerID() < copySeat[j-1].getCustomerID()){
                    PlaneSeat temp= copySeat[j];
                    copySeat[j]=copySeat[j-1];
                    copySeat[j-1]=temp;
                }
                else{
                    break;
                }
            }
        }
        return copySeat;
    }

    //getter
    public void showNumEmptySeats(){
        System.out.println("There are "+ numEmptySeat + " empty seats");
    }

    //methods
    public void showEmptySeats(){
        System.out.println("The following seats are empty: ");

        for(PlaneSeat i : seat){
            if(i.isOccupied()==false){
                System.out.println("SeatID "+ i.getSeatID());
            }
        }
    }

    public void showAssignedSeats(boolean bySeatId){

        if(bySeatId){
            System.out.println("The seat assignments are as follows:");

            for(int i=0;i<seat.length;i++){
                if(seat[i].isOccupied()==true){
                    System.out.println("SeatID " + (seat[i].getSeatID()) + " assigned to CustomerID " + seat[i].getCustomerID());
                }
            }
        }
        else{
            PlaneSeat[] copySeat = sortSeats();
            System.out.println("The seat assignments are as follows:");

            for(int i=0;i<copySeat.length;i++){
                if(copySeat[i].isOccupied()==true){
                    System.out.println("SeatID " + (copySeat[i].getSeatID()) + " assigned to CustomerID " + copySeat[i].getCustomerID());
                }
            }
        }
        
    }

    public void assignSeat(int seatID,int customerID){

        if(seatID>seat.length){
            System.out.println("Invalid seat!");
            return;
        }

        for(PlaneSeat i: seat){
            if(i.getSeatID()==seatID && i.isOccupied()==false){
                i.assign(customerID);
                this.numEmptySeat--;
                System.out.println("Seat Assigned!");
                return;
            }
        }
        System.out.println("Seat already assigned to a customer.");
        return;

    }

    public void unAssignSeat(int seatID){
        if(seatID>seat.length){
            System.out.println("Invalid seat!");
            return;
        }

        for(PlaneSeat i: seat){
            if(i.getSeatID()==seatID){
                i.unAssign();
                this.numEmptySeat++;
                System.out.println("Seat Unassigned!");
                return;
            }
        }
    }

}