#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Course {
private:
    int id;
    int point;
    int score;
public:
    int get(); //学分
    void set(int id_, int point_, int score_);
    double getPointU(); //本科绩点
    double getPointP(); //研究生绩点
    bool isP();
};
void Course::set(int id_, int point_, int score_) {
    id = id_;
    point = point_;
    score = score_;
}
int Course::get() {
    return point;
}
double Course::getPointU() {
    if (score < 60) {
        return 0;
    }
    else {
        return score / 10.0 - 5;
    }
}
bool Course::isP() {
    if (id / 1000 == 1) {
        return false;
    }
    return true;
}
double Course::getPointP() {
    if (!isP()) {
        return getPointU();
    }
    else {
        if (score < 70) {
            return 0;
        }
        else if (score < 80) {
            return 1.0;
        }
        else if (score < 90) {
            return 2.0;
        }
        else {
            return 3.0;
        }
    }
}

class Student {
private:
    string stuid, name;
    char type;
    double averagepoint; //平均绩点
    int done; //已修课程数目
    Course* cp; //课程类指针
    int score; //已修研究生学分
public:
    Student(string stuid, string name);
    void print();
    ~Student();
    void setCourse(int n);
    Student(const Student& s);
};


Student::Student(string stuid_, string name_) {
    stuid = stuid_;
    name = name_;
    type = 'U';
    averagepoint = done = score = 0;
}
void Student::print() {
    if (type == 'P') {
        //本硕连读生 P2000151001 张三 平均绩点=2.4 已修研究生学分=6\n
        cout << "本硕连读生 " << stuid << " " << name << " 平均绩点=" << averagepoint << " 已修研究生学分=" << score << endl;
    }
    else {
        cout << "本科生 " << stuid << " " << name << " 平均绩点=" << averagepoint << endl;
    }
}
Student::~Student() {
    delete[]cp;
}
void Student::setCourse(int n) {
    done = n;
    cp = new Course[n];

    for (int i = 0; i < n; i++) {
        int id, point, score;
        cin >> id >> point >> score;
        cp[i].set(id, point, score);
    }

    double total1 = 0; //(每门及格课程学分×绩点)的总和
    double total2 = 0;//及格课程的学分总数
    for (int i = 0; i < done; i++) {
        double  tmp = cp[i].getPointU(); //绩点
        if (tmp != 0) {
            total1 += cp[i].get() * tmp;
            total2 += cp[i].get();
        }
    }
    averagepoint = total1 / total2;
}
Student::Student(const Student& s) {
    stuid = "P2000" + s.stuid;
    type = 'P';
    done = s.done;
    cp = new Course[done];
    name = s.name;
    score = 0;
    for (int i = 0; i < done; i++) {
        cp[i] = s.cp[i];
    }
    double total1 = 0; //(每门及格课程学分×绩点)的总和
    double total2 = 0;//及格课程的学分总数
    for (int i = 0; i < done; i++) {
        double  tmp = cp[i].getPointP(); //绩点
        if (tmp != 0) {
            total1 += cp[i].get() * tmp;
            total2 += cp[i].get();
            if (cp[i].isP()) {
                score += cp[i].get();
            }
        }
    }
    averagepoint = total1 / total2;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string stuid, name;
        int courses;
        cin >> stuid >> name >> courses;
        Student stu(stuid, name);

        stu.setCourse(courses);
        char op;
        cin >> op;
        if (op == 'U') {
            stu.print();
        }
        else {
            Student stu2(stu);
            stu2.print();
        }
    }
    return 0;
}