#ifndef GRADE_H
#define GRADE_H

class Student;
class Course;


class Grade{
private: 
    
    const Student* student;
    const Course* course;
    double finalMark;        // 40
    double midtermMark;      // 20
    double assignmentsMark;  // 10
    double attendanceMark;   // 10
    double quizesMark;       // 10 
    double projectMark;      // 10
public:
    static const int MIDTERMMAXMARK= 20;
    static const int FINALMAXMARK= 40;
    static const int ASSIGNMENTSMMAXMARK= 10;
    static const int ATTENDANCEMAXMARK= 10;
    static const int QUIZESMAXMARK= 10;
    static const int PROJECTMAXMARK= 10;

    Grade(const Student* student, const Course* course);
    ~Grade();
    const Student* getStudent() const;
    const Course* getCourse() const;
    double getFinalMark() const;
    double getMidtermMark() const;
    double getAssignmentsMark() const;
    double getAttendanceMark() const;
    double getQuizesMark() const;
    double getProjectMark() const;
    double getTotalMark() const;
    double getYearWork() const;
    
    void setFinalMark(double finalMark);
    void setMidetermMark(double midtermMark);
    void setAssignmentsMark(double assignmentsMark);
    void setAttendanceMark(double attendanceMark);
    void setQuizesMark(double quizesMark);
    void setProjectMark(double projectMark);
    
    
};

#endif