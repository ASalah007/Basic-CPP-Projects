#include "../Course.h"

Course::Course(string name, string code){
    this->name = name;
    this->code = code;
    open = false;
}

string Course::getCode() const{
    return code;
}

string Course::getName() const{
    return name;
}

vector<pair<Student*, Grade>>& Course::getStudentsAndGrades(){
    return studentsAndGrades;
}

void Course::openCourse(){
    open = true;
}
void Course::addTA(TA* teachingAssistant){
    TAs.push_back(teachingAssistant);
}
void Course::assignDoctor(Doctor* doctor){
    this->doctor = doctor;
}

void Course::createAssignment(string name, int maxMark){
    assignments.push_back(Assignment(name, maxMark, this));
    Assignment ass = Assignment(name, maxMark, this);
    for(pair<Student*, Grade>& sg : studentsAndGrades){
        studentsAssignments.push_back(sg.first->addAssignment(ass));
    }
}
vector<Assignment*>& Course::getStudentAssignments(){
    return studentsAssignments;
}
bool Course::isOpen(){
    return open;
}
Grade* Course::registerStudent(Student* student){
    if(student == nullptr)
        throw exception();
    pair<Student*, Grade> p (student, Grade(student, this));
    studentsAndGrades.push_back(p);
    for(Assignment i : assignments){
        studentsAssignments.push_back(student->addAssignment(i));
    }
    pair<Student*, Grade>* ptr= &studentsAndGrades.back();
    return &(ptr->second);
}
int Course::noOfAssignments() const{
    return assignments.size();
}

int Course::noOfRegisteredStudents() const{
    return studentsAndGrades.size();
}

const vector<Assignment>& Course::getAssignments() const{
    return assignments;
}

const Grade* Course::getGrade(int id) const{
    for(auto& sg : studentsAndGrades){
        if(sg.first->getID() == id){
            return &sg.second;
        }
    }
    return nullptr;
}
Course::~Course(){
    
}