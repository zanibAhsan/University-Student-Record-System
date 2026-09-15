#include "Professor.h"
#include "Person.h"
#include "Date.h"
#include "Course.h"
#include <iostream>
using namespace std;

int Professor::nextEmployeeID = 5000;

Professor::Professor() : Person() {
    Employee_ID = nextEmployeeID;
    nextEmployeeID++;
    employment_date = Date();
}

Professor::Professor(string name, Date birth, Date e) : Person(name, birth) {
    Employee_ID = nextEmployeeID;
    nextEmployeeID++;
    employment_date = e;
}

int Professor::getEmployee_ID() {
    return Employee_ID;
}

Date Professor::getEmployment_date() {
    return employment_date;
}

void Professor::setEmployee_ID(int e) {
    Employee_ID = e;
}

void Professor::setEmployment_date(Date d) {
    employment_date = d;
}

int Professor::getid() {
    return Employee_ID;
}

int Professor::addGraduateStudent(GraduateStudent*) {
    cout << "Only full time professor can supervise graduate students." << endl;
    return 0;
}

void Professor::print() {
    Person::print();

    cout << "Employee ID: " << Employee_ID << endl;

    cout << "Employment date: ";
    employment_date.print();
    cout << endl;
}

Professor::~Professor() {
    cout << "Professor object deleted." << endl;
}
