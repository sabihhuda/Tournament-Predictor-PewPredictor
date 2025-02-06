# Tournament Predictor - PewPredictor
A C++ program designed to manage and predict the outcomes of tournament matches using object-oriented programming principles. The system allows users to input teams, view predictions for different tournament stages, and access administrative functionalities.

---

## Features
- **Team Management:** Easily add, display, and manage participating teams.
- **Prediction System:** Random prediction algorithm for quarterfinals, semifinals, and finals.
- **Advanced Prediction Adjustments:** Handles cases where teams are missing (prototype concept).
- **User-Friendly Menu:** Navigate through prediction stages and administrative options seamlessly.
- **Admin Features:** View teams at various tournament stages, including quarterfinalists, semifinalists, and winners.

---

## Project Structure
- **Team Class:** Manages team details and provides essential methods for data retrieval.
- **PewPredictor Class:** Core engine that handles predictions and rounds.
- **RoundPredictor Class:** Static class for generating random predictions.
- **Admin Class:** Provides advanced functionalities for administrative interactions.
- **advPredictor Class:** (Prototype) Extends prediction capabilities by adjusting outcomes when a team is unavailable.

---

## UML Diagram
![image](https://github.com/user-attachments/assets/5b7b09ab-b752-4119-9aee-0bc352b9783f)


---

## How to Run
1. Clone this repository:
   ```bash
   git clone <repository-url>
   ```
2. Navigate to the project directory:
   ```bash
   cd tournament-predictor
   ```
3. Compile the project using a C++ compiler:
   ```bash
   g++ -o TournamentPredictor Final_project.cpp
   ```
4. Ensure `teamData.txt` exists with team details in the following format:
   ```
   Team A
   Team B
   Team C
   ```
5. Run the program:
   ```bash
   ./TournamentPredictor
   ```
6. Follow the menu instructions to predict tournament rounds and manage teams.

---

## Sample Code Snippets
### 1. Adding Teams to the Predictor
```cpp
void PewPredictor::addTeam(const std::string &teamName) {
    Team newTeam(teamName);
    teams.push_back(newTeam);
    std::cout << "Team " << teamName << " added successfully!\n";
}
```

### 2. Displaying Quarterfinalists
```cpp
void PewPredictor::displayRound(const std::vector<Team> &roundTeams) {
    std::cout << "\nTeams in this round:\n";
    for (const auto &team : roundTeams) {
        team.display();
    }
}
```

### 3. Prediction Algorithm
```cpp
std::vector<Team> RoundPredictor::predictNextRound(const std::vector<Team> &currentRound) {
    std::vector<Team> nextRound;
    std::set<int> selectedIndices;

    srand(time(0));
    while (nextRound.size() < currentRound.size() / 2) {
        int randomIndex = rand() % currentRound.size();
        if (selectedIndices.find(randomIndex) == selectedIndices.end()) {
            nextRound.push_back(currentRound[randomIndex]);
            selectedIndices.insert(randomIndex);
        }
    }

    return nextRound;
}
```

---

## Project Flow
1. **Initialization:** Read team data from a file.
2. **Menu Navigation:** Access prediction rounds or administrative features.
3. **Prediction Execution:** Generate random predictions for each round.
4. **Adjustments:** Handle cases where teams are unavailable (prototype feature).
5. **Results Display:** Show prediction results until the user exits the program.

---

## Reflection
This project was a valuable learning experience in C++ programming and object-oriented design. While I successfully implemented core functionalities, integrating the `advPredictor` class posed challenges due to errors in inheritance and method overriding. Despite this, the project highlighted areas for future improvement and reinforced my understanding of advanced programming concepts.

---

## Future Improvements
- **Enhanced Prediction Algorithm:** Implement a more sophisticated prediction model.
- **Error Handling:** Improve error detection and handling when teams are missing.
- **Unit Testing:** Add test cases for all major functions to ensure robust code.
- **User Interface:** Enhance the menu system for better user interaction.

---

## License
This project is open-source and available under the [MIT License](LICENSE).

---

## Contact
For questions or suggestions, please contact sabihhuda3@gamil.com

