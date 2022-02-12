#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

class User{
private:
    static int lastID;
    string name;
    int ID;
    string email;
    string nationalID;
    string address;
    string phoneNumber;
    string password;
    string birthday;
protected:
    string type;
public:
    User(string name, string email, string nationalID, string address, string phoneNumber, string password, string birthday);
    virtual ~User();
    string getEmail() const;
    string getPhoneNumber() const;
    string getAddress() const;
    string getNationalID() const;
    string getName() const;
    int getID() const;
    string getBirthday() const;
    string getPassword() const;
    string getType() const;

    void setEmail(string email);
    void setPhoneNumber(string phoneNumber);
    void setAddress(string address);
    void setNationalID(string nationalID);
    void setName(string name);
    void setBirthday(string birthday);
    void setType(string type);
    void printInfo();

};
#endif