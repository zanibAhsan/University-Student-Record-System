#include "Student.h"
#include "Person.h"
#include "Course.h"
#include "Date.h"
#include <iostream>
using namespace std;

int Student::nextStudentID = 1000;

Student::Student() : Person() {
    Student_ID = nextStudentID;
    nextStudentID++;
    enrollment_date = Date();
    graduation_date = Date(0, 0, 0);
}

Student::Student(string name, Date birth, Date e) : Person(name, birth) {
    Student_ID = nextStudentID;
    nextStudentID++;
    enrollment_date = e;
    graduation_date = Date(0, 0, 0);
}

Student::Student(string name, Date birth, Date e, Date g) : Person(name, birth) {
    Student_ID = nextStudentID;
    nextStudentID++;
    enrollment_date = e;
    graduation_date = g;
}

int Student::getStudent_ID() {
    return Student_ID;
}

Date Student::getEnrollment_date() {
    return enrollment_date;
}

Date Student::getGraduation_date() {
    return graduation_date;
}

void Student::setStudent_ID(int s) {
    Student_ID = s;
}

void Student::setEnrollment_date(Date d) {
    enrollment_date = d;
}

void Student::setGraduation_date(Date d) {
    graduation_date = d;
}

int Student::getid() {
    return Student_ID;
}

bool Student::isGraduateStudent() {
    return false;
}

void Student::print() {
    Person::print();

    cout << "Student ID: " << Student_ID << endl;

    cout << "Enrollment date: ";
    enrollment_date.print();
    cout << endl;

    cout << "Graduation date: ";
    graduation_date.print();
    cout << endl;
}

Student::~Student() {
    cout << "Student object deleted." << endl;
}
