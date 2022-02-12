#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
#include <utility>

class Doctor;
class TA;
#include "Student.h"
#include "Assignment.h"
#include "Grade.h"



using namespace std;

class Course{
private: 
    string name;
    string code;
    Doctor* doctor;
    vector<TA *> TAs;
    vector<pair<Student*, Grade>> studentsAndGrades;
    vector<Assignment> assignments;
    vector<Assignment*> studentsAssignments;
    bool open;
public:

    Course(string name, string code);
    ~Course();
    string getName() const;
    string getCode() const;
    int noOfAssignments() const;
    int noOfRegisteredStudents() const;
    const vector<Assignment>& getAssignments() const;
    vector<Assignment*>& getStudentAssignments();
    vector<pair<Student*, Grade>>& getStudentsAndGrades();
    bool isOpen();

    void openCourse();
    void addTA(TA* teachingAssistant);
    void assignDoctor(Doctor* doctor);
    void createAssignment(string name, int maxMark);
    
    Grade* registerStudent(Student* student);
    const Grade* getGrade(int id) const;

};

#endif