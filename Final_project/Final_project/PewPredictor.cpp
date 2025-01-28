#include "PewPredictor.h"
#include "RoundPredictor.h"
#include "Admin.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

// This is the constructor to initialize PewPredictor with team data
PewPredictor::PewPredictor(const string& teamFilename) {
    readTeamsFromFile(teamFilename);
}

// This is the method to read teams from a file
void PewPredictor::readTeamsFromFile(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Unable to open file: " << filename << endl;
        perror("Error details");
        exit(EXIT_FAILURE);
    }

    string teamName;

    while (getline(file, teamName)) {
        addTeam(teamName);
    }

    file.close();
}

// This is the method to display the predictor's menu
void PewPredictor::displayMenu() {
    cout << "Pew Predictor Menu:" << endl;
    cout << "1. Round 1 Predictions" << endl;
    cout << "2. Round 2 Predictions" << endl;
    cout << "3. Round 3 Predictions" << endl;
    cout << "4. Admin Options" << endl;
    cout << "5. Exit" << endl;
}

// This is the method to display teams in a round
void PewPredictor::displayRound(const vector<Team>& roundTeams) {
    for (const auto& team : roundTeams) {
        team.display();
    }
}

// This is the method to run the predictor
void PewPredictor::run() {
    while (true) {
        displayMenu();

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Round 1:" << endl;
            cout << "Quarter Finalist:" << endl;
            quarterFinalTeams = RoundPredictor::predictRound(teams, 4);
            displayRound(quarterFinalTeams);
            cout << endl;
            break;

        case 2:
            if (quarterFinalTeams.empty()) {
                cout << "Error: Round 2 predictions cannot be made without Round 1 results." << endl;
            }
            else {
                cout << "Round 2:" << endl;
                cout << "Semi Finalist:" << endl;
                semiFinalTeams = RoundPredictor::predictRound(quarterFinalTeams, 2);
                displayRound(semiFinalTeams);
                cout << endl;
            }
            break;

        case 3:
            if (semiFinalTeams.empty()) {
                cout << "Error: Round 3 predictions cannot be made without Round 2 results." << endl;
            }
            else {
                cout << "Round 3:" << endl;
                cout << "Winner:" << endl;
                winners = RoundPredictor::predictRound(semiFinalTeams, 1);
                displayRound(winners);
                cout << endl;
            }
            break;
        case 4: // Admin Options
            adminOptions();
            cout << endl;
            break;

        case 5: // Exit
            cout << "Exiting Pew Predictor. Goodbye!" << endl;
            exit(EXIT_SUCCESS);
            break;

        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
            break;
        }
    }
}

// This is the method to add a team to the predictor
void PewPredictor::addTeam(const string& teamName) {
    teams.push_back(Team(teamName));
}

// This is the method to handle admin options
void PewPredictor::adminOptions() {
    string username, password;
    cout << "Enter admin username: ";
    cin >> username;
    cout << "Enter admin password: ";
    cin >> password;

    if (username == "AUser" && password == "pew2024") {
        Admin::adminMenu(*this);
    }
    else {
        cout << "Invalid admin credentials." << endl;
    }
}

// This is the method to get quarter-finalist teams
const vector<Team>& PewPredictor::getQuarterFinalists() const {
    return quarterFinalTeams;
}

// This is the method to get semi-finalist teams
const vector<Team>& PewPredictor::getSemiFinalists() const {
    return semiFinalTeams;
}

// This is the method to get winning teams
const vector<Team>& PewPredictor::getWinners() const {
    return winners;
}

// This is the method to get all teams
const vector<Team>& PewPredictor::getTeams() const {
    return teams;
}