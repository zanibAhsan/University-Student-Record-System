#ifndef UNTITLED9_DATAMANAGER_H
#define UNTITLED9_DATAMANAGER_H

#include <iostream>
#include <string>
#include "Student.h"
#include "GraduateStudent.h"
#include "UndergraduateStudent.h"
#include "Professor.h"
#include "FullTimeProfessor.h"
#include "CourseRegistration.h"
#include "Course.h"
using namespace std;

class DataManager {
private:
    int student_enrolled;
    int professor_count;
    Student* students[5000];
    Professor* professors[100];
    CourseRegistration* courseregistrations[200];

public:
    DataManager();

    int getstudent_enrolled();
    int getprofessor_count();

    void setStudent_enrolled(int s);
    void setProfessor_count(int p);

    void enrolled_student(Student* s);
    void addProfessor(Professor* p);
    void removeStudent_fromUni(int Student_ID);

    void addNewCourse(CourseRegistration* c);
    void removeCourse(int Course_number);

    void registerStudentToCourse(int Student_ID, Course& course);
    void dropCourse(int Student_ID, Course& course);

    bool studentEnrolledInCourse(int Student_ID, Course& course);
    bool studentEnrolledInUni(int Student_ID);

    void addSupervisor(int professorID, int studentID);

    bool saveStudent(string studentFile, Student* student);
    void searchStudent(string studentFile, string className, int student_id);

    ~DataManager();
};

#endif
