#include "Team.h"
#include <iostream>
using namespace std;

// This is the implementation of the Team constructor
Team::Team(const string& n) : name(n) {}

// This is the implementation of the display method to print the team name
void Team::display() const {
    cout << name << endl;
}

// This is the implementation of the getName method to retrieve the team name
string Team::getName() const {
    return name;
}
