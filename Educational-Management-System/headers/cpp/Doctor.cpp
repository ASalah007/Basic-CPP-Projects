#include "../Doctor.h"

Doctor::Doctor(string name, string email, string nationalID, string address, string phoneNumber, string password, string birthday)
    : User(name, email, nationalID, address, phoneNumber, password, birthday){
        this->type = "Doctor";
}
vector<Course*>& Doctor::getCourses(){
    return courses;
}

void Doctor::addCourse(Course* course){
    course->assignDoctor(this);
    courses.push_back(course);
}


const vector<Course*>& Doctor::readCourses()const{
    return courses;
}

Doctor::~Doctor(){
    
}
