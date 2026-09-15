#ifndef UNTITLED9_GRADUATESTUDENT_H
#define UNTITLED9_GRADUATESTUDENT_H

#include "Student.h"
#include "Course.h"
#include <iostream>
#include <string>
using namespace std;

class GraduateStudent : public Student {
private:
    int Number_of_courses;
    Course* pt[2];
    string supervisor_name;

public:
    GraduateStudent();
    GraduateStudent(string name, Date birth, Date e);
    GraduateStudent(string name, Date birth, Date e, Date g, string supervisor);

    int getNumber_of_courses();
    string getSupervisor_name();

    void setNumber_of_courses(int n);
    void setSupervisor_name(string s);

    bool isGraduateStudent();

    int add_course(Course* c);
    int remove_course(int courseNumber);
    bool isCourseInStudent(int courseNumber);

    void print();

    friend ostream& operator<<(ostream& out, GraduateStudent& s);

    ~GraduateStudent();
};

#endif
