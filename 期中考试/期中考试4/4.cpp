#include <iostream>
#include <string>
using namespace std;

class CDate {
private:
    int year, month, day;
public:
    int get();
    CDate(int y, int m, int d);
};
CDate::CDate(int y, int m, int d) {
    year = y;
    month = m;
    day = d;
}
int CDate::get() {
    return year * 10000 + month * 100 + day;
}

class Meeting {
private:
    CDate date;
    int id;
    int start, end;
public:
    Meeting(int y, int m, int d, int id_, int start_, int end_);
    int Judge(Meeting& m);
    int get();
};
Meeting::Meeting(int id_, int y, int m, int d, int start_, int end_) :date(y, m, d) {
    id = id_;
    start = start_;
    end = end_;
}
int Meeting::Judge(Meeting& m) {
    if (date.get() != m.date.get()) {
        return 0;
    }
    if (start<m.start && end > m.start || m.start<start && m.end > start || m.start == start && m.end == end) {
        return 1;
    }
    return 0;
}
int Meeting::get() {
    return id;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int id, y, m, d, start, end;
        cin >> id >> y >> m >> d >> start >> end;
        Meeting m1(id, y, m, d, start, end);
        cin >> id >> y >> m >> d >> start >> end;
        Meeting m2(id, y, m, d, start, end);
        if (m1.Judge(m2)) {
            cout << "Meeting " << m1.get() << " and " << m2.get() << " are conflicted\n";
        }
        else {
            cout << "Meeting " << m1.get() << " and " << m2.get() << " are not conflicted\n";
        }
    }
    return 0;
}