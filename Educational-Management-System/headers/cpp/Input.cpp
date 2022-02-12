#include "../Input.h"


int Input::readInt(int upperBound){
    bool correctFormat = false;
    string temp;
    int choice; 
    do{
        cout<<"Enter a Number: ";
        cin>>temp;
        cin.clear();
        cin.ignore(256,'\n');
        if(temp == "b"){
            return -1;
        }
        if (temp.size() != 1 || !isdigit(temp[0])) {
            continue;
        }

        choice = temp[0] -'0';

        if(choice < upperBound && choice >= 0){
            correctFormat = true;
        }       
    }
    while(!correctFormat);
    return choice;
}
double Input::readDouble(double upperBound){
    double a;
    cout<<"Enter a Number: ";
    cin>>a;
    cin.clear();
    cin.ignore(256, '\n');
    if(a > upperBound){
        cout<<"Enter a Number that is less than "<<upperBound<<": ";
        return readDouble(upperBound);
    }

    return a;
}
string Input::readEmail(){
    bool correctFormat = false;
    string temp;
    regex emailRegex ("([\\w._%-]*@(\\w+(\\.\\w)*(\\.[a-zA-Z]{2,3})+)+)");
    smatch match;
    
    do{
        cout<<"Enter your email: ";
        cout.flush();
        cin>>temp;
        cin.clear();
        cin.ignore(256,'\n');
        if(temp == "0")
            return "0";
        if(regex_search(temp,match,emailRegex)){
            return match.str();
        }
        cout<<"NOT VALID"<<endl;
    }while(true);

}

string Input::readString(string holder){
    string temp;
    cout<<"Enter "<<holder<<": ";
    getline(cin, temp);
    cin.clear();
    return temp;

}
string Input::readNationalID(){
    string temp;
    regex nreg ("([1-9]\\d{13})");
    smatch match;

    do{
        cout<<"Enter your National ID: ";
        cout.flush();
        cin>>temp;
        cin.clear();
        cin.ignore(256,'\n');
        if(temp == "0")
            return "0";
        if(regex_search(temp, match, nreg) && temp.size() == 14){
            return match.str(0);
        }
        cout<<"NOT VALID"<<endl;
        cout<<"To go back enter 0"<<endl;
        cout<<endl;
    }while(true);
}
string Input::readBirthday(){
    string temp;
    regex breg ("(([0-3]?[1-9]) ([0-1]?\\d) ([1-2]\\d\\d\\d))");
    smatch match;
    do{
        cout<<"Enter your Birthday (dd mm yyyy): ";
        cout.flush();
        getline(cin,temp);
        if(temp == "0")
            return "0";
        if(regex_search(temp, match, breg)){
        	int d = std::stoi(match.str(2));
        	int m = std::stoi(match.str(3));
        	int y = std::stoi(match.str(4));
        	if(d<32 && y<3000 && m<=12)
        		return match.str(0);
        }
        cout<<"NOT VALID"<<endl;
        cout<<"To go back enter 0"<<endl;
        cout<<endl;
    }while(true);
}
string Input::readPhoneNumber(){
    string temp;
    regex breg ("01\\d{9}");
    smatch match;
    do{
        cout<<"Enter your Phone Number 01XXXXXXXXX: ";
        cout.flush();
        cin>>temp;
        cin.clear();
        cin.ignore(256,'\n');
        if(temp == "0")
            return "0";
        if(regex_search(temp, match, breg) && temp.size() == 11){
        		return match.str(0);
        }
        cout<<"NOT VALID"<<endl;
        cout<<"To go back enter 0"<<endl;
        cout<<endl;
    }while(true);
}

string Input::readAnswers(){
    cout<<"Please Enter your answers on one line and use \\n to insert a new line"<<endl;
    string temp;
    cout<<"answers: ";
    getline(cin, temp);
    return temp;
}