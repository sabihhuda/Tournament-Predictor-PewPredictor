#pragma once
#ifndef PEWPREDICTOR_H
#define PEWPREDICTOR_H

#include "Team.h"
#include <vector>
#include <string>

class PewPredictor {
protected:
    vector<Team> teams;             // This vector to stores the teams participating in the predictor
    vector<Team> quarterFinalTeams; // This vector to stores the quarter-finalist teams
    vector<Team> semiFinalTeams;    // This vector to stores the semi-finalist teams
    vector<Team> winners;           // This vector to stores the winning teams

public:
    PewPredictor(const string& teamFilename); // The Constructor to initialize PewPredictor with team data
    void addTeam(const string& teamName);     // This is the method to add a team to the predictor
    void displayMenu();                       // This is the method to display the predictor's menu
    void displayRound(const vector<Team>& roundTeams); // This is the method to display teams in a round
    virtual void run();                       // This is the method to run the predictor
    void adminOptions();                      // This is the method to handle admin options
    void readTeamsFromFile(const string& filename);    // This is the method to read teams from a file
    
    const vector<Team>& getQuarterFinalists() const;    // This is the method to get quarter-finalist teams
    const vector<Team>& getSemiFinalists() const;        // This is the method to get semi-finalist teams
    const vector<Team>& getWinners() const;              // This is the method to get winning teams
    const vector<Team>& getTeams() const;                // This is the method to get all teams
};

#endif // PEWPREDICTOR_H
