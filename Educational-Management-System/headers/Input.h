#ifndef INPUT_H
#define INPUT_H
#include <string>
#include <iostream>
#include <regex>
using namespace std;

class Input{

public:
    static int readInt(int upperBound);
    static double readDouble(double upperBound);
    static string readEmail();
    static string readString(string holder);
    static string readNationalID();
    static string readBirthday();
    static string readPhoneNumber();
    static string readAnswers();

};

#endif