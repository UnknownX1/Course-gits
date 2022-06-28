#include <iostream>
#include <iomanip>
using namespace std;

class func {
private:
    float a;
    float b;
public:
    int root();
    double getX();
    func(float a_, float b_);
};
func::func(float a_, float b_) {
    a = a_;
    b = b_;
}
int func::root() {
    if (a == 0 && b != 0) {
        return 0;
    }
    return 1;
}
double func::getX() {
    return -b / a;
}
void solve(func& c) {
    if (c.root()) {
        cout << fixed << setprecision(2) << c.getX() << endl;
    }
    else {
        cout << "no root\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        float a, b;
        cin >> a >> b;
        func c(a, b);
        solve(c);
    }
    return 0;
}