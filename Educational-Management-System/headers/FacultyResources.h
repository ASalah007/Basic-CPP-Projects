#ifndef FACULTYRESOURCES_H
#define FACULTYRESOURCES_H
#include "Doctor.h"
#include "TA.h"
#include "Student.h"
#include "Course.h"

class FacultyResources{
private:    
    static vector<Course> courses;
    static vector<Course*>openCourses;
    static vector<Student> students;
    static vector<TA> TAs;
    static vector<Doctor> doctors;
    FacultyResources();
    static User* getUser(string email);
    static Course* getCourse(string courseCode);
public:
    static User* getUser(string email, User& currentUser);
    static User* getUser(string email, string password);
    
    static vector<Course*>& getOpenCourses();
    static vector<Course>& getCourses();
   
    static void addStudent(string name, string email, string nationalID, string address, string phoneNumber, string password, string birthday);
    static void registerStudent(string courseCode, Student* student);
    
    static void addTA(string name, string email, string nationalID, string address, string phoneNumber, string password, string birthday);
    static vector<TA>& getTAs();
    
    static void addDoctor(string name, string email, string nationalID, string address, string phoneNumber, string password, string birthday);
    static Course* addCourse(string courseCode);

    static void fillDummyData();
};
#endif