#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


enum QuizLevel {
    easy=1,medium=2,hard=3,mix=4
};

enum OperationType {
    addition=1,subtraction=2,multiplication=3,division=4,Mix=5
};


int getAddition(int left,int right) {
    return left+right;
}

int getSubtraction(int left,int right) {
    return left-right;
}
int getMultiplication(int left,int right) {
    return left*right;
}
int getDivision(int left,int right) {
    return left/right;
}


struct QuizStats {

    short quizNumber;

    QuizLevel quizLevel;

    OperationType operationType;

    short rightAnswerCount;

    short wrongAnswerCount;
};


void loseScreen() {

    cout<<"wrong Answer: "<<endl;
    cout << "\033[2J\033[H\033[41m";
    cout << "\a";
}

void winScreen() {

    cout<<"right Answer: "<<endl;
    cout << "\033[42m";
}

int RandomNumber(int From, int To) {

    return rand() % (To - From + 1) + From;
}

string playAgain(string message) {

    string playAgain;

    do {

        cout << message << endl;
        cin >> playAgain;

    } while (playAgain != "y" && playAgain != "n");

    return playAgain;
}

short getQuizNumber(string message) {

    short quizNumber;

    do {
        cout << message << endl;
        cin >> quizNumber;
    } while (quizNumber < 1 || quizNumber > 10);

    return quizNumber;
}


void gameStatus(QuizStats stats) {
    cout << "\nNumber of Questions    : " << stats.quizNumber << endl;
    cout << "Question Level           : " << stats.quizLevel <<endl;
    cout << "OpType                   : " << stats.operationType << endl;
    cout << "Number of right answers  : " << stats.rightAnswerCount<< endl;
    cout << "Number of wrong answers  : " << stats.wrongAnswerCount << endl;
}

void gameOver(QuizStats stats) {
    cout << "                  ____________________________________________________________________________" << endl;
    cout << "\n\n                                           +++   Final result is   +++" << endl;
    cout << "                  ____________________________________________________________________________" << endl;
    cout << "\n                  _____________________________[Game Results ]______________________________________" << endl;
    gameStatus(stats);
}

QuizLevel getQuizLevel() {

    short quizLevel;
    do {
        cout << "Enter Question level [1] Easy,  [2] Med,  [3] Hard,  [4] Mix" << endl;
        cin>>quizLevel;
    }while (quizLevel < 1 || quizLevel > 4);

    return (QuizLevel)quizLevel;
}

OperationType getOperationType() {

    short operationType;
    do {
        cout << "Enter Operation Type [1] Add,  [2] Sub ,  [3] Mul,  [4] Div, [5] Mix" << endl;
        cin>>operationType;
    }while (operationType < 1 || operationType > 5);

    return (OperationType)operationType;
}


int getNumber(QuizLevel quizLevel) {

    if (quizLevel==QuizLevel::easy) {
        return RandomNumber(1, 9);
    }else if (quizLevel==QuizLevel::medium) {
        return RandomNumber(10,99);
    }else if (quizLevel==QuizLevel::hard) {
        return RandomNumber(100,1000);
    }
}

string operationString(OperationType operation) {
    if (operation == OperationType::addition) {
        return "+";
    }else if (operation == OperationType::subtraction) {
        return "-";
    }else if (operation == OperationType::multiplication) {
        return "*";
    }else if (operation == OperationType::division) {
        return "/";
    }
}




void getResult(int playerAnswer,int rightAnswer,QuizStats &stats) {

   if (playerAnswer == rightAnswer) {
       stats.rightAnswerCount ++;
       winScreen();
   }else {
       stats.wrongAnswerCount ++;
       loseScreen();
   }

}


int getPlayerAnswer() {

    int playerAnswer;
    cin >> playerAnswer;
    return playerAnswer;
}


int getNumbers(QuizLevel quizLevel) {

    switch (quizLevel) {
        case QuizLevel::easy:
            return RandomNumber(1, 9);
        case QuizLevel::medium:
            return RandomNumber(10,99);
        case QuizLevel::hard:
            return RandomNumber(100,1000);
        default: ;
    }

}


int getQuestion(QuizStats stats) {

    int right,left;
    switch (stats.operationType) {
        case OperationType::addition:
            right = getNumbers(stats.quizLevel);
            left =  getNumbers(stats.quizLevel);
            cout<<right<<endl;
            cout<<left<<" +"<<endl;
            cout<<"______________\n";
           return right + left;

        case  OperationType::subtraction:
            right = getNumbers(stats.quizLevel);
            left =  getNumbers(stats.quizLevel);
            cout<<right<<endl;
            cout<<left<<" -"<<endl;
            cout<<"______________\n";
            return right - left;

        case  OperationType::multiplication:
            right = getNumbers(stats.quizLevel);
            left =  getNumbers(stats.quizLevel);
            cout<<right<<endl;
            cout<<left<<" *"<<endl;
            cout<<"______________\n";
            return right * left;

        case  OperationType::division:
            right = getNumbers(stats.quizLevel);
            left =  getNumbers(stats.quizLevel);
            cout<<right<<endl;
            cout<<left<<" /"<<endl;
            cout<<"______________\n";
            return right / left;
        default: ;
    }

}


void startQuiz() {
    QuizStats stats;
    stats.quizNumber = getQuizNumber("How many Questions do you want to answer ?");
    stats.quizLevel = getQuizLevel();
    stats.operationType = getOperationType();
    stats.rightAnswerCount = 0;
    stats.wrongAnswerCount = 0;

    int rightAnswer,userAnswer;
    for (int i=1;i<=stats.quizNumber;i++) {

        cout<<"Question ["<<i<<"/"<<stats.quizNumber<<"]"<<endl;
        rightAnswer = getQuestion(stats);
        userAnswer = getPlayerAnswer();
        getResult(rightAnswer,userAnswer,stats);
    }

    gameOver(stats);
}

void continuePlaying() {
    string choice = playAgain("Do you want to play again? (y/n)");
    if (choice == "y") {
            startQuiz();
    }
}

int main() {
    srand((unsigned)time(NULL));
    startQuiz();
    continuePlaying();
    return 0;
}
