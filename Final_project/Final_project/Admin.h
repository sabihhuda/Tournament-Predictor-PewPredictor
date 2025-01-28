#pragma once
#include "PewPredictor.h"
#include <iostream>

class Admin {
public:
    // The method to start the admin menu with a new advPredictor instance
    void adminMenu();

    // The static method to display the admin menu options
    static void adminMenu(PewPredictor& pewPredictor);

    // The static methods to display information about quarter - finalists, semi - finalists, and winners
    static void getQuarterFinalists(const PewPredictor& pewPredictor);
    static void getSemiFinalists(const PewPredictor& pewPredictor);
    static void getWinners(const PewPredictor& pewPredictor);
};
