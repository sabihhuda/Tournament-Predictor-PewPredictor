#include "RoundPredictor.h"
#include <cstdlib>

// This is the definition of the static method to predict a round
std::vector<Team> RoundPredictor::predictRound(const std::vector<Team>& inputTeams, int numPredictions) {
    std::vector<Team> result; // Vector to store the predicted teams

    // This iterates for the specified number of predictions
    for (int i = 0; i < numPredictions; ++i) {
        int index = rand() % inputTeams.size(); // Generate a random index within the size of the input teams
        result.push_back(inputTeams[index]);    // Add the randomly selected team to the result
    }

    return result; // This Returns the vector of predicted teams
}