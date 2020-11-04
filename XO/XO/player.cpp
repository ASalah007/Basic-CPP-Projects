#include "player.h"
#include <iostream>
#include <string>


std::string player::get_name() { return name; };
int player::get_score() { return score; };
void player::set_score(int s) { score = s; };
void player::score_inc() { score++; };

player::player(std::string n, int s)
    : name{ n }, score{ s }
{

}

player::~player()
{
}

