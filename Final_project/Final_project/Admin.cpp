#include "Admin.h"
#include "advPredictor.h"  
#include <iostream>
using namespace std;

// This is the method to start the admin menu with a new advPredictor instance
void Admin::adminMenu() {

    // This creates a new instance of advPredictor with "teamData.txt" as the team data file
    advPredictor pewPredictor("teamData.txt");


    // This runs the advPredictor's run method
    pewPredictor.run();
}

// The Static method to display the admin menu options
void Admin::adminMenu(PewPredictor& pewPredictor) {

    // This displays the admin menu options
    cout << "Admin Menu:" << endl;
    cout << "1. View Quarter Finalists" << endl;
    cout << "2. View Semi Finalists" << endl;
    cout << "3. View Winners" << endl;

    // This prompts the user for their choice
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    // This process the user's choice
    switch (choice) {
    case 1:
        // This calls the static method to display quarter-finalists
        getQuarterFinalists(pewPredictor);
        break;
    case 2:
        // This calls the static method to display semi-finalists
        getSemiFinalists(pewPredictor);
        break;
    case 3:
        // This calls the static method to display winners
        getWinners(pewPredictor);
        break;
    default:
        cout << "Invalid choice." << endl;
        break;
    }
}

// The Static method to display information about quarter-finalists
void Admin::getQuarterFinalists(const PewPredictor& pewPredictor) {

    // This retrieves the quarter-finalists from the PewPredictor
    const vector<Team>& quarterFinalists = pewPredictor.getQuarterFinalists();

    // This checks if there are quarter-finalists available
    if (quarterFinalists.empty()) {
        cout << "No quarterfinalists available." << endl;
    }
    else {
        // This displays the names of quarter-finalist teams
        cout << "Quarter-finalists:" << endl;
        for (const auto& team : quarterFinalists) {
            team.display();
        }
    }
}

// The Static method to display information about semi-finalists
void Admin::getSemiFinalists(const PewPredictor& pewPredictor) {

    // This retrieves the semi - finalists from the PewPredictor
    const vector<Team>& semiFinalists = pewPredictor.getSemiFinalists();

    // This checks if there are semi-finalists available
    if (semiFinalists.empty()) {
        cout << "No semi-finalists available." << endl;
    }
    else {
        // This displays the names of semi-finalist teams
        cout << "Semi-finalists:" << endl;
        for (const auto& team : semiFinalists) {
            team.display();
        }
    }
}

// The Static method to display information about winners
void Admin::getWinners(const PewPredictor& pewPredictor) {

    // This retrieves the winners from the PewPredictor
    const vector<Team>& winners = pewPredictor.getWinners();

    // This checks if there are winners available
    if (winners.empty()) {
        cout << "No winners available." << endl;
    }
    else {
        // This displays the names of winning teams
        cout << "Winners:" << endl;
        for (const auto& team : winners) {
            team.display();
        }
    }
}
