#include <iostream>
#include <string>
using namespace std;

class Apply;
class Room {
private:
    int id, full, state;
    static int free;
    static int use;
public:
    Room();
    void Set(int id_, int full_);
    friend int Allocate(Room rms[], int L, Apply& ay);
    static int getFree();
    static int getUse();
};
Room::Room() {
    id = full = state = 0;
    free++;
}
void Room::Set(int id_, int full_) {
    id = id_;
    full = full_;
}
//静态成员函数自行定义
int Room::getFree() {
    return free;
}
int Room::getUse() {
    return use;
}

class Apply {
private:
    int id;
    int num;
    int roomid;
public:
    Apply(int id, int num);
    void print();
    friend int Allocate(Room rms[], int L, Apply& ay);
};
Apply::Apply(int id_, int num_) {
    id = id_;
    num = num_;
    roomid = -1;
}
void Apply::print() {

    if (roomid != -1) {
        //Room 1001 is allocated for Apply 9901\n
        cout << "Room " << roomid << " is allocated for Apply " << id << endl;
    }
    else {
        //No room for Apply 9903\n
        cout << "No room for Apply " << id << endl;
    }

}


int Allocate(Room rms[], int L, Apply& ay) {
    int minindex = 0x3f3f3f3f, min = 0x3f3f3f3f;
    for (int i = 0; i < L; i++) {
        if (rms[i].state == 0 && ay.num <= rms[i].full) {
            int tmp = rms[i].full - ay.num;
            if (tmp < min) {
                minindex = i;
                min = tmp;
            }
        }
    }
    if (minindex != 0x3f3f3f3f) {
        ay.roomid = rms[minindex].id;
        rms[minindex].state = 1;
        Room::free--;
        Room::use++;
        return 1;
    }
    return -1;
}

int Room::free = 0;
int Room::use = 0;

int main() {
    int t;
    cin >> t;
    Room* r = new Room[t];
    for (int i = 0; i < t; i++) {
        int id, full;
        cin >> id >> full;
        r[i].Set(id, full);
    }
    int n;
    cin >> n;
    while (n--) {
        int id, num;
        cin >> id >> num;
        Apply app(id, num);
        Allocate(r, t, app);
        app.print();
    }
    cout << "The number of free room is " << Room::getFree() << endl;
    cout << "The number of busy room is " << Room::getUse() << endl;

    delete[]r;
    return 0;
}