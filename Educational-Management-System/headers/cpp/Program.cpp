#include "../Program.h"

User* Program::currentUser = nullptr;
Student* Program::currentStudent = nullptr;
Doctor* Program::currentDoctor = nullptr;
TA* Program::currentTA = nullptr;

void Program::startMenu(){
    Print::startMenu();
    int choice =  Input::readInt(4);
    switch (choice){
    case 1:
        signInMenu();
        break;
    case 2: 
        signUpMenu();
        break;
    case 3: 
        FacultyResources::fillDummyData();
        startMenu();
        break;
    default:
        exit(0);
        break;
    }
}
void Program::signInMenu(){
    Print::signInMenu();
    string email = Input::readEmail();
    if(email == "0"){
        startMenu();
        return;
    }
    string password = Input::readString("password");

    currentUser = FacultyResources::getUser(email, password);
    if(currentUser == nullptr){
        cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
        cout<<"email or password is not correct"<<endl;
        cout<<"        please try again"<<endl;
        signInMenu();
        return;
    }

    string type = currentUser->getType();
    if(type == "Doctor"){
        currentDoctor = dynamic_cast<Doctor *>(currentUser);
        currentUser = nullptr;
        doctorStartMenu();
        return;
    }
    else if(type == "TA"){
        currentTA = dynamic_cast<TA *>(currentUser);
        currentUser = nullptr;
        TAStartMenu();
        return;
    }   
    else if(type == "Student"){
        currentStudent = dynamic_cast<Student *>(currentUser);
        currentUser = nullptr;
        studentStartMenu();
        return;
    }
    else{
        return;
    }
}
void Program::signUpMenu(){
    Print::signUpMenu();
    string name        =  Input::readString("Full Name");
    string address     =  Input::readString("your Address");
    string nationalID  =  Input::readNationalID();
    string phoneNumber =  Input::readPhoneNumber();
    string birthday    =  Input::readBirthday();
    string email       =  Input::readEmail(); 
    string password    =  Input::readString("password");
    Print::list("Sign Up as: ", "Doctor Student TA");
    int choice = Input::readInt(5);
    string type; 
    switch (choice)
    {
    case 1:
        type = "Doctor";
        break;
    case 2:
        type = "Student";
        break;
    case 3:
        type = "TA";
        break;
    }

    string data =   "#Full Name: " + name + 
                    "#Address: "+ address +
                    "#National ID: " + nationalID + 
                    "#Phone Number: "+ phoneNumber +
                    "#Birthday: "+ birthday + 
                    "#email: "+ email +
                    "#password: "+ password+
                    "#Role: " + type;
    
    if(Print::verify(data)){
        if(type == "Doctor"){
            FacultyResources::addDoctor(name, email, nationalID, address, phoneNumber, password, birthday);
            currentDoctor = dynamic_cast<Doctor*>(FacultyResources::getUser(email, password));
            doctorStartMenu();
            return;
        }
        else if(type == "TA"){
            FacultyResources::addTA(name, email, nationalID, address, phoneNumber, password, birthday);
            currentTA = dynamic_cast<TA*>(FacultyResources::getUser(email, password));
            TAStartMenu();
            return;
        }
        else{
            FacultyResources::addStudent(name, email, nationalID, address, phoneNumber, password, birthday);
            currentStudent = dynamic_cast<Student*>(FacultyResources::getUser(email, password));
            studentStartMenu();
            return;
        }
        return;
    }
    else{
        signUpMenu();
        return;
    }
}
void Program::doctorStartMenu(){
    Print::doctorStartMenu(currentDoctor->getName());
    switch (Input::readInt(5))
    {
    case 1:
        doctorCoursesListMenu();
        break;
    case 2:
        doctorOpenCourseMenu();
        break;
    case 3: 
        doctorInformationMenu();
        break;
    default:
        currentDoctor = nullptr;
        startMenu();
        break;
    }

}
void Program::doctorCoursesListMenu(){
    const vector<Course*>& courses = currentDoctor->getCourses();
    string data = "";
    for( Course* a: courses){
        data += a->getName() + "_" + a->getCode() + " ";
    }
    Print::list("Current Courses", data);
    int choice = Input::readInt(courses.size()+1);
    if(choice == 0){
        doctorStartMenu();
        return;
    }
    doctorCourseMenu(courses.at(choice - 1));
}

void Program::doctorCourseMenu(Course* course){
    Print::doctorCourseMenu(course);
    switch(Input::readInt(7)){
        case 1: 
            courseStudentsMenu(course);
            break;
        case 2: 
            courseAssignmentsMenu(course);
            break;
        case 3:
            midtermMarksMenu(course);
            break;
        case 4: 
            finalMarksMenu(course);
            break;
        case 5:
            addNewAssignmentMenu(course);
            break;
        case 6:
            addTAMenu(course);
            break;
        default: 
            doctorCoursesListMenu();
            break;
    }
}
void Program::addTAMenu(Course* course){
    vector<TA>& TAs = FacultyResources::getTAs();
    cout<<setw(30)<<left<<"TA's Name"<<" || ";
    cout<<setw(10)<<left<<"ID"<<" || "<<endl;

    int counter = 1;
    for(TA& t: TAs){
        cout<<setw(3)<<left<<counter<<setw(3)<<left<<"-> "<<setw(24)<<left<<t.getName()<<" || ";
        cout<<setw(10)<<left<<t.getID()<<" || "<<endl;
        counter++;
    }

    string s = Input::readString("TA's ID or 0 to go back");
    if(s == "0"){
        doctorCourseMenu(course);
        return;
    }
    int choice = stoi(s);
    TA* ta = nullptr;
    for(TA& t: TAs){
        if(t.getID() == choice){
            ta = &t;
        }
    }
    if(ta == nullptr){
        cout<<"TA NOT FOUND !!!"<<endl;
        cout<<"TRY AGAIN."<<endl;
        addTAMenu(course);
        return;
    }

    course->addTA(ta);
    ta->addCourse(course);

    cout<<"\nTA was added successfully !!"<<endl;
    doctorCourseMenu(course);
}
void Program::addNewAssignmentMenu(Course* course){
    cout<<"\n\n";
    string name = Input::readString("Assignment Name");
    int marks = 0;
    for(auto i :course ->getAssignments()){
        marks += i.getMaxMark();
    }
    cout<<"The available Assignments Marks = "<<10-marks<<endl;
    int maxMark = Input::readInt(10 - marks + 1);
    if(maxMark == 0){
        doctorCourseMenu(course);
        return;
    }
    course->createAssignment(name,maxMark);
    doctorCourseMenu(course);
}
void Program::courseStudentsMenu(Course* course){
    vector<pair<Student*, Grade>>& studentsAndGrades = course->getStudentsAndGrades();
    cout<<setw(30)<<left<<"Student's Name"<<" || ";
    cout<<setw(10)<<left<<"ID"<<" || ";
    cout<<setw(10)<<left<<"Year Work"<<" || ";
    cout<<setw(10)<<left<<"Midterm"<<" || ";
    cout<<setw(10)<<left<<"finalMark"<<" || ";
    cout<<endl;
    int counter = 1;
    for(pair<Student*, Grade>& sg: studentsAndGrades){
        cout<<setw(3)<<left<<counter<<setw(3)<<left<<"-> "<<setw(24)<<left<<sg.first->getName()<<" || ";
        cout<<setw(10)<<left<<sg.first->getID()<<" || ";
        cout<<setw(10)<<right<<sg.second.getYearWork()<<" || ";
        cout<<setw(10)<<right<<sg.second.getMidtermMark()<<" || ";
        cout<<setw(10)<<right<<sg.second.getFinalMark()<<" || \n";
        counter++;
    }


    cout<<"\n\n"<<endl;
    cout<<"Enter 0 to go back."<<endl;
    Input::readInt(1);
    doctorCourseMenu(course);
}
void Program::courseAssignmentsMenu(Course* course){
    vector<Assignment *> &studentsAssignments = course->getStudentAssignments();
    int counter = 1;

    cout<<setw(20)<<left<<"Assignment Name"<<" || ";
    cout<<setw(15)<<right<<"Student's Mark"<<" || ";
    cout<<setw(10)<<left<<"Status"<<" || "<<endl;
    sort(studentsAssignments.begin(), studentsAssignments.end(), [](auto x, auto y) {return x->getStatus()<y->getStatus(); });
   
    for(Assignment* ass: studentsAssignments){
        cout<<setw(3)<<left<<counter<<setw(3)<<left<<"-> "<<setw(14)<<left<<ass->getName()<<" || ";
        cout<<setw(13)<<right<<ass->getMark()<<"/"<<ass->getMaxMark()<<" || ";
        cout<<setw(10)<<left<<ass->getStatusAsString()<<" || "<<endl;  
        counter++;
    }

    int choice = 1;
    while(true){
        cout<<"\n\n"<<endl;
        cout<<"choose an assignment to set its mark or 0 to go back."<<endl;
        choice = Input::readInt(studentsAssignments.size()+1);
        if(choice  == 0){
            doctorCourseMenu(course);
            return;
        }
        courseAssignmentMenu(studentsAssignments.at(choice-1));
        courseAssignmentsMenu(course);
    }
    doctorCourseMenu(course);
}
void Program::courseAssignmentMenu(Assignment* assignment){
    cout<<"\n\n";
    cout<<assignment->getName()<<" - "<<"( 0 / "<<assignment->getMaxMark()<<")"<<endl;
    cout<<"Student's Answer:\n\n";
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<assignment->getAnswers()<<endl;
    cout<<"----------------------------------------------------------------"<<endl;

    cout<<"Enter Student's Mark "<<endl;
    int mark = Input::readDouble(assignment->getMaxMark()+0.00001);
    if(mark == -1){
        return;
    }
    assignment->setMark(mark);
    assignment->setStatus(GRADED);
    cout<<"Mark is added Successfully ("<<mark<<" / "<<assignment->getMaxMark()<<") "<<endl;
}
void Program::midtermMarksMenu(Course* course){
    vector<pair<Student*, Grade>>& studentsAndGrades = course->getStudentsAndGrades();
    sort(studentsAndGrades.begin(), studentsAndGrades.end(), [](auto a, auto b){return a.second.getMidtermMark() > b.second.getMidtermMark();});
    cout<<setw(10)<<left<<"ID"<<" || ";
    cout<<setw(10)<<left<<"Midterm"<<" || ";
    cout<<setw(10)<<left<<"finalMark"<<" || ";
    cout<<endl;
    int counter = 1;
    for(pair<Student*, Grade>& sg: studentsAndGrades){
        cout<<setw(10)<<left<<sg.first->getID()<<" || ";
        cout<<setw(10)<<right<<sg.second.getMidtermMark()<<" || ";
        cout<<setw(10)<<right<<sg.second.getFinalMark()<<" || "<<endl;
    }


    cout<<"Enter Student ID or 0 to go back: ";
    string s; 
    cin>>s;
    if(s == "0"){
        doctorCourseMenu(course);
        return;
    }
    int ID = stoi(s);
    pair<Student*, Grade>* studentAndGrade = nullptr;
    vector<pair<Student*, Grade>>& stgr = course->getStudentsAndGrades();
    for(auto& sg : stgr){
        if(sg.first->getID() == ID){
            studentAndGrade = &sg;
            break;
        }
    }
    if(studentAndGrade == nullptr){
        cout<<"Student Not Found !!!"<<endl;
        midtermMarksMenu(course);
    }
    
    cout<<"FOUND STUDENT !!!"<<endl;
    cout<<"Student's current Mark: "<< studentAndGrade->second.getMidtermMark() <<endl;
    cout<<"\nEnter Student's new Mark: ";

    double m = Input::readDouble(Grade::MIDTERMMAXMARK+0.000001);
    studentAndGrade->second.setMidetermMark(m);
    cout<<"\n Mark Was Added Successfully !"<<endl;

    midtermMarksMenu(course);
}
void Program::finalMarksMenu(Course* course){
    vector<pair<Student*, Grade>>& studentsAndGrades = course->getStudentsAndGrades();
    sort(studentsAndGrades.begin(), studentsAndGrades.end(), [](auto a, auto b){return a.second.getFinalMark() > b.second.getFinalMark();});
    cout<<setw(10)<<left<<"ID"<<" || ";
    cout<<setw(10)<<left<<"Midterm"<<" || ";
    cout<<setw(10)<<left<<"finalMark"<<" || ";
    cout<<endl;
    int counter = 1;
    for(pair<Student*, Grade>& sg: studentsAndGrades){
        cout<<setw(10)<<left<<sg.first->getID()<<" || ";
        cout<<setw(10)<<right<<sg.second.getMidtermMark()<<" || ";
        cout<<setw(10)<<right<<sg.second.getFinalMark()<<" || "<<endl;
    }

    cout<<"Enter Student ID or 0 to go back: ";
    string s; 
    cin>>s;
    if(s == "0"){
        doctorCourseMenu(course);
        return;
    }
    int ID = stoi(s);

    pair<Student*, Grade>* studentAndGrade = nullptr;
    vector<pair<Student*, Grade>>& stgr = course->getStudentsAndGrades();
    for(auto& sg : stgr){
        if(sg.first->getID() == ID){
            studentAndGrade = &sg;
            break;
        }
    }
    if(studentAndGrade == nullptr){
        cout<<"Student Not Found !!!"<<endl;
        finalMarksMenu(course);
    }
    
    cout<<"FOUND STUDENT !!!"<<endl;
    cout<<"Student's current Mark: "<< studentAndGrade->second.getFinalMark() <<endl;
    cout<<"\nEnter Student's new Mark: ";

    double m = Input::readDouble(Grade::FINALMAXMARK+0.000001);
    studentAndGrade->second.setFinalMark(m);
    cout<<"\n Mark Was Added Successfully !"<<endl;

    finalMarksMenu(course);
}
void Program::doctorOpenCourseMenu(){
    cout<<endl;
    vector<Course>& courses = FacultyResources::getCourses();
    
    string data = "";
    for(Course& a: courses){
        if(a.isOpen())
            continue;
        data += a.getName() + "_(" + a.getCode() + ") ";

    }
    Print::list("Current Available Courses", data);
    
    string courseCode = Input::readString("Course Code");
    if(courseCode == "0"){
        doctorStartMenu();
        return;
    }
    Course* course = FacultyResources::addCourse(courseCode);
    if(course == nullptr){
        cout<<"There is no such course !!"<<endl;
        doctorOpenCourseMenu();
        return;
    }
    if(course->isOpen()){
        cout<<"This course is already open !!"<<endl;
        doctorOpenCourseMenu();
        return;
    }
    course->openCourse();
    
    currentDoctor->addCourse(course);
    cout<<endl;
    cout<<"Course Added Successfully"<<endl;
    doctorStartMenu();
}
void Program::doctorInformationMenu(){
    Print::doctorInformationMenu(currentDoctor);
    Input::readInt(1);
    doctorStartMenu();
}

void Program::TAStartMenu(){
     Print::TAStartMenu(currentTA->getName());
    int choice = Input::readInt(4);
    
    switch(choice){
        case 1:
            TACoursesMenu();
            break;
        case 2: 
            TAInformationMenu();
            break;
        default:
            currentTA = nullptr;
            startMenu();
            break;
    }
}
void Program::TAInformationMenu(){
    currentTA->printInfo();
    cout<<"\n\nEnter 0 to go back\n"<<endl;
    Input::readInt(1);
    TAStartMenu();
    
}
void Program::TACoursesMenu(){
    const vector<Course*>& courses = currentTA->getCourses();
    string data = "";
    for(const Course* a: courses){
        data += a->getName() + "_" + a->getCode() + " ";
    }
    Print::list("Current Courses", data);
    int choice = Input::readInt(courses.size()+1);
    if(choice == 0){
        TAStartMenu();
        return;
    }
    TACourseMenu(courses.at(choice-1));
}
void Program::TACourseMenu(Course* course){
    Print::TACourseMenu(course);
    int choice = Input::readInt(6);
    
    switch(choice){
        case 1: 
            courseStudentsMenu(course);
            break;
        case 2:
            courseAssignmentsMenu(course);
            break;
        case 3:
            midtermMarksMenu(course);
            break;
        case 4: 
            courseAttendanceMenu(course);
            break;
        case 5:
            courseProjectMenu(course);
            break;
        default:
            TAStartMenu();
            break;
    }
}
void Program::courseAttendanceMenu(Course* course){
    string s = Input::readString("Student's ID or 0 to go back");
    if(s == "0"){
        TACourseMenu(course);
    }
    int ID = stoi(s);

    pair<Student*, Grade>* studentAndGrade = nullptr;

    vector<pair<Student*, Grade>> studentAndGrades = course->getStudentsAndGrades();
    for(auto sg : studentAndGrades){
        if(sg.first->getID() == ID){
            studentAndGrade = &sg;
        }
    }
    if(studentAndGrade == nullptr){
        cout<<"Student NOT FOUND !!!"<<endl;
        cout<<"Try Again"<<endl;
        courseAttendanceMenu(course);
        return;
    }

    cout<<"Enter Student's Mark: ";
    double mark= Input::readDouble(Grade::ATTENDANCEMAXMARK+0.0001);
    studentAndGrade->second.setAttendanceMark(mark);
    
    cout<<"Mark was added successfully !!!"<<endl;
    courseAttendanceMenu(course);
}
void Program::courseProjectMenu(Course* course){
    string s = Input::readString("Student's ID or 0 to go back");
    if(s == "0"){
        TACourseMenu(course);
    }
    int ID = stoi(s);

    pair<Student*, Grade>* studentAndGrade = nullptr;

    vector<pair<Student*, Grade>> studentAndGrades = course->getStudentsAndGrades();
    for(auto sg : studentAndGrades){
        if(sg.first->getID() == ID){
            studentAndGrade = &sg;
        }
    }
    if(studentAndGrade == nullptr){
        cout<<"Student NOT FOUND !!!"<<endl;
        cout<<"Try Again"<<endl;
        courseProjectMenu(course);
        return;
    }

    cout<<"Enter Student's Mark: ";
    double mark= Input::readDouble(Grade::PROJECTMAXMARK+0.0001);
    studentAndGrade->second.setProjectMark(mark);
    
    cout<<"Mark was added successfully !!!"<<endl;
    courseProjectMenu(course);
}

void Program::studentStartMenu(){
    Print::studentStartMenu(currentStudent->getName());
    int choice = Input::readInt(6);
    switch(choice){
        case 1:
            studentCourseRegisterationMenu();
            break;
        case 2: 
            studentCoursesMenu();
            break;
        case 3: 
            studentGradesReportMenu();
            break;
        case 4:
            studentInformationMenu();
            break;
        default:
            currentStudent = nullptr;
            startMenu();
            return;
    }
}
void Program::studentCourseRegisterationMenu(){
    cout<<"Open Courses so far:\n"<<endl;
    for(Course* c : FacultyResources::getOpenCourses()){
        cout<<"\t"<<c->getName()<<" - "<<c->getCode()<<endl;    
    }
    cout<<"-------------------------------------------------------------------------------"<<endl;
    string courseCode = Input::readString("The Course Code");
    if(courseCode == "0"){
        return studentStartMenu();
    }
    for_each(courseCode.begin(), courseCode.end(), [](char& c){c = ::toupper(c);});
    vector<const Course*>courses = currentStudent->getCourses();
    for(auto c : courses){
        if(c->getCode() == courseCode){
            cout<<"You are already registered in this course. "<<endl;
            return studentStartMenu();
        }
    }
    try{
        FacultyResources::registerStudent(courseCode, currentStudent);
    }
    catch(exception e){
        cout<<"Course Not Found !!!"<<endl;
        return studentCourseRegisterationMenu();
    }
    cout<<"You are now Registered in this Course"<<endl;
    studentStartMenu();
}
void Program::studentCoursesMenu(){
    const vector<const Course*>& courses = currentStudent->getCourses();
    string data ="";
    for(const Course* c : courses){
        data += c->getName() + "-(" + c->getCode() + ") ";
    }
    Print::list("Registered Courses: ", data);
    cout<<"Choose a Course to view or 0 to go back"<<endl;
    int choice = Input::readInt(courses.size()+1);   
    if(choice == 0){
        return studentStartMenu();
    } 
    const Course* course = courses.at(choice - 1);
    studentCourseMenu(course);
    return;
}
void Program::studentCourseMenu(const Course* course){
    Print::studentCourseMenu(course);
    const vector<Assignment> &ass = course->getAssignments();
    int choice = Input::readInt(ass.size()+1);
    if(choice == 0){
        studentStartMenu();
        return;
    }
    studentAssignmentMenu(course, ass.at(choice-1));
}
void Program::studentAssignmentMenu(const Course* course, Assignment assignment){
    vector<Assignment> &ass = currentStudent->getAssignments();
    Assignment* studentAssignment = nullptr;
    for(Assignment &a : ass){
        if(a.getName() == assignment.getName()){
            studentAssignment = &a;
        }
    }
    if(studentAssignment == nullptr){
        cout<<"error";
    }
    cout<<"\n\n";
    cout<<studentAssignment->getName()<<" - "<<studentAssignment->getMark()<<" / "<<studentAssignment->getMaxMark();
    cout<<" - "<<studentAssignment->getStatusAsString()<<"\n"<<endl;
    int bound;
    if(studentAssignment->getStatus() == GRADED){
        bound = 1;
    }
    else{
        cout<<"1- Submit answers"<<endl;
        bound = 2;
    }
    cout<<"0- Go Back"<<endl;

    int choice = Input::readInt(bound);
    if(choice  == 0)
        studentCourseMenu(course);
    
    string answers = Input::readAnswers();
    studentAssignment->submit(answers);
    studentCourseMenu(course);   
}
void Program::studentGradesReportMenu(){
    const vector<const Course *>& courses = currentStudent->getCourses();
    vector<const Grade*> g;
    
    for(const Course* c : courses){
        g.push_back(c->getGrade(currentStudent->getID()));
    }  
    for(const Grade* gd : g){
        Print::grade(gd);
        cout<<endl;
    }
    cout<<"press 0 to go back";
    int choice = Input::readInt(1);
    studentStartMenu();
}
void Program::studentInformationMenu(){
    Print::studentInformationMenu(currentStudent);
    Input::readInt(1);
    studentStartMenu();
}