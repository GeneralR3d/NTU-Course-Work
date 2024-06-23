package q2;
public class Point{
    private int x;
    private int y;

    public Point(int x,int y){
        this.x=x;
        this.y=y;
    }

    public String toString(){
        String output="[ "+ this.x+ ","+ this.y+" ]";
        return output;
    }

    public void setPoint(int x, int y){
        this.x=x;
        this.y=y;
    }

    public int getX(){
        return this.x;
    }

    public int getY(){
        return this.y;
    }
}