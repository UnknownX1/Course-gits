#include <iostream>
#include <iomanip>
using namespace std;

class Equation {
private:
    float a;
    float b;
public:

    double getX();
    Equation(float a_, float b_);
    ~Equation();
};
Equation::Equation(float a_, float b_) {
    a = a_;
    b = b_;
    cout << "Equation " << a << "x+" << b << "=0 ";
    cout << "constructed\n";
}
Equation::~Equation() {
    cout << "Equation " << a << "x+" << b << "=0 ";
    cout << "destructed\n";
}
double Equation::getX() {
    return -b / a;
}

int compareX(Equation& p1, Equation& p2) {
    return (p1.getX() > p2.getX()) ? 1 : -1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        float a, b;
        cin >> a >> b;
        Equation equ1(a, b);
        cin >> a >> b;
        Equation equ2(a, b);
        if (compareX(equ1, equ2)<0) {
            cout << "The first equation is smaller\n";
        }
        else {
            cout << "The second equation is smaller\n";
        }
    }
    return 0;
}