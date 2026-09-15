#include "GraduateStudent.h"
#include "Student.h"
#include "Course.h"
#include <iostream>
using namespace std;

GraduateStudent::GraduateStudent() : Student() {
    Number_of_courses = 0;
    supervisor_name = "";

    for (int i = 0; i < 2; i++) {
        pt[i] = nullptr;
    }
}

GraduateStudent::GraduateStudent(string name, Date birth, Date e) : Student(name, birth, e) {
    Number_of_courses = 0;
    supervisor_name = "";

    for (int i = 0; i < 2; i++) {
        pt[i] = nullptr;
    }
}

GraduateStudent::GraduateStudent(string name, Date birth, Date e, Date g, string supervisor) : Student(name, birth, e, g) {
    Number_of_courses = 0;
    supervisor_name = supervisor;

    for (int i = 0; i < 2; i++) {
        pt[i] = nullptr;
    }
}

int GraduateStudent::getNumber_of_courses() {
    return Number_of_courses;
}

string GraduateStudent::getSupervisor_name() {
    return supervisor_name;
}

void GraduateStudent::setNumber_of_courses(int n) {
    Number_of_courses = n;
}

void GraduateStudent::setSupervisor_name(string s) {
    supervisor_name = s;
}

bool GraduateStudent::isGraduateStudent() {
    return true;
}

int GraduateStudent::add_course(Course* c) {
    if (Number_of_courses >= 2) {
        cout << "Graduate student cannot take more than 2 courses." << endl;
        return 0;
    }

    for (int i = 0; i < 2; i++) {
        if (pt[i] != nullptr && pt[i]->getCourse_number() == c->getCourse_number()) {
            cout << "Student is already registered in this course." << endl;
            return 0;
        }
    }

    for (int i = 0; i < 2; i++) {
        if (pt[i] == nullptr) {
            pt[i] = c;
            Number_of_courses++;
            cout << "Course added to graduate student." << endl;
            return 1;
        }
    }

    return 0;
}

int GraduateStudent::remove_course(int courseNumber) {
    for (int i = 0; i < 2; i++) {
        if (pt[i] != nullptr && pt[i]->getCourse_number() == courseNumber) {
            pt[i] = nullptr;
            Number_of_courses--;
            cout << "Course removed from graduate student." << endl;
            return 1;
        }
    }

    cout << "Course was not found in graduate student courses." << endl;
    return 0;
}

bool GraduateStudent::isCourseInStudent(int courseNumber) {
    for (int i = 0; i < 2; i++) {
        if (pt[i] != nullptr && pt[i]->getCourse_number() == courseNumber) {
            return true;
        }
    }

    return false;
}

void GraduateStudent::print() {
    cout << "Graduate Student:" << endl;
    Student::print();

    cout << "Supervisor name: " << supervisor_name << endl;
    cout << "Number of courses: " << Number_of_courses << endl;

    cout << "Registered courses:" << endl;
    for (int i = 0; i < 2; i++) {
        if (pt[i] != nullptr) {
            pt[i]->print();
        }
    }
}

ostream& operator<<(ostream& out, GraduateStudent& s) {
    out << "Graduate Student:" << endl;
    out << "Name: " << s.getName() << endl;
    out << "Date of birth: " << s.getDate_of_birth() << endl;
    out << "Student ID: " << s.getStudent_ID() << endl;
    out << "Enrollment date: " << s.getEnrollment_date() << endl;
    out << "Graduation date: " << s.getGraduation_date() << endl;
    out << "Supervisor name: " << s.supervisor_name << endl;
    out << "Number of courses: " << s.Number_of_courses << endl;
    out << "Registered courses:" << endl;

    for (int i = 0; i < 2; i++) {
        if (s.pt[i] != nullptr) {
            out << s.pt[i]->getDepartment() << " "
                << s.pt[i]->getCourse_number() << " "
                << s.pt[i]->getCourse_name() << endl;
        }
    }

    return out;
}

GraduateStudent::~GraduateStudent() {
    cout << "GraduateStudent object deleted." << endl;
}
