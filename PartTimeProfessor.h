#ifndef UNTITLED9_PARTTIMEPROFESSOR_H
#define UNTITLED9_PARTTIMEPROFESSOR_H

#include "Professor.h"
#include "Course.h"
#include <iostream>
#include <string>
using namespace std;

class PartTimeProfessor : public Professor {
private:
    int Number_of_courses;
    Course* pt[3];

public:
    PartTimeProfessor();
    PartTimeProfessor(string name, Date birth, Date e);

    int getNumber_of_courses();
    void setNumber_of_courses(int n);

    int add_course(Course* c);

    void print();

    ~PartTimeProfessor();
};

#endif
