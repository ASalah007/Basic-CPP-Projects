#include "../Grade.h"

Grade::Grade(const Student* student, const Course* course){
    this->student = student;
    this->course = course;
    finalMark = 0;
    midtermMark = 0;      
    assignmentsMark = 0;  
    attendanceMark = 0;   
    quizesMark = 0;        
    projectMark = 0;      
}

const Student* Grade::getStudent() const{
    return student;
}
const Course* Grade::getCourse() const{
    return course;
}
double Grade::getFinalMark() const{
    return finalMark;
}
double Grade::getMidtermMark() const{
    return midtermMark;
}
double Grade::getAssignmentsMark() const{
    return assignmentsMark;
}
double Grade::getAttendanceMark() const{
    return attendanceMark;
}
double Grade::getQuizesMark() const{
    return quizesMark;
}
double Grade::getProjectMark() const{
    return projectMark;
}
double Grade::getTotalMark() const{
    return finalMark + midtermMark + assignmentsMark + attendanceMark + quizesMark + projectMark;
}
double Grade::getYearWork() const{
    return assignmentsMark + attendanceMark + quizesMark + projectMark;
}


void Grade::setFinalMark(double finalMark){
    this->finalMark = finalMark;
}
void Grade::setMidetermMark(double midtermMark){
    this->midtermMark = midtermMark;
}
void Grade::setAssignmentsMark(double assignmentsMark){
    this->assignmentsMark = assignmentsMark;
}
void Grade::setAttendanceMark(double attendanceMark){
    this->attendanceMark = attendanceMark;
}
void Grade::setQuizesMark(double quizesMark){
    this->quizesMark = quizesMark;
}
void Grade::setProjectMark(double projectMark){
    this->projectMark = projectMark;
}

Grade::~Grade(){
    
}