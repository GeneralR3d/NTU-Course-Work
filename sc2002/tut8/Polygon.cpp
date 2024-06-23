#include <string>
#include <iostream>


class Polygon{

    //attributes

    public: 
        enum KindofPolygon { POLY_PLAIN, POLY_RECT, POLY_TRIANG};
    protected:
        std::string name; 
        float width;
        float height;
        KindofPolygon polytype;

    
        
    public:
        //constructor
        Polygon(std::string theName, float theWidth, float theHeight):name(theName),width(theWidth),height(theHeight){
            polytype = KindofPolygon::POLY_PLAIN;
        }

        //getters
        KindofPolygon getPolytype(){
            return polytype;
        }

        //setters
        void setPolytype(KindofPolygon value){
            polytype = value;
        }

        //methods
        std::string getName(){ 
            return name; 
        }
        virtual float calArea() = 0;

        void printWidthHeight(){
            std::cout << "Width = " << width << " Height = " << height;
        }
        //destructor
        ~Polygon(){
            ;
        }
    };

class Rectangle: public Polygon{
    public:
        //constructor
        Rectangle(std::string theName, float theWidth, float theHeight): Polygon::Polygon(theName,theWidth,theHeight){
            polytype = Polygon::KindOfPolygon::POLY_RECT;
        }
        //methods
        float calArea(){
            return width * height;
        }
        //destrtuctor
        ~Rectangle(){
            ;
        }
};

class Triangle: public Polygon{
    public:
        //constructor
        Triangle(std::string theName, float theWidth, float theHeight): Polygon::Polygon(theName,theWidth,theHeight){
            polytype = KindOfPolygon::POLY_TRIANG;
        }
        //methods
        float calArea(){
            return 0.5*width * height;
        }
        //destructor
        ~Triangle(){
            ;
        }
};


void printArea(Polygon &p){
    std::cout<< "The area is "<< p.calArea();
}

int main(){
    Rectangle r("Big Rectangle", 10, 5);
    printArea(r);

    Triangle t("Big Triangle", 10, 4);
    printArea(t);
}



