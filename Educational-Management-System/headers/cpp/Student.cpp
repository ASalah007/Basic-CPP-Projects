#include "../Student.h"


Student::Student(string name, string email, string nationalID, string address, string phoneNumber, string password, string birthday)
    : User(name, email, nationalID, address, phoneNumber, password, birthday){
        type="Student";
    
}
const vector<const Course*>& Student::getCourses() const{
    return courses;
}

const vector<Grade*>& Student::getGrades() const{
    return grades;
}

void Student::addCourse(const Course* course){
    courses.push_back(course);
}

Grade* Student::getGrade(const Course* course) {
    for(Grade* g : grades){
        if(g->getCourse()->getCode() == course->getCode()){
            return g;
        }
    }
    return nullptr;
}
vector<Assignment>& Student::getAssignments(){
   return assignments;
}
vector<Assignment *> Student::getAssignments(string courseCode) {
    vector<Assignment *> temp;
    for(Assignment ass: assignments){
        if(ass.getCourse()->getCode() == courseCode)
            temp.push_back(&ass);
    } 
    return temp;  
}
Assignment* Student::addAssignment(Assignment ass){
    
    assignments.push_back(ass);
    return &assignments.back();
}

void Student::addGrade(Grade* grade){
    grades.push_back(grade);
}

Student::~Student(){
    
}