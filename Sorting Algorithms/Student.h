//
// Created by HP on 4/22/2024.
//

#ifndef CS214_ASSIGNMENT_1_STUDENT_H
#define CS214_ASSIGNMENT_1_STUDENT_H
#include <bits/stdc++.h>
using namespace std;

class Student {
private:
    string id;
    string name;
    double gpa;
public:
    Student();
    Student(string sname, string sid , double sgpa);
    bool operator< (Student& std);
    bool operator> (Student& std);
    bool operator<= (Student& std);
    bool operator>= (Student& std);
    friend ostream& operator<<(ostream& out, const Student& std);
    double get_gpa();
};


#endif //CS214_ASSIGNMENT_1_STUDENT_H
