#include "../User.h"

int User::lastID = 0;

User::User(string name, string email, string nationalID, string address, string phoneNumber, string password, string birthday){
    this->name = name;
    this->email = email;
    this->birthday = birthday;
    this->nationalID = nationalID;
    this->phoneNumber = phoneNumber;
    this->password = password;
    this->ID = ++lastID;
    this->birthday = birthday;
    this->address= address;
}
User::~User(){

}
string User::getEmail() const{
    return email;
}
string User::getPhoneNumber() const{
    return phoneNumber;
}
string User::getAddress() const{
    return address;
}
string User::getNationalID() const{
    return nationalID;
}
string User::getName() const{
    return name;
}
int User::getID() const{
    return ID;
}
string User::getBirthday() const{
    return birthday;
}
string User::getPassword() const{
    return password;
}
string User::getType() const{
    return type;
}

void User::setEmail(string email){
    this->email = email;
}
void User::setPhoneNumber(string phoneNumber){
    this->phoneNumber = phoneNumber;
}
void User::setAddress(string address){
    this->address = address;
}
void User::setNationalID(string nationalID){
    this->nationalID = nationalID;
}
void User::setName(string name){
    this->name = name;
}
void User::setBirthday(string birthday){
    this->birthday = birthday;
}
void User::setType(string type){
    this->type = type;
}

void User::printInfo(){
    cout<<"Full Name: "<<name<<"\n";
    cout<<"ID: "<<ID<<"\n";
    cout<<"Role: "<<type<<"\n";
    cout<<"email: "<<email<<"\n";
    cout<<"National ID: "<<nationalID<<"\n";
    cout<<"Phone Number: "<<phoneNumber<<"\n";
    cout<<"Address: "<<address<<"\n";
    cout<<"birthday: "<<birthday<<endl;
};

