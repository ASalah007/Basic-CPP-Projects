#include "../FacultyResources.h"
#include <cstdlib>
vector<Course> FacultyResources::courses = {
    Course("Programming", "CSE122"),
    Course("Advanced_Programming", "CSE211"),
    Course("Discrete_Mathematics", "PHM211"),
    Course("Data_Structures_and_Algorithms", "CSE331"),
    Course("Operating_Systems", "CSE335"),
    Course("Computer_Networks", "CSE351"),
    Course("Control_Engineering", "CSE371"),
    Course("Design_and_Analysis_of_Algorithms", "CSE332"),
    Course("Database_Systems", "CSE333"),
    Course("Software_Engineering", "CSE334"),
    Course("Parallel_and_Distributed_Systems", "CSE352"),
    Course("Real-Time_Embedded_Systems_and_Design", "CSE411"),
    Course("Design_of_Compilers", "CSE439"),
    Course("Artificial_Intelligence", "CSE472"),
    Course("Software_Project_Management", "CSE441"),
    Course("Computer_and_Network_Security", "CSE451")
    };
vector<Course*> FacultyResources::openCourses;
vector<Student> FacultyResources::students = {Student("STUDENT", "s@ems.com", "12345678901234", "Cairo", "01234567890", "123", "27 12 1999")};
vector<TA> FacultyResources::TAs= {TA("TEACHING ASSISTANT", "t@ems.com", "12345678901234", "Cairo", "01234567890", "123", "27 9 2000")};
vector<Doctor> FacultyResources::doctors = {Doctor("DOCTOR", "d@ems.com", "12345678901234", "Cairo", "01234567890", "123", "27 9 2000")};

User* FacultyResources::getUser(string email){
    for(auto& i : students){
        if(i.getEmail() == email)
            return &i;
    }
    for(auto& i : TAs){
        if(i.getEmail() == email)
            return &i;
    }
    for(auto& i : doctors){
        if(i.getEmail() == email)
            return &i;
    }
    return nullptr;
}
User* FacultyResources::getUser(string email, User& currentUser){
    User* user = getUser(email);
    if(user == nullptr)
        return nullptr;
    string userType = user->getType();
    string type = currentUser.getType();
   
   if (type == "Doctor"){
        return user;
    }
    else if (type == "TA"){
        if (userType == "Student")
            return user;
        throw exception();
    }
    else {
        throw exception();
    }
}
User* FacultyResources::getUser(string email, string password){
    User* user = getUser(email);
    if (user == nullptr)
        return nullptr;
    if(user->getPassword() == password)
        return user;
    return nullptr;
}

vector<Course*>& FacultyResources::getOpenCourses(){
    return openCourses;
}
vector<Course>& FacultyResources::getCourses(){
    return courses;
}

void FacultyResources::addStudent(string name, string email, string nationalID, string address, string phoneNumber, string password,string birthday){
    students.push_back(Student(name, email, nationalID, address, phoneNumber, password, birthday));
}
void FacultyResources::registerStudent(string courseCode, Student* student){
    Course* course = getCourse(courseCode);
    if(course == nullptr)
        throw exception();
    student->addGrade(course->registerStudent(student));
    const Course* c = course;
    student->addCourse(c);
}

void FacultyResources::addTA(string name, string email, string nationalID, string address, string phoneNumber, string password, string birthday){
    TAs.push_back(TA(name, email, nationalID, address, phoneNumber, password, birthday));
}
vector<TA>& FacultyResources::getTAs(){
    return TAs;
}

void FacultyResources::addDoctor(string name, string email, string nationalID, string address, string phoneNumber, string password, string birthday){
    doctors.push_back(Doctor(name, email, nationalID, address, phoneNumber, password, birthday));
}
Course* FacultyResources::addCourse(string courseCode){
    Course* course = getCourse(courseCode);
    if(course != nullptr && !course->isOpen()){
        openCourses.push_back(course);
    }
    return course;
}
Course* FacultyResources::getCourse(string courseCode){
    for(auto& c : courses){
        if(c.getCode() == courseCode){
            return &c;
        }
    }
    return nullptr;
}


void FacultyResources::fillDummyData(){
    cout<<"\n\nThe following Doctors have been added to the system"<<endl;
    for(int i=0; i<10; i++){
        string name = "DOCTOR" + to_string(i);
        string email = "d" + to_string(i) + "@ems.com";
        doctors.push_back(Doctor(name, email, "12345678901234", "Cairo", "01234567890", "123", "23 9 1980"));
        Doctor* temp = &doctors.back();
        Course* course = FacultyResources::addCourse(courses[i].getCode());
        temp->addCourse(course);
        course->openCourse();

        cout<<name<<" - "<<email<< " -> "<<course->getName()<<endl;
    }
    cout<<"-----------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\nThe following Students have been added to the system."<<endl;
    for(int i=0; i<1000; i++){
        string name = "STUDENT" + to_string(i);
        string email = "s" + to_string(i) + "@ems.com";
        students.push_back(Student(name, email, "12345678901234", "Cairo", "01234567890", "123", "27 12 1998"));
        cout<<name<<" - "<<email<<endl;
    }

    for(Student& s: students){
        int r = rand()%(openCourses.size()-2);
        s.addGrade(openCourses[r]->registerStudent(&s));
        s.addCourse(openCourses[r]);
        s.addGrade(openCourses[r+1]->registerStudent(&s));
        s.addCourse(openCourses[r+1]);
        s.addGrade(openCourses[r+2]->registerStudent(&s));
        s.addCourse(openCourses[r+2]);
    }
    
    cout<<"-----------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\nThe following TAs have been added to the system."<<endl;
    for(int i=0; i<60; i++){
        
        string name = "TA" + to_string(i);
        string email = "t" + to_string(i) + "@ems.com";
        TAs.push_back(TA(name, email, "12345678901234", "Cairo", "01234567890", "123", "23 9 1980"));
        TA* temp = &TAs.back();

        cout<<name<<" - "<<email<<endl;
    }
    cout<<"-----------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\n\nNote: All Passwords are \"123\"."<<endl;
}
