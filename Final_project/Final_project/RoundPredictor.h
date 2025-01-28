#pragma once
#ifndef ROUNDPREDICTOR_H
#define ROUNDPREDICTOR_H

#include "Team.h"
#include <vector>
using namespace std;

class RoundPredictor {
public:
    static vector<Team> predictRound(const vector<Team>& inputTeams, int numPredictions);
};

#endif // ROUNDPREDICTOR_H
