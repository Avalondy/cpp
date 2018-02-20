#include <iostream>
#include <valarray>
using namespace std;

class point{
    public:
        point(double x=0.0, double y=0.0):x(x), y(y){}
        operator double();
        friend ostream& operator<<(ostream&, const point&);
    private:
        double x, y;
};

point::operator double(){
    return sqrt(x*x + y*y);
}

ostream& operator<<(ostream& out, const point& p){
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

int main(){
    point s = {3, 7};
    double d = s;
    cout << s << endl;
    cout << d << endl;
}
