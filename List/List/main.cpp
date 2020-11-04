#include <iostream>
#include <vector>
#include <cctype>
#include <iomanip>
using namespace std;

void display();
void add(vector <int>* listref);
void print(const vector <int>* const listref);
void smallest(const vector <int>* const listref);
void largest(const vector <int>* const listref);
void mean(const vector <int>* const listref);

int main()
{
    cout << "=================Welcomt to the list programm==================\n\n" << endl;
    cout << "please choose an option from the following\n" << endl;
    vector <int> mylist;
    char selection{ 0 };
    do
    {
        display();
        cout << "please choose a number from the list upove : ";
        cin >> selection;
        selection = toupper(selection);

        if (selection == 'A')
            add(&mylist);
        else if (selection == 'P')
            print(&mylist);
        else if (selection == 'S')
            smallest(&mylist);
        else if (selection == 'L')
            largest(&mylist);
        else if (selection == 'M')
            mean(&mylist);
        else if (selection != 'Q')
            cout << "please select an option from upove" << endl;
    } while (selection != 'Q');
}


void display()
{
    cout << "A - add a number to the list" << endl;
    cout << "P - print the numbers in the list" << endl;
    cout << "S - display the smallest number in the list" << endl;
    cout << "L - display the largest number in the list" << endl;
    cout << "m - display the mean of the number in the list" << endl;
    cout << "Q - quit" << endl;
}

void add(vector <int>* listref)
{
    int num{ 0 };
    cout << "Enter the number you want to add to the list : ";
    cin >> num;
    (*listref).push_back(num);
    cout << num << " is added to the list succesffully.\n" << endl;
}

void print(const vector <int>* const listref)
{
    if ((*listref).size() == 0)
        cout << "[] , the list is empty" << endl;
    else {
        cout << "[ ";
        for (auto i : *listref)
            cout << i << " ";
        cout << "]" << endl;
    }
}

void smallest(const vector <int>* const listref)
{
    if ((*listref).size() == 0)
        cout << "[] , the list is empty" << endl;
    else {
        int small{ (*listref).at(0) };
        for (auto i : *listref)
            small = (small <= i) ? small : i;
        cout << "\n\nthe smallest number in the list is : " << small << endl << endl;
    }
}

void largest(const vector <int>* const listref)
{
    if ((*listref).size() == 0)
        cout << "[] , the list is empty" << endl;
    else {
        int large{ (*listref).at(0) };
        for (auto i : *listref)
            large = (large >= i) ? large : i;
        cout << "\n\nthe largest number in the list is : " << large << endl << endl;
    }
}

void mean(const vector <int>* const listref)
{
    if ((*listref).size() == 0)
        cout << "[] , the list is empty" << endl;
    else {
        long int total{ 0 };
        for (auto i : *listref)
            total += i;
        cout << fixed << showpoint << setprecision(2);
        double mean = static_cast<double> (total) / (*listref).size();
        cout << "the mean of the list is : " << mean << endl;
    }
}