#include "../Print.h"


void fixOutput(int a, int b){
    if(a < b){
        cout<<endl;
        return;
    }
    for(int i =a-b; i>0; i--){
        cout<<" ";
    }
    cout<<"|"<<endl;
}
void Print::startMenu(){
    cout<<"                                         ==========================================================         "<<endl;
    cout<<"                                        |                                                          |         "<<endl;
    cout<<"                                        |                                                          |         "<<endl;
    cout<<"                                        |                                                          |         "<<endl;  
    cout<<"                                        |                                                          |         "<<endl;
    cout<<"                                        |       Welcome to the Educational Management System.      |         "<<endl;
    cout<<"                                        |       ---------------------------------------------      |         "<<endl;
    cout<<"                                        |                                                          |         "<<endl;
    cout<<"                                        |                                                          |         "<<endl;
    cout<<"                                        |                                                          |         "<<endl;
    cout<<"                                        |                                                          |         "<<endl;
    cout<<"                                        |                                                          |         "<<endl;
    cout<<"                                        |             1- Sign In                                   |         "<<endl;
    cout<<"                                        |             2- Sign Up                                   |         "<<endl;
    cout<<"                                        |             3- Fill the system with DummyData            |         "<<endl;
    cout<<"                                        |                                                          |         "<<endl;
    cout<<"                                        |             0- exit                                      |         "<<endl;
    cout<<"                                        |                                                          |         "<<endl;
    cout<<"                                        |      Please choose from the options above.               |         "<<endl;
    cout<<"                                        |                                                          |         "<<endl;
    cout<<"                                        |                                                          |         "<<endl;
    cout<<"                                         ==========================================================          "<<endl;
}

void Print::signInMenu(){
    cout<<"                     ========================================  "<<endl;
    cout<<"                    |                                        | "<<endl;
    cout<<"                    |                                        | "<<endl;
    cout<<"                    |                 Sign In                | "<<endl;
    cout<<"                    |                 -------                | "<<endl;
    cout<<"                    |                                        | "<<endl;
    cout<<"                    |       Enter your Email to sign in      | "<<endl;
    cout<<"                    |       or                               | "<<endl;
    cout<<"                    |       Enter 0 to go back               | "<<endl;
    cout<<"                    |                                        | "<<endl;
    cout<<"                    |                                        | "<<endl;
    cout<<"                     ========================================  "<<endl;
}

void Print::signUpMenu(){
    cout<<"                     ========================================  "<<endl;
    cout<<"                    |                                        | "<<endl;
    cout<<"                    |                                        | "<<endl;
    cout<<"                    |                 Sign Up                | "<<endl;
    cout<<"                    |                 -------                | "<<endl;
    cout<<"                    |                                        | "<<endl;
    cout<<"                    |                                        | "<<endl;
    cout<<"                     ========================================  "<<endl;

}
void Print::doctorStartMenu(string name){
    cout<<"                     =================================================================         "<<endl;
    cout<<"                    |                                                                 |         "<<endl;
    cout<<"                    |                                                                 |         "<<endl;
    cout<<"                    |   Welcome Doctor: "<<name; fixOutput(46, name.size());
    cout<<"                    |   --------------------------------------------------------      |         "<<endl;
    cout<<"                    |                                                                 |         "<<endl;
    cout<<"                    |       1- List open Courses                                      |         "<<endl;
    cout<<"                    |       2- Open new Course                                        |         "<<endl;
    cout<<"                    |       3- Personal Information                                   |         "<<endl;
    cout<<"                    |       4- Log out                                                |         "<<endl;
    cout<<"                    |                                                                 |         "<<endl;
    cout<<"                    |      Please choose from the options above.                      |         "<<endl;
    cout<<"                    |                                                                 |         "<<endl;
    cout<<"                    |                                                                 |         "<<endl;
    cout<<"                     =================================================================          "<<endl;
}

void Print::doctorCourseMenu(const Course* course){
    cout<<"                     ======================================================  "<<endl;
    cout<<"                    |                                                      | "<<endl;
    cout<<"                    |   Course Name: "<<course->getName(); fixOutput(38, course->getName().size());
    cout<<"                    |   Course Code: "<<course->getCode(); fixOutput(38, course->getCode().size());
    cout<<"                    |   -----------------------------------------------    | "<<endl;
    cout<<"                    |                                                      | "<<endl;
    cout<<"                    |     -> Number of Registered Students: "<<course->noOfRegisteredStudents();fixOutput(15,to_string(course->noOfRegisteredStudents()).size());
    cout<<"                    |                                                      | "<<endl;
    cout<<"                    |     -> There are "<<course->noOfAssignments()<<" Assignments:                      |"<<endl;
    cout<<"                    |                                                      | "<<endl;
    cout<<"                    |                                                      | "<<endl;
    cout<<"                    |     1- View Students                                 | "<<endl;
    cout<<"                    |     2- View Assignments                              | "<<endl;
    cout<<"                    |     3- MidTerm Marks                                 | "<<endl;
    cout<<"                    |     4- Final Marks                                   | "<<endl;
    cout<<"                    |     5- Add new Assignment                            | "<<endl;
    cout<<"                    |     6- Add TA                                        | "<<endl;
    cout<<"                    |                                                      | "<<endl;
    cout<<"                    |     0- Back                                          | "<<endl;
    cout<<"                    |                                                      | "<<endl;
    cout<<"                    |     Please Select from the above Options.            | "<<endl;
    cout<<"                    |                                                      | "<<endl;
    cout<<"                    |                                                      | "<<endl;
    cout<<"                     ======================================================  "<<endl;    
}

void Print::TAStartMenu(string name){
    cout<<"                     =================================================================         "<<endl;
    cout<<"                    |                                                                 |         "<<endl;
    cout<<"                    |                                                                 |         "<<endl;
    cout<<"                    |   Welcome TA: "<<name; fixOutput(50, name.size());
    cout<<"                    |   --------------------------------------------------------      |         "<<endl;
    cout<<"                    |                                                                 |         "<<endl;
    cout<<"                    |       1- List My Courses                                        |         "<<endl;
    cout<<"                    |       2- Personal Information                                   |         "<<endl;
    cout<<"                    |       3- Log out                                                |         "<<endl;
    cout<<"                    |                                                                 |         "<<endl;
    cout<<"                    |      Please choose from the options above.                      |         "<<endl;
    cout<<"                    |                                                                 |         "<<endl;
    cout<<"                    |                                                                 |         "<<endl;
    cout<<"                     =================================================================         "<<endl;
}
void Print::TACourseMenu(const Course* course){
    cout<<"                     ======================================================  "<<endl;
    cout<<"                    |                                                      | "<<endl;
    cout<<"                    |   Course Name: "<<course->getName(); fixOutput(38, course->getName().size());
    cout<<"                    |   Course Code: "<<course->getCode(); fixOutput(38, course->getCode().size());
    cout<<"                    |   -----------------------------------------------    | "<<endl;
    cout<<"                    |                                                      | "<<endl;
    cout<<"                    |     -> Number of Registered Students: "<<course->noOfRegisteredStudents()<<endl;
    cout<<"                    |                                                      | "<<endl;
    cout<<"                    |     -> There are "<<course->noOfAssignments()<<" Assignments:                      |"<<endl;
    cout<<"                    |                                                      | "<<endl;
    cout<<"                    |                                                      | "<<endl;
    cout<<"                    |     1- View Students                                 | "<<endl;
    cout<<"                    |     2- View Assignments                              | "<<endl;
    cout<<"                    |     3- MidTerm Marks                                 | "<<endl;
    cout<<"                    |     4- Attendance Marks                              | "<<endl;
    cout<<"                    |     5- Project Marks                                 | "<<endl;
    cout<<"                    |                                                      | "<<endl;
    cout<<"                    |     0- Back                                          | "<<endl;
    cout<<"                    |                                                      | "<<endl;
    cout<<"                    |     Please Select from the above Options.            | "<<endl;
    cout<<"                    |                                                      | "<<endl;
    cout<<"                    |                                                      | "<<endl;
    cout<<"                     ======================================================  "<<endl;    
  
}
void Print::studentStartMenu(string name){

    cout<<"                     ======================================================  "<<endl;
    cout<<"                    |                                                      | "<<endl;
    cout<<"                    |   Welcome: "<<name;fixOutput(42, name.size());
    cout<<"                    |   ------------------------------------------------   | "<<endl;
    cout<<"                    |                                                      | "<<endl;
    cout<<"                    |      1- Register in a course                         | "<<endl;
    cout<<"                    |      2- List my courses                              | "<<endl;
    cout<<"                    |      3- Grades Report                                | "<<endl;
    cout<<"                    |      4- Student Information                          | "<<endl;
    cout<<"                    |      5- Log Out                                      | "<<endl;
    cout<<"                    |                                                      | "<<endl;
    cout<<"                    |                                                      | "<<endl;
    cout<<"                    |                                                      | "<<endl;
    cout<<"                    |       Select option from above.                      | "<<endl;
    cout<<"                    |                                                      | "<<endl;
    cout<<"                    |                                                      | "<<endl;
    cout<<"                     ======================================================  "<<endl;    
}
void Print::studentCourseMenu(const Course* course){
    cout<<"                     ======================================================  "<<endl;
    cout<<"                    |                                                      | "<<endl;
    cout<<"                    |   Course Name: "<<course->getName();fixOutput(38, course->getName().size());           
    cout<<"                    |   Course Code: "<<course->getCode();fixOutput(38, course->getCode().size());
    cout<<"                    |                                                      | "<<endl;
    int counter =1;
    for(const Assignment &a : course->getAssignments()){
        cout<<"                    |   "<<counter<<"- "<<a.getName()<<" - "<<a.getMaxMark();
        fixOutput(51 ,to_string(counter).size() + a.getName().size() + to_string(a.getMaxMark()).size()+5);         
        counter++;
    }    
    cout<<"                    |                                                      | "<<endl;
    cout<<"                    |     Select Assignment to Submit or 0 to go back.     | "<<endl;
    cout<<"                    |                                                      | "<<endl;
    cout<<"                    |                                                      | "<<endl;
    cout<<"                     ======================================================  "<<endl;    
}
void Print::studentInformationMenu(const Student* student){
    cout<<"                     ===================================================================  "<<endl;
    cout<<"                    |                                                                   | "<<endl;
    cout<<"                    |   Name: "<<student->getName();fixOutput(58, student->getName().size());
    cout<<"                    |   ID: "<<student->getID();fixOutput(60, to_string(student->getID()).size());
    cout<<"                    |   Email: "<<student->getEmail();fixOutput(57, student->getEmail().size());
    cout<<"                    |   National ID: "<<student->getNationalID();fixOutput(51, student->getNationalID().size());
    cout<<"                    |   Phone Number: "<<student->getPhoneNumber();fixOutput(50, student->getPhoneNumber().size());
    cout<<"                    |   Address: "<<student->getAddress();fixOutput(55, student->getAddress().size());
    cout<<"                    |   Birthday: "<<student->getBirthday();fixOutput(54, student->getBirthday().size());
    cout<<"                    |   Registered Courses:                                             | "<<endl;
    for(const Course* c : student->getCourses()){
        cout<<"                    |         "<<c->getName()<<" - "<<c->getCode();
        fixOutput(58, c->getName().size() + 3 + c->getCode().size());
    }
    cout<<"                    |                                                                   | "<<endl;
    cout<<"                    |                        Enter 0 to go back.                        | "<<endl;
    cout<<"                    |                                                                   | "<<endl;
    cout<<"                    |                                                                   | "<<endl;
    cout<<"                     ===================================================================  "<<endl;    
}

void Print::doctorInformationMenu(const Doctor* doctor){
    cout<<"                     ===================================================================  "<<endl;
    cout<<"                    |                                                                   | "<<endl;
    cout<<"                    |   Name: "<<doctor->getName();                   fixOutput(58, doctor->getName().size());
    cout<<"                    |   ID: "<<doctor->getID();                       fixOutput(60, to_string(doctor->getID()).size());
    cout<<"                    |   Email: "<<doctor->getEmail();                 fixOutput(57, doctor->getEmail().size());
    cout<<"                    |   National ID: "<<doctor->getNationalID();      fixOutput(51, doctor->getNationalID().size());
    cout<<"                    |   Phone Number: "<<doctor->getPhoneNumber();    fixOutput(50, doctor->getPhoneNumber().size());
    cout<<"                    |   Address: "<<doctor->getAddress();             fixOutput(55, doctor->getAddress().size());
    cout<<"                    |   Birthday: "<<doctor->getBirthday();           fixOutput(54, doctor->getBirthday().size());
    cout<<"                    |   Registered Courses:                                             |" <<endl;
    for(const Course* c : doctor->readCourses()){
        cout<<"                    |       "<<c->getName()<<" - "<<c->getCode();
        fixOutput(60, c->getName().size()+3+c->getCode().size());
    }
    cout<<"                    |                                                                   | "<<endl;
    cout<<"                    |                        Enter 0 to go back.                        | "<<endl;
    cout<<"                    |                                                                   | "<<endl;
    cout<<"                    |                                                                   | "<<endl;
    cout<<"                     ===================================================================  "<<endl;    
}

void Print::list(string header, string choices){
    cout<<endl;
    cout<<header<<"\n"<<endl;
    cout<<"--------------------------------------------"<<endl;
    istringstream sin(choices);
    string temp;
    int i=1;
    while(sin>>temp){
        replace(temp.begin(), temp.end(), '_', ' ');
        cout<< i << "- " << temp<<endl;
        i++;
    }
    cout<<"\n---------------------------------------------"<<endl;
    cout<<"Choose option from above.\n\n"<<endl;
}

bool Print::verify(string data){
    
    cout<<"                     ==========================================================          "<<endl;
    cout<<"                    |                                                          |         "<<endl;  
    cout<<"                    |                                                          |         "<<endl;
    cout<<"                    |            Please verify the following Data.             |         "<<endl;
    cout<<"                    |            ---------------------------------             |         "<<endl;
    cout<<"                    |                                                          |         "<<endl;
    cout<<"                    |                                                          |         "<<endl;
    cout<<"                     ==========================================================          "<<endl;

    int counter = 0;
    for(int i=0; i<data.size(); i++){
        if(data[i] == '#'){
            counter++;
            cout<<endl;
            cout<<"\t\t\t"<<counter<<"-";
            i++;
        }
        cout<<data[i];
    }
    cout<<endl<<endl;
    cout<<"Is this data Correct (y/n): ";
    cout.flush();
    string c;
    cin>>c;
    cin.clear();
    cin.ignore(256, '\n');
    if(tolower(c[0]) == 'y')
        return true;
    else
        return false;
}


void Print::grade(const Grade* grade){
    cout<<"                     ======================================================  "<<endl;
    cout<<"                    |                                                      | "<<endl;
    cout<<"                    |   Course Name: "<<grade->getCourse()->getName();   fixOutput(38, grade->getCourse()->getName().size());
    cout<<"                    |   Student Name: "<<grade->getStudent()->getName(); fixOutput(37, grade->getStudent()->getName().size());
    cout<<"                    |   Studnet ID: "<<grade->getStudent()->getID();     fixOutput(39, to_string(grade->getStudent()->getID()).size()); 
    cout<<"                    |   -----------------------------------------------    | "<<endl;
    cout<<"                    |                                                      | "<<endl;
    cout<<"                    |     Attendance Mark  : "<<grade->getAttendanceMark()<<endl;
    cout<<"                    |     Assignments Mark : "<<grade->getAssignmentsMark()<<endl;
    cout<<"                    |     Quizes Mark      : "<<grade->getQuizesMark()<<endl;
    cout<<"                    |     Projcet Mark     : "<<grade->getProjectMark()<<endl;
    cout<<"                    |     MidTerm Mark     : "<<grade->getMidtermMark()<<endl;
    cout<<"                    |     Final Mark       : "<<grade->getFinalMark()<<endl;
    cout<<"                    |                                                      | "<<endl;
    cout<<"                    |                                                      | "<<endl;
    cout<<"                    |              Total Mark: "<<grade->getTotalMark()<<endl;
    cout<<"                    |                                                      | "<<endl;
    cout<<"                    |                                                      | "<<endl;
    cout<<"                     ======================================================  "<<endl;    
}