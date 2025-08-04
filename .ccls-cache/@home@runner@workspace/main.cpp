#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <cctype>    


void readData(std::vector<std::string>& winners, std::vector<std::string>& losers);


int findWins(const std::string& teamName, const std::vector<std::string>& winners, const std::vector<std::string>& losers);


void writeReport(const std::string& teamName, int wins);


int main() {
    std::vector<std::string> winners;
    std::vector<std::string> losers;
    std::string teamName;
    int wins;

    readData(winners, losers);

    std::cout << "World Series Winner Counter (1903-2009)\n";
    std::cout << "Enter a team name: ";
    std::getline(std::cin, teamName);

    wins = findWins(teamName, winners, losers);

    writeReport(teamName, wins);

    return 0;
}



void readData(std::vector<std::string>& winners, std::vector<std::string>& losers) {
    winners = {
        "Boston Red Sox", "New York Giants", "Chicago White Sox", "Chicago Cubs", "Chicago Cubs",
        "Pittsburgh Pirates", "Philadelphia Athletics", "Philadelphia Athletics", "Boston Red Sox",
        "Philadelphia Athletics", "Boston Braves", "Boston Red Sox", "Chicago White Sox",
        "Boston Red Sox", "Cincinnati Reds", "Cleveland Indians", "New York Giants",
        "New York Giants", "New York Giants", "Washington Senators", "Pittsburgh Pirates",
        "St. Louis Cardinals", "New York Yankees", "New York Yankees", "Philadelphia Athletics",
        "Philadelphia Athletics", "St. Louis Cardinals", "New York Yankees", "New York Yankees",
        "St. Louis Cardinals", "Detroit Tigers", "New York Yankees", "New York Yankees",
        "New York Yankees", "Cincinnati Reds", "New York Yankees", "St. Louis Cardinals",
        "New York Yankees", "St. Louis Cardinals", "St. Louis Cardinals", "Detroit Tigers",
        "St. Louis Cardinals", "New York Yankees", "Cleveland Indians", "New York Yankees",
        "New York Yankees", "New York Yankees", "New York Yankees", "New York Yankees",
        "Milwaukee Braves", "New York Yankees", "Los Angeles Dodgers", "Pittsburgh Pirates",
        "New York Yankees", "New York Yankees", "Los Angeles Dodgers", "St. Louis Cardinals",
        "Los Angeles Dodgers", "Baltimore Orioles", "St. Louis Cardinals", "Detroit Tigers",
        "New York Mets", "Baltimore Orioles", "Pittsburgh Pirates", "Baltimore Orioles",
        "Oakland Athletics", "Oakland Athletics", "Oakland Athletics", "Cincinnati Reds",
        "Cincinnati Reds", "New York Yankees", "New York Yankees", "New York Yankees",
        "Pittsburgh Pirates", "Los Angeles Dodgers", "St. Louis Cardinals", "Baltimore Orioles",
        "Detroit Tigers", "Kansas City Royals", "New York Mets", "Minnesota Twins",
        "Los Angeles Dodgers", "Oakland Athletics", "Cincinnati Reds", "Minnesota Twins",
        "Toronto Blue Jays", "Toronto Blue Jays", "Atlanta Braves", "New York Yankees",
        "Florida Marlins", "New York Yankees", "New York Yankees", "New York Yankees",
        "Arizona Diamondbacks", "Anaheim Angels", "Florida Marlins", "Boston Red Sox",
        "Chicago White Sox", "St. Louis Cardinals", "Boston Red Sox", "Philadelphia Phillies",
        "New York Yankees"
    };

    losers = {
        "Pittsburgh Pirates", "Boston Americans", "New York Giants", "Detroit Tigers", "Detroit Tigers",
        "Detroit Tigers", "Chicago Cubs", "Chicago Cubs", "New York Giants",
        "New York Giants", "Philadelphia Athletics", "Brooklyn Robins", "New York Giants",
        "Chicago Cubs", "Chicago White Sox", "Brooklyn Robins", "Brooklyn Robins",
        "New York Yankees", "New York Yankees", "New York Giants", "Washington Senators",
        "Washington Senators", "St. Louis Cardinals", "Pittsburgh Pirates", "Chicago Cubs",
        "St. Louis Cardinals", "Philadelphia Athletics", "Chicago Cubs", "St. Louis Cardinals",
        "Philadelphia Athletics", "Chicago Cubs", "New York Giants", "Cincinnati Reds",
        "Detroit Tigers", "Brooklyn Dodgers", "Brooklyn Dodgers", "New York Yankees",
        "Brooklyn Dodgers", "Boston Red Sox", "Brooklyn Dodgers", "New York Yankees",
        "New York Yankees", "Brooklyn Dodgers", "Brooklyn Dodgers", "Philadelphia Phillies",
        "Brooklyn Dodgers", "New York Yankees", "New York Yankees", "New York Yankees",
        "Milwaukee Braves", "New York Yankees", "Chicago White Sox", "New York Yankees",
        "Cincinnati Reds", "San Francisco Giants", "New York Yankees", "Philadelphia Phillies",
        "Baltimore Orioles", "Los Angeles Dodgers", "St. Louis Cardinals", "Baltimore Orioles",
        "Cincinnati Reds", "Oakland Athletics", "Los Angeles Dodgers", "New York Mets",
        "Boston Red Sox", "Los Angeles Dodgers", "New York Yankees", "Los Angeles Dodgers",
        "Kansas City Royals", "Milwaukee Brewers", "Philadelphia Phillies", "San Diego Padres",
        "St. Louis Cardinals", "Boston Red Sox", "New York Mets", "St. Louis Cardinals",
        "San Francisco Giants", "Atlanta Braves", "Cleveland Indians", "Atlanta Braves",
        "Philadelphia Phillies", "San Diego Padres", "Cleveland Indians", "San Francisco Giants",
        "New York Yankees", "New York Mets", "Houston Astros", "St. Louis Cardinals",
        "Colorado Rockies", "Tampa Bay Rays", "Philadelphia Phillies"
    };
}

int findWins(const std::string& teamName, const std::vector<std::string>& winners, const std::vector<std::string>& losers) {
    int wins = 0;
    bool teamFound = false;

    std::string lowerTeamName = teamName;
    std::transform(lowerTeamName.begin(), lowerTeamName.end(), lowerTeamName.begin(), ::tolower);

    for (const std::string& winner : winners) {
        std::string lowerWinner = winner;
        std::transform(lowerWinner.begin(), lowerWinner.end(), lowerWinner.begin(), ::tolower);

        if (lowerWinner == lowerTeamName) {
            wins++;
            teamFound = true;
        }
    }

    if (wins == 0) {
        for (const std::string& loser : losers) {
            std::string lowerLoser = loser;
            std::transform(lowerLoser.begin(), lowerLoser.end(), lowerLoser.begin(), ::tolower);
            if (lowerLoser == lowerTeamName) {
                teamFound = true;
                break;
            }
        }
    }

    if (!teamFound) {
        return -1; 
    }
    return wins;
}

void writeReport(const std::string& teamName, int wins) {
    if (wins == -1) {
        std::cout << "Error: The team '" << teamName << "' was not found in the World Series data.\n";
    } else {
        std::cout << "\nThe team '" << teamName << "' won the World Series " << wins << " time(s).\n";
    }
}