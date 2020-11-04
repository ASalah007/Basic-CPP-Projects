#pragma once
#include <iostream>
#include <string>


class player
{
private:
    std::string name;
    int score = 0;

public:

    void set_score(int s);
    int get_score();
    std::string get_name();
    void score_inc();
    player(std::string n, int s);
    ~player();

};
