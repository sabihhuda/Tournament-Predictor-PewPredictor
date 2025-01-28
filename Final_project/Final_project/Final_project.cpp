#include <iostream>
#include "PewPredictor.h"
#include "RoundPredictor.h"

int main() {
    // This creates an instance of the PewPredictor class, initializing it with team data from "teamData.txt"
    PewPredictor pewPredictor("teamData.txt");

    // This runs the main loop of the PewPredictor application
    pewPredictor.run();

    return 0;
}
