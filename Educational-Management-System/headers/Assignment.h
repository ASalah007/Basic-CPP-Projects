#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <string>
class Course;
using namespace std;

enum Status{
        NOTSUBMITTED = 0,
        SUBMITTED = 1,
        GRADED = 2
};
class Assignment{
private:
    string name;
    int maxMark=0;
    double mark=0;
    string answers;
    Status status = NOTSUBMITTED;
    const Course* course;
    int submittedStudentsCount;

public: 
    Assignment(string name, int maxMark, const Course* course);
    ~Assignment();
    string getName() const;
    int getMaxMark() const;
    double getMark() const;
    string getAnswers() const;
    Status getStatus() const;
    string getStatusAsString() const;
    const Course* getCourse() const;


    void setMark(double mark);
    void setName(string name);
    void setStatus(Status status);
    void submit(string answers);
    int noOfSubmittedStudent();
};
#endif