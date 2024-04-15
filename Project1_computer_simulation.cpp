#include <iostream>
#include <queue>
#include <unordered_map>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

const double LIFE_EXPECTANCY_MEAN = 55.0;
const double LIFE_EXPECTANCY_STDDEV = 10.0;
const int LIFE_EXPECTANCY_MIN = 25;
const int LIFE_EXPECTANCY_MAX = 80;

class Politician {
public:
    int age;
    string experience;

    Politician(int _age, string _experience) : age(_age), experience(_experience) {}
};

// Function to simulate the life expectancy of a politician
int simulateLifeExpectancy() {
    random_device rd;
    mt19937 gen(rd());
    normal_distribution<double> dist(LIFE_EXPECTANCY_MEAN, LIFE_EXPECTANCY_STDDEV);

    int lifeExpectancy = static_cast<int>(round(dist(gen)));
    return max(min(lifeExpectancy, LIFE_EXPECTANCY_MAX), LIFE_EXPECTANCY_MIN);
}

// Function to check if there are any unfilled positions
bool unfilledPositionFound(unordered_map<string, int>& officePositions) {
    for (const auto& kv : officePositions) {
        if (kv.second < 0)
            return true;
    }
    return false;
}

// Function to check if there is a consul being re-elected within 10 years
bool reelectingConsulFound(vector<Politician>& consuls) {
    for (const auto& consul : consuls) {
        // Assume "firstCounslorDate" is a field in Politician representing the date of first consul term
        if (consul.age >= 52) // Minimum age for re-election + 10 years
            return true;
    }
    return false;
}

// Function to calculate the Political Stability Index (PSI)
int calculatePSI(unordered_map<string, int>& officePositions, vector<Politician>& consuls) {
    int PSI = 100;
    if (unfilledPositionFound(officePositions)) {
        PSI -= 5;
    }
    if (reelectingConsulFound(consuls)) {
        PSI -= 10;
    }
    return PSI;
}

// Function to simulate the annual election process and career progression
void simulateAnnualElections(queue<Politician>& candidates, unordered_map<string, int>& officePositions,
    vector<Politician>& consuls) {
    // Simulation logic for annual elections
}

// Function to update the ages of politicians and remove those who have surpassed their life expectancy
void updateAgesAndRemovePoliticians(queue<Politician>& candidates, vector<Politician>& consuls) {
    // Update ages of politicians
    queue<Politician> newCandidates;
    while (!candidates.empty()) {
        Politician& candidate = candidates.front();
        candidate.age++;
        if (candidate.age <= simulateLifeExpectancy()) {
            newCandidates.push(candidate);
        }
        candidates.pop();
    }
    candidates = move(newCandidates);

    for (auto& consul : consuls) {
        consul.age++;
    }

    // Remove politicians who have surpassed their life expectancy from consuls
    consuls.erase(remove_if(consuls.begin(), consuls.end(),
        [](const Politician& p) { return p.age > simulateLifeExpectancy(); }), consuls.end());
}

// Function to generate new candidates for the election
void generateNewCandidates(queue<Politician>& candidates) {
    // Simulation logic for generating new candidates
}

// Function to print the final results
void printResults(queue<Politician>& candidates, unordered_map<string, int>& officePositions,
    vector<Politician>& consuls, int finalPSI) {
    // Print final results
}

int main() {
    queue<Politician> candidates;
    unordered_map<string, int> officePositions;
    vector<Politician> consuls;

   
  

    // Run simulation for 200 years
    for (int year = 0; year < 200; ++year) {
        // Simulate yearly cycle
        simulateAnnualElections(candidates, officePositions, consuls);
        updateAgesAndRemovePoliticians(candidates, consuls);
        generateNewCandidates(candidates);

        // Update PSI
        int finalPSI = calculatePSI(officePositions, consuls);

        // Output results for each year
        //printResults(candidates, officePositions, consuls, finalPSI);
    }

    return 0;
}
