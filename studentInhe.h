#include <iostream>
#include <cstring>
using namespace std;

class student{
    public:
        enum year{fresh, soph, junior, senior, grad};
        student(char const* nm, int id, double g, year x);
        void print() const;
        friend ostream& operator<<(ostream&, const year&);
    protected:
        int student_id;
        double gpa;
        year y;
        char name[30];
};

class grad_student: public student{
    public:
        enum support{ta, ra, fellowship, other};
        grad_student(char const* nm, int id, double g, year x, support t,
                char const* d, char const* th);
        void print() const;
        friend ostream& operator<<(ostream&, const support&);
    protected:
        support s;
        char dept[10];
        char thesis[80];
};

student::student(char const* nm, int id, double g, year x): student_id(id), gpa(g), y(x){
    strcpy(name, nm);
}

grad_student::grad_student(char const* nm, int id, double g, year x, support t,
        char const* d, char const* th):
    student(nm, id, g, x), s(t){strcpy(dept, d); strcpy(thesis, th);}

void student::print() const{
    cout << name << ", " << student_id << ", " << y << ", " << gpa << endl;
}

void grad_student::print() const{
    student::print();
    cout << dept << ", " << s << endl << thesis << endl;
}

ostream& operator<<(ostream& out, const student::year& y){
    switch (y){
        case student::fresh:     out << "fresh"; break;
        case student::soph:      out << "sophomore"; break;
        case student::junior:    out << "junior"; break;
        case student::senior:    out << "senior"; break;
        case student::grad:      out << "graduate"; break;
    }
    return out;
}

ostream& operator<<(ostream& out, const grad_student::support& s){
    switch (s){
        case grad_student::ta:     out << "ta"; break;
        case grad_student::ra:     out << "ra"; break;
        case grad_student::fellowship:   out << "fellowship"; break;
        case grad_student::other:      out << "other"; break;
    }
    return out;
}
