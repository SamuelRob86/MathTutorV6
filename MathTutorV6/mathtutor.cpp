//
// Created by Davy Tran on 11/16/25.
//

#include <cstdlib>
#include <iostream> // inclusion required for cin and cout, and Left + Right alignment
#include <iomanip> // for setw
#include <string> // for string stuff
#include <vector> // for vectors
#include <limits>
#include "mathtutor.h"

using namespace std;

const int LEVEL_CHANGE_RANGE = 10;

void DisplayGameIntro()
{
    // It looks wierd here, but once run, the ASCII looks correct
    cout << "*********************************************************************" << endl;
    cout << "*     __  __       _   _       _____      _               _ _ _     *" << endl;
    cout << "*    |  \\/  | __ _| |_| |__   |_   _|   _| |_ ___  _ __  | | | |    *" << endl;
    cout << "*    | |\\/| |/ _` | __| '_ \\    | || | | | __/ _ \\| '__| | | | |    *" << endl;
    cout << "*    | |  | | (_| | |_| | | |   | || |_| | || (_) | |    |_|_|_|    *" << endl;
    cout << "*    |_|  |_|\\__,_|\\__|_| |_|   |_| \\__,_|\\__\\___/|_|    (_|_|_)    *" << endl;
    cout << "*********************************************************************" << endl;
    cout << "*            Welcome to the Silly Simple Math Tutor V5!             *" << endl;
    cout << "*********************************************************************" << endl;
    cout << endl;
    cout << "Fun Math Facts:" << endl << endl << "  * Teaching is hard\n" << "  * Math is sometimes hard\n" <<
        "  * It gets easier the more you practice\n" << "  * Math is fun when it's easy!" << endl;
    cout << endl;
    cout << "********************************************************************" << endl;
    cout << endl;

    return;
}

string GetUserName()
{
    string userName = "?";

    cout << "What is your name? ";
    getline(cin, userName);
    cout << endl << "Welcome, " << userName << ", to the Silly Simple Math Tutor!" << endl << endl;

    return userName;
}


vector<int> GenerateRandomQuestion(int mathLevel) {

    enum MathType { MT_ADD = 1, MT_SUB = 2, MT_MUL = 3, MT_DIV = 4 };
    MathType mathType = MT_ADD;
    int firstNumber = 0;
    int secondNumber = 0;
    int correctAnswer = 0;
    int levelRange = 10;
    int temp = 0;
    int mathOp = 0;

    firstNumber = rand() % levelRange + 1;
    secondNumber = rand() % levelRange + 1;
    mathType = static_cast<MathType>(rand() % 4 + 1);

    switch (mathType)
    {
        case MT_ADD:
            mathOp = '+';
            correctAnswer = firstNumber + secondNumber;
            break;
        case MT_SUB:
            mathOp = '-';
            if (firstNumber < secondNumber)
            {
                temp = firstNumber;
                firstNumber = secondNumber;
                secondNumber = temp;
            }
            correctAnswer = firstNumber - secondNumber;
            break;
        case MT_MUL:
            mathOp = '*';
            correctAnswer = firstNumber * secondNumber;
            break;
        case MT_DIV:
            mathOp = '/';
            firstNumber *= secondNumber;
            correctAnswer = firstNumber / secondNumber;
            break;
        default:
            cout << "Error -1. Please Contact Samuel for catastrophic failure.";
            exit(-1);
    }


    // should take in the numbers and data from question
    return {mathLevel, firstNumber, mathOp, secondNumber,correctAnswer};
}

/*************************
 *loop until numeric value is entered, then return user's answer.
 ***************************/
int GetNumericValue() {
    int userAnswer = 0;

    while (!(cin >> userAnswer))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');;
        cout << "\tInvalid input!" << endl;
        cout << "\tPlease enter a valid number: ";
    }

    return userAnswer;
}

/*************************
 *asking user if they want to play again, loops until y/n is entered, returns answer.
 ***************************/
string AskToPlayAgain() {

    string userInput = "?";

    while (true)
    {
        cout << "\nDo you want to continue? (y=yes | n=no) ";
        getline(cin, userInput);

        //to lower the input's case
        for (int i = 0; i < userInput.size(); i++) {
            userInput.at(i) = tolower(userInput.at(i));
        }
        if (userInput == "y" || userInput == "yes" || userInput == "n" || userInput == "no") {
            break;
        } else {
            cout << endl << "Invalid input! please try again..." << endl;
            cout << endl;
        } //end of if (y,yes,n,no)
    } // end of inner while loop to validate
    return userInput;
} //end of asktoplayagain

void DisplaySummaryReport(const vector<vector<int>> questions) {

    int mathLevel = 0;
    int firstNumber = 0;
    int mathOp = 0;
    int secondNumber = 0;
    int correctAnswer = 0;
    int attempts = 0;
    int totalCorrect = 0;
    int totalIncorrect = 0;
    // Thanks for playing + Summary Report

    cout << setfill('=') << setw(36) << "" << endl;
    cout << "         SUMMARY REPORT" << endl;
    cout << setfill('=') << setw(36) << "" << endl;
    cout << left << "Level      " << "Question        " << right << "Attempts" << endl;
    cout << "-----  ---------------    ----------" << endl;
    cout << setfill(' ');
    totalCorrect = 0;
    totalIncorrect = 0;
    //redefining variables from 2D vector for ease of display
    for (int i = 0; i < questions.size(); i++)
    {
        mathLevel = questions.at(i).at(0);
        firstNumber = questions.at(i).at(1);
        mathOp = questions.at(i).at(2);
        secondNumber = questions.at(i).at(3);
        correctAnswer = questions.at(i).at(4);
        attempts = questions.at(i).at(5);
        //displaying report stats
        cout << "  " << setw(2) << right << mathLevel << " "
            << setw(5) << right << firstNumber << " " << static_cast<char>(mathOp) << " " << secondNumber << "  =" << setw(4) << right <<
            correctAnswer << "  ";
        // dealing with attempts stuff
        if (attempts != 0)
        {
            cout << setw(8) << right << attempts << endl;
            totalCorrect++;
        }
        else
        {
            cout << setw(12) << right << "Incorrect" << endl;
            totalIncorrect++;
        }
    }
    cout << endl;
    //averages and totals
    cout << "Total Questions:" << setw(6) << right << totalCorrect + totalIncorrect << endl;
    cout << "Total Correct  :" << setw(6) << right << totalCorrect << endl;
    cout << "Total Incorrect:" << setw(6) << right << totalIncorrect << endl;
    cout << "Average Correct:" << setw(7) << right << (totalCorrect * 100) / questions.size() << "%" << endl;
}

bool GiveThreeAttempts(string userName, vector<int> &currentQuestion) {
    const int MAX_ATTEMPTS = 3;
    int userAnswer = 0;

    int mathLevel = currentQuestion.at(0);
    int firstNumber = currentQuestion.at(1);
    char mathOp = static_cast<char>(currentQuestion.at(2));
    int secondNumber = currentQuestion.at(3);
    int correctAnswer = currentQuestion.at(4);

    bool isCorrect = false;

    for (int i = 1; i <= MAX_ATTEMPTS; i++)
    {
        cout << "[Level #" << mathLevel << "] " << userName << ", Answer the following: " << firstNumber << " " <<
            mathOp << " " << secondNumber << " = ";
        // Loop  until user gives an actual number
        userAnswer = GetNumericValue();

        if (userAnswer == correctAnswer)
        {
            isCorrect = true;
            cout << "\nCorrect! " << correctAnswer << " is the answer!" << endl;
            currentQuestion.push_back(i);
            break;
        }
        else
        {
            // out of attempts
            if (i == MAX_ATTEMPTS)
            {

                cout << "\nIncorrect... " << correctAnswer << " is the answer..." << endl;
                currentQuestion.push_back(0);
            }
            // still has attempts
            else
            {
                cout << "\nIncorrect! [Attempts Left: " << MAX_ATTEMPTS - i << "]" << endl;
            }
        }
    }
    return isCorrect;
}
//Changes Level/Level Range
void CheckForLevelChange (int &totalCorrect, int &totalIncorrect, int &mathLevel) {
    int levelRange = 0;
    if (totalCorrect == 3)
    {

        mathLevel++;
        levelRange = mathLevel * LEVEL_CHANGE_RANGE;
        totalCorrect = 0;
        totalIncorrect = 0;
        cout << "Level UP!\tNew Level: " << mathLevel << "." << endl;
        cout << "Range UP!\tNew Range: 1-" << levelRange << "." << endl;
    }
    else if (totalIncorrect == 3 && mathLevel > 1)
    {
        mathLevel--;
        levelRange / LEVEL_CHANGE_RANGE;
        totalCorrect = 0;
        totalIncorrect = 0;
        cout << "Level DOWN...\tNew Level: " << mathLevel << "." << endl;
        cout << "Range DOWN...\tNew Range: 1-" << levelRange << "." << endl;
    }
    return;
}