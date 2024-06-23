public class UnknownOperatorException extends Exception {
    
    //constructors
    public UnknownOperatorException(){
        super("Unknown Operator Exception is called!");
    }

    public UnknownOperatorException(char op){
        super(op + " is an unknown operator");
    }

    public UnknownOperatorException(String message){
        super(message);
    }
}
