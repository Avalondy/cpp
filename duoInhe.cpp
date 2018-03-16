#include <iostream>
#include <cmath>
using namespace std;

template <class T>
class duo{
    public:
        duo():first(0.0), second(0.0){}
        void set_first(T d){first = d;}
        void set_second(T d){second = d;}
        T get_first(){return first;}
        T get_second(){return second;}
    protected:
        T first, second;
};

template <class T>
class point:public duo<T>{
    public:
        using duo<T>::first;
        using duo<T>::second;
        T length(){return sqrt(first*first + second* second);}
};

int main(){
    point<double> q;
    q.set_first(3.0); q.set_second(4.0);
    cout << q.get_first() << ", " << q.get_second() << endl;
    cout << q.length() << endl;
    return 0;
}
