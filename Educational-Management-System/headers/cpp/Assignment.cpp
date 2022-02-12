#include "../Assignment.h"


Assignment::Assignment(string name, int maxMark,const Course* course){
    this->name = name;
    this->maxMark = maxMark;
    this->course = course;
}

string Assignment::getName() const{
    return name;
}
double Assignment::getMark() const{
    return mark;
}
int Assignment::getMaxMark() const{
    return maxMark;
}
string Assignment::getAnswers() const{
    return answers;
}
Status Assignment::getStatus() const{
    return status;
}
string Assignment::getStatusAsString() const{
   ;
    if(status == SUBMITTED)
        return "SUBMITTED";
    else if(status == GRADED)
        return "GRADED";
    else if(status == NOTSUBMITTED)      
        return "NOT-SUBMITTED";
    
    throw exception();
}
const Course* Assignment::getCourse() const{
    return course;
}


int Assignment::noOfSubmittedStudent(){
    return submittedStudentsCount;
}


void Assignment::setMark(double mark){
    if(mark > maxMark || mark < 0)
        throw exception();
    this->mark = mark;
}

void Assignment::setName(string name){
    this->name = name;
}

void Assignment::setStatus(Status status){
    this->status = status;
}

void Assignment::submit(string answers){
    this->answers = answers;
    this->status = SUBMITTED;
}

Assignment::~Assignment(){

}