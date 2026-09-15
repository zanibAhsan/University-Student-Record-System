#include <iostream>
#include <stdexcept>
#include <fstream>

#include "Date.h"
#include "Course.h"
#include "Person.h"
#include "Student.h"
#include "UndergraduateStudent.h"
#include "GraduateStudent.h"
#include "Professor.h"
#include "FullTimeProfessor.h"
#include "PartTimeProfessor.h"
#include "CourseRegistration.h"
#include "DataManager.h"

using namespace std;

int main() {
    cout << "University Information Management System - Assignment 5" << endl;

    DataManager* manager = new DataManager();

    cout << "\nCreating Students:" << endl;

    UndergraduateStudent* student1 = new UndergraduateStudent(
        "Ali_Ahmad",
        Date(9, 15, 2003),
        Date(8, 25, 2022),
        Date(5, 30, 2026)
    );

    GraduateStudent* student2 = new GraduateStudent(
        "Sara_Khan",
        Date(4, 20, 2001),
        Date(8, 25, 2024),
        Date(5, 30, 2026),
        "None"
    );

    UndergraduateStudent* student3 = new UndergraduateStudent(
        "Omar_Salem",
        Date(2, 10, 2004),
        Date(8, 25, 2025)
    );

    manager->enrolled_student(student1);
    manager->enrolled_student(student2);
    manager->enrolled_student(student3);

    cout << "Students in system: " << manager->getstudent_enrolled() << endl;

    cout << "\nCreating Professors:" << endl;

    FullTimeProfessor* professor1 = new FullTimeProfessor(
        "Dr_Nadia_Smith",
        Date(5, 12, 1975),
        Date(8, 15, 2010)
    );

    PartTimeProfessor* professor2 = new PartTimeProfessor(
        "Dr_Mark_Lee",
        Date(11, 3, 1980),
        Date(1, 10, 2022)
    );

    manager->addProfessor(professor1);
    manager->addProfessor(professor2);

    cout << "Professors in system: " << manager->getprofessor_count() << endl;

    cout << "\nAdding Courses:" << endl;

    CourseRegistration* course1 = new CourseRegistration(
        "COEN",
        244,
        "Programming_Methodology",
        professor1->getName(),
        30
    );

    CourseRegistration* course2 = new CourseRegistration(
        "MATH",
        204,
        "Calculus",
        professor2->getName(),
        25
    );

    CourseRegistration* course3 = new CourseRegistration(
        "SOEN",
        287,
        "Web_Programming",
        professor1->getName(),
        20
    );

    manager->addNewCourse(course1);
    manager->addNewCourse(course2);
    manager->addNewCourse(course3);

    cout << "\nAssigning Courses To Professors:" << endl;

    Professor* professorPointer;

    professorPointer = professor1;
    professorPointer->add_course(course1);
    professorPointer->add_course(course3);

    professorPointer = professor2;
    professorPointer->add_course(course2);

    cout << "\nRegistering Students To Courses:" << endl;

    manager->registerStudentToCourse(student1->getStudent_ID(), *course1);
    manager->registerStudentToCourse(student1->getStudent_ID(), *course2);

    manager->registerStudentToCourse(student2->getStudent_ID(), *course1);
    manager->registerStudentToCourse(student2->getStudent_ID(), *course3);

    manager->registerStudentToCourse(student3->getStudent_ID(), *course2);

    cout << "\nAdding Graduate Student Supervisor:" << endl;

    manager->addSupervisor(professor1->getEmployee_ID(), student2->getStudent_ID());

    cout << "\nShowing Polymorphism With Person Pointers:" << endl;

    Person* people[5];

    people[0] = student1;
    people[1] = student2;
    people[2] = student3;
    people[3] = professor1;
    people[4] = professor2;

    for (int i = 0; i < 5; i++) {
        cout << "\nObject ID from getid(): " << people[i]->getid() << endl;
        people[i]->print();
        cout << "------------------------------------------" << endl;
    }

    cout << "\nTesting Date operator overloading:" << endl;

    Date date1(5, 30, 2026);
    Date date2(5, 30, 2027);

    cout << "date1: " << date1 << endl;
    cout << "date2: " << date2 << endl;

    if (date2 > date1) {
        cout << "date2 is greater than date1." << endl;
    }

    cout << "\nTesting insertion operator for students:" << endl;

    cout << *student1 << endl;
    cout << *student2 << endl;

    cout << "\nCurrent Course Statuses:" << endl;

    course1->print();
    cout << "\n------------------------------------------" << endl;

    course2->print();
    cout << "\n------------------------------------------" << endl;

    course3->print();
    cout << "\n------------------------------------------" << endl;

    cout << "\nChecking Course Registration:" << endl;

    if (manager->studentEnrolledInCourse(student1->getStudent_ID(), *course1)) {
        cout << "Verification: Student "
             << student1->getStudent_ID()
             << " is registered in COEN 244."
             << endl;
    }

    cout << "\nDropping Course:" << endl;

    manager->dropCourse(student1->getStudent_ID(), *course2);

    cout << "\nChecking University Enrollment:" << endl;

    if (manager->studentEnrolledInUni(student2->getStudent_ID())) {
        cout << "Student "
             << student2->getStudent_ID()
             << " is confirmed enrolled at the university."
             << endl;
    }

    cout << "\nSaving Graduated Students To File:" << endl;

    string studentFile = "studentFile.txt";

    ofstream clearFile(studentFile.c_str());
    clearFile.close();

    try {
        manager->saveStudent(studentFile, student1);
        manager->saveStudent(studentFile, student2);

        cout << "Students were saved in the file." << endl;
    }
    catch (runtime_error& e) {
        cout << e.what() << endl;
        delete manager;
        return 0;
    }

    cout << "\nSearching For Students From File:" << endl;

    try {
        manager->searchStudent(studentFile, "undergraduate", student1->getStudent_ID());

        cout << "\n------------------------------------------" << endl;

        manager->searchStudent(studentFile, "graduate", student2->getStudent_ID());
    }
    catch (runtime_error& e) {
        cout << e.what() << endl;
    }

    cout << "\nTesting Exception Handling For Missing Student:" << endl;

    try {
        manager->searchStudent(studentFile, "graduate", 9999);
    }
    catch (runtime_error& e) {
        cout << e.what() << endl;
    }

    cout << "\nRemoving Student From University:" << endl;

    manager->removeStudent_fromUni(student3->getStudent_ID());

    cout << "Students in system: " << manager->getstudent_enrolled() << endl;

    cout << "\nRemoving Course From University:" << endl;

    manager->removeCourse(course3->getCourse_number());

    cout << "\nCLEANING UP SYSTEM & DELETING DATA MANAGER:" << endl;

    delete manager;

    cout << "\nPROGRAM FINISHED:" << endl;

    return 0;
}
