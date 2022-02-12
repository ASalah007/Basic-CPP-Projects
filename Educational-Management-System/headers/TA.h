#ifndef TA_H
#define TA_H
#include "User.h"

#include <vector>
class Course;
using namespace std;

class TA : public User{

private:
    vector<Course*> courses;
    
public: 
    TA(string name, string email, string nationalID, string address, string phoneNumber, string password, string birthday);
    ~TA();

    void addCourse(Course* course);
    const vector<Course*>& getCourses();
};

#endif