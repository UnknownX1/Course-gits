#include <iostream>
#include <string>
using namespace std;

class Pack {
private:
    int year, month, day;
    int id, scid;
public:
    Pack();
    void set(int y, int m, int d, int id_);
    int get();
    void setVerify(int code);
    void print();
};
Pack::Pack() {
    year = month = day = 0;
    id = scid = 0;
}
void Pack::set(int y, int m, int d, int id_) {
    year = y;
    month = m;
    day = d;
    id = id_;
}
void Pack::setVerify(int code) {
    scid = id*10000 + code;
}
void Pack::print() {
    cout << "Pack ID=" << id << " Verify=" << scid << endl;
}
int Pack::get() {
    return year * 10000 + month * 100 + day;
}

int gen_Code(Pack ps[], int n, int x) {
    int minindex = 0x3f3f3f3f;
    int min = 0x3f3f3f3f;
    for (int i = 0; i < n; i++) {
        if (ps[i].get() < min) {
            minindex = i;
            min = ps[i].get();
        }
    }
    int year = min / 10000;
    int day = min % 100;
    int month = (min - year * 10000) / 100;
    int code = year * x * x + month * x + day;
    return code % 10000;
}

int main() {
    int t;
    cin >> t;
    Pack* p = new Pack[t];
    for (int i = 0; i < t; i++) {
        int y, m, d, id;
        cin >> y >> m >> d >> id;
        p[i].set(y, m, d, id);

    }
    int x;
    cin >> x;
    int code = gen_Code(p, t, x);

    for (int i = 0; i < t; i++) {
        p[i].setVerify(code);
        p[i].print();
    }
    delete[]p;
    return 0;
}