#include <iostream>
using namespace std;

class CFraction
{
private:
    int fz, fm;
public:
    CFraction(int fz_val, int fm_val);
    CFraction add(const CFraction& r);
    CFraction sub(const CFraction& r);
    CFraction mul(const CFraction& r);
    CFraction div(const CFraction& r);
    int getGCD();   // 求对象的分子和分母的最大公约数
    void print();
};

CFraction::CFraction(int fz_val, int fm_val) {
    fz = fz_val;
    fm = fm_val;
}

CFraction CFraction::add(const CFraction& r) {  //+
    int fenzi = fz * r.fm + r.fz * fm;
    int fenmu = fm * r.fm;
    CFraction temp(fenzi, fenmu);
    int gcd = temp.getGCD();
    CFraction newFra(fenzi / gcd, fenmu / gcd);
    return newFra;
}

CFraction CFraction::sub(const CFraction& r) {  //-
    int fenzi = fz * r.fm - r.fz * fm;
    int fenmu = fm * r.fm;
    CFraction temp(fenzi, fenmu);
    int gcd = temp.getGCD();
    CFraction newFra(fenzi / gcd, fenmu / gcd);
    return newFra;
}

CFraction CFraction::mul(const CFraction& r) {  //*
    int fenzi = fz * r.fz;
    int fenmu = fm * r.fm;
    CFraction temp(fenzi, fenmu);
    int gcd = temp.getGCD();
    CFraction newFra(fenzi / gcd, fenmu / gcd);
    return newFra;
}

CFraction CFraction::div(const CFraction& r) {  //*
    int fenzi = fz * r.fm;
    int fenmu = fm * r.fz;
    CFraction temp(fenzi, fenmu);
    int gcd = temp.getGCD();
    CFraction newFra(fenzi / gcd, fenmu / gcd);
    return newFra;
}

int CFraction::getGCD() {
    int a = max(fz, fm);
    int b = min(fz, fm);
    while (1) {
        int r = a % b;
            if (r == 0) {
                return b;
            }
            a = max(b, r);
            b = min(b, r);
    }
}

void CFraction::print() {
    int flag = 1;
    if (fz < 0) {
        fz *= -1;
        flag *= -1;
    }
    if (fm < 0) {
        fm *= -1;
        flag *= -1;
    }
    if (flag == -1) {
        cout << "-";
    }
    cout << fz << "/" << fm <<endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        char c;
        cin >> a >> c >> b;
        CFraction fra1(a, b);
        cin >> a >> c >> b;
        CFraction fra2(a, b);
        fra1.add(fra2).print();
        fra1.sub(fra2).print();
        fra1.mul(fra2).print();
        fra1.div(fra2).print();
        cout << endl;
    }
    return 0;
}