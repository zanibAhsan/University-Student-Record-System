#ifndef UNTITLED9_STUDENT_H
#define UNTITLED9_STUDENT_H

#include "Person.h"
#include "Date.h"
#include "Course.h"
#include <iostream>
#include <string>
using namespace std;

class Student : public Person {
private:
    int Student_ID;
    Date enrollment_date;
    Date graduation_date;
    static int nextStudentID;

public:
    Student();
    Student(string name, Date birth, Date e);
    Student(string name, Date birth, Date e, Date g);

    int getStudent_ID();
    Date getEnrollment_date();
    Date getGraduation_date();

    void setStudent_ID(int s);
    void setEnrollment_date(Date d);
    void setGraduation_date(Date d);

    int getid();
    virtual bool isGraduateStudent();

    virtual int add_course(Course* c) = 0;
    virtual int remove_course(int courseNumber) = 0;
    virtual bool isCourseInStudent(int courseNumber) = 0;

    virtual void print();

    virtual ~Student();
};

#endif
