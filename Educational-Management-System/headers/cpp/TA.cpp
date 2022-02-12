#include "../TA.h"

TA::TA(string name, string email, string nationalID, string address, string phoneNumber, string password, string birthday)
    : User(name, email, nationalID, address, phoneNumber, password, birthday){
    this->type = "TA";
}
TA::~TA(){

}

void TA::addCourse(Course* course){
    courses.push_back(course);
}

const vector<Course*>& TA::getCourses(){
    return courses;
}