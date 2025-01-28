#pragma once
#ifndef TEAM_H
#define TEAM_H

#include <string>
using namespace std;

class Team {
private:
    string name;

public:
    // The constructor to initialize a Team with a given name
    Team(const string& teamName);

    // The method to display the name of the team
    void display() const;

    // The getter method to retrieve the name of the team
    string getName() const;
    
};

#endif // TEAM_H
