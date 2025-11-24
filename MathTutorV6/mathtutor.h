//
// Created by Davy Tran on 11/16/25.
//

#ifndef MATHTUTORV5_MATHTUTOR_H
#define MATHTUTORV5_MATHTUTOR_H

#include <string> // for string stuff
#include <vector> // for vectors

using namespace std;

void DisplayGameIntro();
string GetUserName();
vector<int> GenerateRandomQuestion(int mathLevel);
int GetNumericValue();
string AskToPlayAgain();
bool GiveThreeAttempts(string userName, vector<int> &currentQuestion);
void CheckForLevelChange(int &totalCorrect, int &totalIncorrect, int &mathLevel);
void DisplaySummaryReport(vector<vector<int>> questions);

#endif //MATHTUTORV5_MATHTUTOR_H