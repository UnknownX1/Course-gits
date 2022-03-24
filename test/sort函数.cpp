/*
#include <iostream>
#include <algorithm>
using namespace std;
struct student
{
    int year = 0;
    int month = 0;
    int day = 0;
};
bool max(student a, student b)
{
    int shengri1 = a.year * 10000 + a.month * 100 + a.day;
    int shengri2 = b.year * 10000 + b.month * 100 + b.day;
    return shengri1 < shengri2;
}
int main02(void)
{
    int number = 0;
    cin >> number;
    student* stu = new student[number];
    for (int i = 0; i < number; i++)
    {
        cin >> stu[i].year;
        cin >> stu[i].month;
        cin >> stu[i].day;
    }
    sort(stu, stu + number, max);
    cout << stu[1].year << "-" << stu[1].month << "-" << stu[1].day;
}
*/