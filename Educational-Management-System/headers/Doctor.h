#ifndef DOCTOR_H
#define DOCTOR_H
#include <vector>

#include "User.h"
#include "Course.h"


class Doctor : public User{
private:
    vector<Course*> courses;

public:
    Doctor(string name, string email, string nationalID, string address, string phoneNumber, string password, string birthday);
    ~Doctor();
    vector<Course*>& getCourses();
    void addCourse(Course* course);
    const vector<Course*>& readCourses()const;
    void addTA(TA* ta);

};

#endif