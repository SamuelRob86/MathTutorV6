/*
 * Program: MathTutorV6
 * Programmer(s): Samuel Robinson, Davy Tran
 * Date(s): 11/24/2025
 * Github Repository: https://github.com/SamuelRob86/MathTutorV6
 * Description: Math tutor application for children/young adolescence that generates a new problem with random numbers
 * and operators with varying difficulty(number sizes) based upon the level they are on, and will report a summary of
 * the user's statistics.
 */


#include <iostream> // inclusion required for cin and cout, and Left + Right alignment
#include <iomanip> // for setw
#include <string> // for string stuff
#include <ctime> // for randomness
#include <limits> // for limits
#include <vector> // for vectors


using namespace std; // sets standard namespace

void DisplayGameIntro();
string GetUserName();
vector<int> GenerateRandomQuestion(int mathLevel);
int GetNumericValue();

string AskToPlayAgain();
bool GiveThreeAttempts(string userName, vector<int> &currentQuestion);
void CheckForLevelChange(int &totalCorrect, int &totalIncorrect, int &mathLevel);
void DisplaySummaryReport(vector<vector<int>> questions);

const int LEVEL_CHANGE_RANGE = 10;

int main()
{
    //Declaring and initializing Variables

    enum MathType { MT_ADD = 1, MT_SUB = 2, MT_MUL = 3, MT_DIV = 4 };


    int userAnswer = 0;
    int firstNumber = 0;
    int secondNumber = 0;
    int correctAnswer;
    int totalCorrect = 0;
    int totalIncorrect = 0;
    int mathLevel = 1;
    int levelRange = LEVEL_CHANGE_RANGE;
    int temp = 0;
    int attempts;
    MathType mathType = MT_ADD;
    char mathOp = '?';
    string userName = "unknown";
    string userInput = "?";
    srand(time(0));

    bool isCorrect = false;
    //2D vector for questions
    vector<vector<int>> questions;

    // Header of actual program:

    DisplayGameIntro();

    // ----------------------------------------Actual program stuff----------------------------------------

    userName = GetUserName();


    //do-while loop here
    do
    {
        //generates random numbers based on level and range

        vector<int> currentQuestion = GenerateRandomQuestion(mathLevel);

        isCorrect = GiveThreeAttempts(userName, currentQuestion);

       if (isCorrect) {
           totalCorrect++;
       } else {
           totalIncorrect++;
       }
        cout << endl;
        // records question info for report
        questions.push_back(currentQuestion);

        CheckForLevelChange(totalCorrect, totalIncorrect, mathLevel);

        getline(cin, userInput); // clears input buffer

        userInput = AskToPlayAgain();
    }
    while (userInput == "yes" || userInput == "y");

    DisplaySummaryReport(questions);

    cout << endl << "Thanks for playing!" << endl;
    return 0;
}

