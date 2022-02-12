#ifndef PROGRAM_H
#define PROGRAM_H

#include <iostream>
#include "User.h"
#include "Input.h"
#include "Print.h"
#include "FacultyResources.h"
#include <ctype.h>
#include <iomanip>

using namespace std;
class Program{
private: 
    static User* currentUser;
    static Student* currentStudent;
    static Doctor* currentDoctor;
    static TA* currentTA;  
    Program();

public:
    static void startMenu();
    static void signInMenu();
    static void signUpMenu();

    static void doctorStartMenu();
    static void doctorCoursesListMenu();
    static void doctorCourseMenu(Course* course);
    static void addTAMenu(Course* course);
    static void doctorOpenCourseMenu();
    static void doctorInformationMenu();
    static void addNewAssignmentMenu(Course* course);
    static void courseStudentsMenu(Course* course);
    static void courseAssignmentsMenu(Course* course);
    static void courseAssignmentMenu(Assignment* assignment);
    static void midtermMarksMenu(Course* course);
    static void finalMarksMenu(Course* course);

    static void TAStartMenu();
    static void TACoursesMenu();
    static void TACourseMenu(Course* course);
    static void TAInformationMenu();
    static void courseAttendanceMenu(Course* course);
    static void courseProjectMenu(Course* course);

    static void studentStartMenu();
    static void studentCourseRegisterationMenu();
    static void studentCoursesMenu();
    static void studentCourseMenu(const Course* course);
    static void studentAssignmentMenu(const Course* course, Assignment assignment);
    static void studentGradesReportMenu();
    static void studentInformationMenu();
};


#endif