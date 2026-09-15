#include "DataManager.h"
#include "Student.h"
#include "GraduateStudent.h"
#include "Professor.h"
#include "FullTimeProfessor.h"
#include "CourseRegistration.h"
#include "Course.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

DataManager::DataManager() {
    student_enrolled = 0;
    professor_count = 0;

    for (int i = 0; i < 5000; i++) {
        students[i] = nullptr;
    }

    for (int j = 0; j < 100; j++) {
        professors[j] = nullptr;
    }

    for (int k = 0; k < 200; k++) {
        courseregistrations[k] = nullptr;
    }
}

int DataManager::getstudent_enrolled() {
    return student_enrolled;
}

int DataManager::getprofessor_count() {
    return professor_count;
}

void DataManager::setStudent_enrolled(int s) {
    student_enrolled = s;
}

void DataManager::setProfessor_count(int p) {
    professor_count = p;
}

void DataManager::enrolled_student(Student* s) {
    for (int i = 0; i < 5000; i++) {
        if (students[i] != nullptr && students[i]->getStudent_ID() == s->getStudent_ID()) {
            cout << "Student with this ID is already enrolled." << endl;
            return;
        }
    }

    for (int i = 0; i < 5000; i++) {
        if (students[i] == nullptr) {
            students[i] = s;
            student_enrolled++;
            cout << "Student enrolled successfully." << endl;
            return;
        }
    }

    cout << "Student cannot be enrolled." << endl;
}

void DataManager::addProfessor(Professor* p) {
    for (int i = 0; i < 100; i++) {
        if (professors[i] == nullptr) {
            professors[i] = p;
            professor_count++;
            cout << "Professor added successfully." << endl;
            return;
        }
    }

    cout << "Professor cannot be added." << endl;
}

void DataManager::removeStudent_fromUni(int Student_ID) {
    for (int i = 0; i < 5000; i++) {
        if (students[i] != nullptr) {
            if (students[i]->getStudent_ID() == Student_ID) {
                for (int j = 0; j < 200; j++) {
                    if (courseregistrations[j] != nullptr) {
                        if (courseregistrations[j]->isStudentInCourse(Student_ID)) {
                            courseregistrations[j]->removeStudent(Student_ID);
                        }
                    }
                }

                delete students[i];
                students[i] = nullptr;
                student_enrolled--;

                cout << "Student removed from university." << endl;
                return;
            }
        }
    }

    cout << "Student not found." << endl;
}

void DataManager::addNewCourse(CourseRegistration* c) {
    for (int j = 0; j < 200; j++) {
        if (courseregistrations[j] != nullptr) {
            if (courseregistrations[j]->getCourse_number() == c->getCourse_number()) {
                cout << "Course already exists." << endl;
                return;
            }
        }
    }

    for (int j = 0; j < 200; j++) {
        if (courseregistrations[j] == nullptr) {
            courseregistrations[j] = c;
            cout << "Course added successfully." << endl;
            return;
        }
    }

    cout << "Course cannot be added." << endl;
}

void DataManager::removeCourse(int Course_number) {
    for (int i = 0; i < 200; i++) {
        if (courseregistrations[i] != nullptr) {
            if (courseregistrations[i]->getCourse_number() == Course_number) {
                for (int j = 0; j < 5000; j++) {
                    if (students[j] != nullptr) {
                        if (students[j]->isCourseInStudent(Course_number)) {
                            students[j]->remove_course(Course_number);
                        }
                    }
                }

                delete courseregistrations[i];
                courseregistrations[i] = nullptr;

                cout << "Course removed from university." << endl;
                return;
            }
        }
    }

    cout << "Course was not removed." << endl;
}

void DataManager::registerStudentToCourse(int Student_ID, Course& course) {
    Student* foundStudent = nullptr;
    CourseRegistration* foundCourse = nullptr;

    for (int i = 0; i < 5000; i++) {
        if (students[i] != nullptr && students[i]->getStudent_ID() == Student_ID) {
            foundStudent = students[i];
            break;
        }
    }

    if (foundStudent == nullptr) {
        cout << "Student was not found at the university." << endl;
        return;
    }

    for (int j = 0; j < 200; j++) {
        if (courseregistrations[j] != nullptr) {
            if (courseregistrations[j]->getCourse_number() == course.getCourse_number()) {
                foundCourse = courseregistrations[j];
                break;
            }
        }
    }

    if (foundCourse == nullptr) {
        cout << "Course was not found." << endl;
        return;
    }

    if (foundStudent->isCourseInStudent(foundCourse->getCourse_number())) {
        cout << "Student is already registered in this course." << endl;
        return;
    }

    int result1 = foundCourse->registerStudent(Student_ID);

    if (result1 == 1) {
        int result2 = foundStudent->add_course(foundCourse);

        if (result2 == 1) {
            cout << "Student has been registered to the course." << endl;
        }
        else {
            foundCourse->removeStudent(Student_ID);
        }
    }
}

void DataManager::dropCourse(int Student_ID, Course& course) {
    Student* foundStudent = nullptr;
    CourseRegistration* foundCourse = nullptr;

    for (int i = 0; i < 5000; i++) {
        if (students[i] != nullptr && students[i]->getStudent_ID() == Student_ID) {
            foundStudent = students[i];
            break;
        }
    }

    if (foundStudent == nullptr) {
        cout << "Student was not found at the university." << endl;
        return;
    }

    for (int j = 0; j < 200; j++) {
        if (courseregistrations[j] != nullptr) {
            if (courseregistrations[j]->getCourse_number() == course.getCourse_number()) {
                foundCourse = courseregistrations[j];
                break;
            }
        }
    }

    if (foundCourse == nullptr) {
        cout << "Course was not found." << endl;
        return;
    }

    foundCourse->removeStudent(Student_ID);
    foundStudent->remove_course(course.getCourse_number());

    cout << "The course has been dropped." << endl;
}

bool DataManager::studentEnrolledInCourse(int Student_ID, Course& course) {
    for (int i = 0; i < 200; i++) {
        if (courseregistrations[i] != nullptr) {
            if (courseregistrations[i]->getCourse_number() == course.getCourse_number()) {
                return courseregistrations[i]->isStudentInCourse(Student_ID);
            }
        }
    }

    return false;
}

bool DataManager::studentEnrolledInUni(int Student_ID) {
    for (int i = 0; i < 5000; i++) {
        if (students[i] != nullptr) {
            if (students[i]->getStudent_ID() == Student_ID) {
                return true;
            }
        }
    }

    return false;
}

void DataManager::addSupervisor(int professorID, int studentID) {
    Professor* foundProfessor = nullptr;
    GraduateStudent* foundStudent = nullptr;

    for (int i = 0; i < 100; i++) {
        if (professors[i] != nullptr && professors[i]->getid() == professorID) {
            foundProfessor = professors[i];
            break;
        }
    }

    if (foundProfessor == nullptr) {
        cout << "Professor was not found." << endl;
        return;
    }

    for (int j = 0; j < 5000; j++) {
        if (students[j] != nullptr && students[j]->getid() == studentID) {
            if (students[j]->isGraduateStudent()) {
                foundStudent = (GraduateStudent*)students[j];
            }
            break;
        }
    }

    if (foundStudent == nullptr) {
        cout << "Graduate student was not found." << endl;
        return;
    }

    int result = foundProfessor->addGraduateStudent(foundStudent);

    if (result == 1) {
        foundStudent->setSupervisor_name(foundProfessor->getName());
    }
}

bool DataManager::saveStudent(string studentFile, Student* student) {
    ofstream outFile;
    Date graduation = student->getGraduation_date();

    if (graduation.getmonth() == 0 && graduation.getday() == 0 && graduation.getyear() == 0) {
        cout << "Student has not graduated and was not saved." << endl;
        return false;
    }

    outFile.open(studentFile.c_str(), ios::app);

    if (!outFile) {
        throw runtime_error("File cannot be opened");
    }

    Date birth = student->getDate_of_birth();
    Date enrollment = student->getEnrollment_date();

    if (student->isGraduateStudent()) {
        GraduateStudent* graduateStudent = (GraduateStudent*)student;

        outFile << "graduate" << " "
                << graduateStudent->getStudent_ID() << " "
                << graduateStudent->getName() << " "
                << birth.getmonth() << " " << birth.getday() << " " << birth.getyear() << " "
                << enrollment.getmonth() << " " << enrollment.getday() << " " << enrollment.getyear() << " "
                << graduation.getmonth() << " " << graduation.getday() << " " << graduation.getyear() << " "
                << graduateStudent->getSupervisor_name() << endl;
    }
    else {
        UndergraduateStudent* undergraduateStudent = (UndergraduateStudent*)student;

        outFile << "undergraduate" << " "
                << undergraduateStudent->getStudent_ID() << " "
                << undergraduateStudent->getName() << " "
                << birth.getmonth() << " " << birth.getday() << " " << birth.getyear() << " "
                << enrollment.getmonth() << " " << enrollment.getday() << " " << enrollment.getyear() << " "
                << graduation.getmonth() << " " << graduation.getday() << " " << graduation.getyear() << endl;
    }

    outFile.close();
    return true;
}

void DataManager::searchStudent(string studentFile, string className, int student_id) {
    ifstream inFile;
    string fileClassName;
    int id;
    string name;
    int birthMonth, birthDay, birthYear;
    int enrollmentMonth, enrollmentDay, enrollmentYear;
    int graduationMonth, graduationDay, graduationYear;
    string supervisorName;

    inFile.open(studentFile.c_str());

    if (!inFile) {
        throw runtime_error("File cannot be opened");
    }

    while (inFile >> fileClassName) {
        inFile >> id >> name;
        inFile >> birthMonth >> birthDay >> birthYear;
        inFile >> enrollmentMonth >> enrollmentDay >> enrollmentYear;
        inFile >> graduationMonth >> graduationDay >> graduationYear;

        if (fileClassName == "graduate") {
            inFile >> supervisorName;
        }
        else {
            supervisorName = "";
        }

        if (fileClassName == className && id == student_id) {
            Date birth(birthMonth, birthDay, birthYear);
            Date enrollment(enrollmentMonth, enrollmentDay, enrollmentYear);
            Date graduation(graduationMonth, graduationDay, graduationYear);

            if (fileClassName == "undergraduate") {
                UndergraduateStudent* foundStudent = new UndergraduateStudent(name, birth, enrollment, graduation);
                foundStudent->setStudent_ID(id);

                cout << "Student found:" << endl;
                cout << *foundStudent << endl;

                Date expectedGraduation(enrollmentMonth, enrollmentDay, enrollmentYear + 4);
                cout << "Expected graduation date: " << expectedGraduation << endl;

                if (graduation > expectedGraduation) {
                    cout << "This undergraduate student did not graduate on time." << endl;
                }
                else {
                    cout << "This undergraduate student graduated on time." << endl;
                }

                delete foundStudent;
            }
            else if (fileClassName == "graduate") {
                GraduateStudent* foundStudent = new GraduateStudent(name, birth, enrollment, graduation, supervisorName);
                foundStudent->setStudent_ID(id);

                cout << "Student found:" << endl;
                cout << *foundStudent << endl;

                Date expectedGraduation(enrollmentMonth, enrollmentDay, enrollmentYear + 2);
                cout << "Expected graduation date: " << expectedGraduation << endl;

                if (graduation > expectedGraduation) {
                    cout << "This graduate student did not graduate on time." << endl;
                }
                else {
                    cout << "This graduate student graduated on time." << endl;
                }

                delete foundStudent;
            }

            inFile.close();
            return;
        }
    }

    inFile.close();
    throw runtime_error("Student couldnot be found");
}

DataManager::~DataManager() {
    for (int i = 0; i < 5000; i++) {
        if (students[i] != nullptr) {
            delete students[i];
            students[i] = nullptr;
        }
    }

    for (int j = 0; j < 100; j++) {
        if (professors[j] != nullptr) {
            delete professors[j];
            professors[j] = nullptr;
        }
    }

    for (int k = 0; k < 200; k++) {
        if (courseregistrations[k] != nullptr) {
            delete courseregistrations[k];
            courseregistrations[k] = nullptr;
        }
    }

    cout << "DataManager object deleted." << endl;
}
