#include "Investment.h"
#include <iostream>
#include <limits>

using namespace std;

int main() {

    InvestmentCalculator myApp;
    InvestmentData inputData;
    char continueFlag = 'Y';

    // Loop allows the user to test different monthly deposit amounts, interest rates, and lengths of time.
    do {
        // Clear screen or provide separation for a clean look
        system("CLS");

        // 1. Get input data from the user
        inputData = myApp.getDataInput();

        // 2. Display the two required reports
        myApp.displayReports(inputData);

        // 3. Prompt for continuation
        cout << "\nWould you like to enter new investment data? (Y/N): ";
        cin >> continueFlag;

        // Clear input buffer for the next loop
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (toupper(continueFlag) == 'Y');

    return 0;
}