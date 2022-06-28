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
    int get(); //ѧ��
    void set(int id_, int point_, int score_);
    double getPointU(); //���Ƽ���
    double getPointP(); //�о�������
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
    double averagepoint; //ƽ������
    int done; //���޿γ���Ŀ
    Course* cp; //�γ���ָ��
    int score; //�����о���ѧ��
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
        //��˶������ P2000151001 ���� ƽ������=2.4 �����о���ѧ��=6\n
        cout << "��˶������ " << stuid << " " << name << " ƽ������=" << averagepoint << " �����о���ѧ��=" << score << endl;
    }
    else {
        cout << "������ " << stuid << " " << name << " ƽ������=" << averagepoint << endl;
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

    double total1 = 0; //(ÿ�ż���γ�ѧ�֡�����)���ܺ�
    double total2 = 0;//����γ̵�ѧ������
    for (int i = 0; i < done; i++) {
        double  tmp = cp[i].getPointU(); //����
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
    double total1 = 0; //(ÿ�ż���γ�ѧ�֡�����)���ܺ�
    double total2 = 0;//����γ̵�ѧ������
    for (int i = 0; i < done; i++) {
        double  tmp = cp[i].getPointP(); //����
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