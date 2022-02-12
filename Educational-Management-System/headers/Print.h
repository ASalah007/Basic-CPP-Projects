#ifndef PRINT_H
#define PRINT_H
#include <iostream>
#include <sstream>
#include <algorithm>

class Grade;
#include "Student.h"
#include "Doctor.h"
#include "Course.h"
#include "Assignment.h"

using namespace std;
class Print{

public:
    static void startMenu();
    static void signInMenu();
    static void signUpMenu();
    static void doctorStartMenu(string name);
    static void doctorCourseMenu(const Course* course); 
    static void doctorOpenCourseMenu();
    static void doctorInformationMenu(const Doctor* doctor);
    
    static void TAStartMenu(string name);
    static void TACourseMenu(const Course* course);
    static void studentStartMenu(string name);
    static void studentCourseMenu(const Course* course);
    static void studentInformationMenu(const Student* student);
    static void list(string header, string choices);
    static bool verify(string data);
    static void grade(const Grade* grade);
   
};

#endif