#include <iostream>
#include <string>
#include "player.h"

void NewGame(player& p1, player& p2);
void print_arrs(std::string h, std::string a1, std::string a2, std::string a3);
void play(char pn, int wt, std::string& a1, std::string& a2, std::string& a3);


int main()
{
    std::cout << "Enter player one name : ";

    std::string n1;
    std::string n2;

    getline(std::cin, n1);
    std::cout << std::endl;
    std::cout << "Enter Player two name : ";
    getline(std::cin, n2);
    std::cout << std::endl;

    player p1(n1, 0);
    player p2(n2, 0);

    NewGame(p1, p2);

    char a{ 'n' };
    do
    {
        std::cout << ", do you want to play again (y\n) :";
        std::cin >> a;

        if (a == 'y' || a == 'Y')
            NewGame(p1, p2);

    } while (a == 'y' || a == 'Y');

}


void NewGame(player& p1, player& p2)
{

    std::cout << p1.get_name() << "'s score: " << p1.get_score() << " VS " << p2.get_name() << "'s score: " << p2.get_score() << std::endl << std::endl;

    std::string hashs{ "------------------------------" };

    std::string arr1{ "     1       2       3 " };
    std::string arr2{ "     4       5       6 " };
    std::string arr3{ "     7       8       9 " };

    char& pn1{ arr1.at(5) };
    char& pn2{ arr1.at(13) };
    char& pn3{ arr1.at(21) };

    char& pn4{ arr2.at(5) };
    char& pn5{ arr2.at(13) };
    char& pn6{ arr2.at(21) };

    char& pn7{ arr3.at(5) };
    char& pn8{ arr3.at(13) };
    char& pn9{ arr3.at(21) };

    print_arrs(hashs, arr1, arr2, arr3);


    int wturn{ 0 };
    do
    {
        if (wturn % 2 == 0)
            std::cout << p1.get_name() << "'s turn";
        else
            std::cout << p2.get_name() << "'s turn";

        std::cout << ", please choose a number : ";
        char a{ '0' };
        std::cin >> a;
        std::cout << std::endl;

        play(a, wturn, arr1, arr2, arr3);
        print_arrs(hashs, arr1, arr2, arr3);

        char X = 'X';
        char O = 'O';


        if (wturn >= 3)
        {
            if (((pn1 == pn2) && (pn2 == pn3) && (pn3 == X)) || ((pn4 == pn5) && (pn5 == pn6) && (pn6 == X)) || ((pn7 == pn8) && (pn8 == pn9) && (pn9 == X)) || ((pn1 == pn4) && (pn4 == pn7) && (pn7 == X)) || ((pn2 == pn5) && (pn5 == pn8) && (pn8 == X)) || ((pn3 == pn6) && (pn6 == pn9) && (pn9 == X)) || ((pn1 == pn5) && (pn5 == pn9) && (pn9 == X)) || ((pn3 == pn5) && (pn5 == pn7) && (pn7 == X)))
            {
                std::cout << "Congratulation, " << p1.get_name() << " won";
                p1.set_score(p1.get_score() + 1);
                wturn = 9;
            }
            else if (((pn1 == pn2) && (pn2 == pn3) && (pn3 == O)) || ((pn4 == pn5) && (pn5 == pn6) && (pn6 == O)) || ((pn7 == pn8) && (pn8 == pn9) && (pn9 == O)) || ((pn1 == pn4) && (pn4 == pn7) && (pn7 == O)) || ((pn2 == pn5) && (pn5 == pn8) && (pn8 == O)) || ((pn3 == pn6) && (pn6 == pn9) && (pn9 == O)) || ((pn1 == pn5) && (pn5 == pn9) && (pn9 == O)) || ((pn3 == pn5) && (pn5 == pn7) && (pn7 == O)))
            {
                std::cout << "Congratulation, " << p2.get_name() << " won";
                p2.set_score(p2.get_score() + 1);
                wturn = 9;
            }
        }
        wturn++;
    } while (wturn < 9);


}


void print_arrs(std::string h, std::string a1, std::string a2, std::string a3)
{
    std::cout << h << std::endl;
    std::cout << a1 << std::endl;
    std::cout << h << std::endl;
    std::cout << a2 << std::endl;
    std::cout << h << std::endl;
    std::cout << a3 << std::endl;
}



void play(char pn, int wt, std::string& a1, std::string& a2, std::string& a3)
{
    for (char& i : a1)
    {
        if (i == pn && wt % 2 == 0)
        {
            i = 'X';
            return;
        }
        else if (i == pn && wt % 2 != 0)
        {
            i = 'O';
            return;
        }
    }

    for (char& i : a2)
    {
        if (i == pn && wt % 2 == 0)
        {
            i = 'X';
            return;
        }
        else if (i == pn && wt % 2 != 0)
        {
            i = 'O';
            return;
        }
    }for (char& i : a3)
    {
        if (i == pn && wt % 2 == 0)
        {
            i = 'X';
            return;
        }
        else if (i == pn && wt % 2 != 0)
        {
            i = 'O';
            return;
        }
    }
}

