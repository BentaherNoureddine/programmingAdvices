#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct GameStats {

    short roundsNumber;

    short playerWins;

    short computerWins;

    short draws;
};


int RandomNumber(int From, int To) {

    return rand() % (To - From + 1) + From;
}

void loseScreen() {


    cout << "\033[2J\033[H\033[41m";
    cout << "\a";
}

void winScreen() {


    cout << "\033[42m";
}

void drawScreen() {


    cout << "\033[43m";
}

string playAgain(string message) {

    string playAgain;

    do {

        cout << message << endl;
        cin >> playAgain;

    } while (playAgain != "y" && playAgain != "n");

    return playAgain;
}

string getChoice(short choice) {

    switch (choice) {

        case 1: return "Stone";
        case 2: return "Paper";
        case 3: return "Scissors";
    }
}

string getHumanChoice() {

    short playerChoice;

    do {
        cout << "Your choice: [1]:Stone, [2]:Paper, [3]:Scissors? ";
        cin >> playerChoice;
    } while (playerChoice < 1 || playerChoice > 3);

    return getChoice(playerChoice);
}

string getComputerChoice() {
    return getChoice(RandomNumber(1, 3));
}

short getRoundsNumber(string message) {

    short rounds;

    do {
        cout << message << endl;
        cin >> rounds;
    } while (rounds < 1 || rounds > 10);

    return rounds;
}

string getWinner(string computerChoice, string humanChoice) {

    if (humanChoice == computerChoice) {
        drawScreen();
        return "Draw";
    }
    if ((humanChoice == "Stone" && computerChoice == "Scissors") ||
        (humanChoice == "Paper" && computerChoice == "Stone") ||
        (humanChoice == "Scissors" && computerChoice == "Paper")) {
        winScreen();
        return "Human";
    }
    loseScreen();

    return "Computer";
}

void updateStats(string winner, GameStats &stats) {

    if (winner == "Draw") {
        stats.draws++;
    }
    else if (winner == "Computer") {
        stats.computerWins++;
    }
    else {
        stats.playerWins++;
    }
}

string getFinalWinner(GameStats stats) {
    if (stats.playerWins == stats.computerWins){ return "Draw";}

    else if (stats.computerWins>stats.playerWins) {
        return "Computer";
    }else {
        return "Player";
    }
}

void roundStatus(short round, string humanChoice, string computerChoice, GameStats &stats) {

    cout << "_________________Round [" << round << "]___________________" << endl;
    cout << "\nPlayer Choice   : " << humanChoice << endl;
    cout << "Computer Choice : " << computerChoice << endl;
    string winner = getWinner(computerChoice, humanChoice);
    cout << "Round Winner    : [" << winner << "]" << endl;
    updateStats(winner, stats);
    cout << "_____________________________________________________________" << endl;
}

void gameStatus(GameStats stats) {
    cout << "\nGame Rounds    : " << stats.roundsNumber << endl;
    cout << "Player won     : " << stats.playerWins << " times" << endl;
    cout << "Computer won   : " << stats.computerWins << " times" << endl;
    cout << "Draws          : " << stats.draws << " times" << endl;
    cout << "Final Winner   : " << getFinalWinner(stats) << endl;
}

void startRound(short round, GameStats &stats) {
    cout << "Round [" << round << "] begins:\n" << endl;
    string humanChoice = getHumanChoice();
    string computerChoice = getComputerChoice();
    roundStatus(round, humanChoice, computerChoice, stats);
}

void gameOver(GameStats stats) {
    cout << "                  ____________________________________________________________________________" << endl;
    cout << "\n\n                                           +++   GAME OVER   +++" << endl;
    cout << "                  ____________________________________________________________________________" << endl;
    cout << "\n                  _____________________________[Game Results ]______________________________________" << endl;
    gameStatus(stats);
}

void startGame() {
    GameStats stats;
    stats.roundsNumber = getRoundsNumber("How many Rounds? (1 to 10)");
    stats.playerWins = 0;
    stats.computerWins = 0;
    stats.draws = 0;

    for (short i = 1; i <= stats.roundsNumber; i++) {
        startRound(i, stats);
    }

    gameOver(stats);
}

void continuePlaying() {
    string choice = playAgain("Do you want to play again? (y/n)");
    if (choice == "y") {
        startGame();
    }
}

int main() {
    srand((unsigned)time(NULL));
    startGame();
    continuePlaying();
    return 0;
}
