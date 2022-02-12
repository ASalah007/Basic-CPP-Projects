#ifndef STUDENT_H
#define STUDENT_H
#include <vector>
#include "User.h"

#include "Course.h"
#include "Grade.h"
#include "Assignment.h"

using namespace std;

class Student : public User{
private: 
vector<const Course*> courses;
vector<Grade*> grades;
vector<Assignment> assignments;

public:
    Student(string name, string email, string nationalID, string address, string phoneNumber, string password, string birthday);
    ~Student();
    const vector<const Course*>& getCourses() const;    
    const vector<Grade*>& getGrades() const;
    void addCourse(const Course* course);
    Grade* getGrade(const Course* course);
    vector<Assignment>& getAssignments();
    vector<Assignment*> getAssignments(string courseCode) ;
    Assignment* addAssignment(Assignment ass) ;
    void addGrade(Grade* grade);
};

#endif