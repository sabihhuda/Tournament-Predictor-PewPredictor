#pragma once
#include "PewPredictor.h"
#include <vector>
#include "Team.h" 
using namespace std;

class advPredictor : public PewPredictor {
public:
    // The constructor for advPredictor, initializes based on team data file
    advPredictor(const string& teamFilename);

    // Override of the run method for custom behavior
    virtual void run() override;

    // This sets quarter-final teams for further predictions
    void setQuarterFinalTeams(const vector<Team>& teams);

    // This sets semi-final teams for further predictions
    void setSemiFinalTeams(const vector<Team>& teams);

    // This adjusts the predictions in case of an unavailable team
    void adjustPredictionsForUnavailableTeam(vector<Team>& teams);

    // This gets the vector of quarter-final teams
    const vector<Team>& getQuarterFinalTeams() const;

    // This gets the vector of semi-final teams
    const vector<Team>& getSemiFinalTeams() const;
};


