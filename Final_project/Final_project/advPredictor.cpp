#include "advPredictor.h"
#include "RoundPredictor.h"
#include <iostream>
using namespace std;

// The implementation of setting semi-final teams
void advPredictor::setSemiFinalTeams(const vector<Team>& teams) {
    semiFinalTeams = teams;
}

// The implementation of adjusting predictions in case of an unavailable team
void advPredictor::adjustPredictionsForUnavailableTeam(vector<Team>& teams) {
    // Check if there are teams available
    if (!teams.empty()) {
        cout << "Adjusting predictions for an unavailable team..." << endl;
        cout << "Team " << teams[0].getName() << " is unable to compete." << endl;

        // Remove the first team from the list
        teams.erase(teams.begin());

        cout << "Adjustment complete." << endl;
    }
}

// The implementation of the run method, handling user choices
void advPredictor::run() {
    while (true) {
        displayMenu();

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Round 1:" << endl;
            cout << "Quarter Finalist:" << endl;

            // This adjusts the predictions for unavailable team
            adjustPredictionsForUnavailableTeam(quarterFinalTeams);

            // This predicts the quarter-finalists based on adjusted predictions
            setQuarterFinalTeams(RoundPredictor::predictRound(getQuarterFinalTeams(), 4));
            displayRound(getQuarterFinalTeams());
            cout << endl;
            break;

        case 2:
            if (getQuarterFinalTeams().empty()) {
                cout << "Error: Round 2 predictions cannot be made without Round 1 results." << endl;
            }
            else {
                cout << "Round 2:" << endl;
                cout << "Semi Finalist:" << endl;

                // This adjusts predictions for unavailable team
                adjustPredictionsForUnavailableTeam(quarterFinalTeams);

                // This predicts the semi-finalists based on adjusted quarter-final teams
                setSemiFinalTeams(RoundPredictor::predictRound(getQuarterFinalTeams(), 2));
                displayRound(getSemiFinalTeams());
                cout << endl;
            }
            break;

        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
            break;
        }
    }
}

// The implementation to get the vector of quarter-final teams
const vector<Team>& advPredictor::getQuarterFinalTeams() const {
    return quarterFinalTeams;
}

// The implementation to get the vector of semi-final teams
const vector<Team>& advPredictor::getSemiFinalTeams() const {
    return semiFinalTeams;
}

// The implementation to set the vector of quarter-final teams
void advPredictor::setQuarterFinalTeams(const vector<Team>& teams) {
    quarterFinalTeams = teams;
}

// Constructor for advPredictor, calls the base class constructor
advPredictor::advPredictor(const string& teamFilename) : PewPredictor(teamFilename) {
    
}