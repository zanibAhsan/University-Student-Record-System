#include "PartTimeProfessor.h"
#include "Professor.h"
#include "Course.h"
#include <iostream>
using namespace std;

PartTimeProfessor::PartTimeProfessor() : Professor() {
    Number_of_courses = 0;

    for (int i = 0; i < 3; i++) {
        pt[i] = nullptr;
    }
}

PartTimeProfessor::PartTimeProfessor(string name, Date birth, Date e) : Professor(name, birth, e) {
    Number_of_courses = 0;

    for (int i = 0; i < 3; i++) {
        pt[i] = nullptr;
    }
}

int PartTimeProfessor::getNumber_of_courses() {
    return Number_of_courses;
}

void PartTimeProfessor::setNumber_of_courses(int n) {
    Number_of_courses = n;
}

int PartTimeProfessor::add_course(Course* c) {
    if (Number_of_courses >= 3) {
        cout << "Part time professor cannot teach more than 3 courses." << endl;
        return 0;
    }

    for (int i = 0; i < 3; i++) {
        if (pt[i] == nullptr) {
            pt[i] = c;
            Number_of_courses++;
            cout << "Course added to part time professor." << endl;
            return 1;
        }
    }

    return 0;
}

void PartTimeProfessor::print() {
    cout << "Part Time Professor:" << endl;
    Professor::print();

    cout << "Number of courses teaching: " << Number_of_courses << endl;
    cout << "Courses teaching:" << endl;
    for (int i = 0; i < 3; i++) {
        if (pt[i] != nullptr) {
            pt[i]->print();
        }
    }
}

PartTimeProfessor::~PartTimeProfessor() {
    cout << "PartTimeProfessor object deleted." << endl;
}
