#include <iostream>
using namespace std;

class point{
    public:
        point(double x=0.0, double y=0.0):x(x),y(y){}
        friend ostream& operator<<(ostream&, const point&);
        friend point operator+(point&, point&);
        double getx(){return x;}
        double gety(){return y;}
        void setx(double v){x = v;}
        void sety(double v){y = v;}
    private:
        double x,y;
};

point operator+(point& p1, point& p2){
    return point(p1.x+p2.x, p1.y+p2.y);
}



ostream& operator<< (ostream& out, const point& p){
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

int main(){
    point a = {3.5,2.5}, b = {2.5,4.5}, c;
    c = a + b;
    cout << "a = " << a << "\tb = " << b << endl;
    cout << "sum = " << a + b << endl;
}
