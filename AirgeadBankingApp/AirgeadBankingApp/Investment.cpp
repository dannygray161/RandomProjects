#include "Investment.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

using namespace std;

// --- Helper: calculateYearEnd ---
// Purpose: Calculates the year-end balance and interest for one year.
pair<double, double> InvestmentCalculator::calculateYearEnd(
    double t_openingBalance,
    double t_annualInterestRate,
    double t_monthlyDeposit)
{
    double currentBalance = t_openingBalance;
    double yearEndInterest = 0.0;

    // Convert annual percentage rate to a monthly decimal rate.
    // Example: 5% -> 0.05 / 12
    double monthlyInterestRate = (t_annualInterestRate / 100.0) / 12.0;

    // Loop through 12 months.
    for (int month = 1; month <= 12; ++month) {

        // Total: The sum of the opening amount and deposited amount for the month.
        double totalForInterest = currentBalance + t_monthlyDeposit;

        // Interest calculation: (Opening Amount + Deposited Amount) * (Monthly Rate)
        double monthlyInterest = totalForInterest * monthlyInterestRate;

        // Accumulate total earned interest for the year.
        yearEndInterest += monthlyInterest;

        // Closing Balance: The sum of the previous balance plus the interest.
        currentBalance += monthlyInterest;
    }

    // Returns a pair: {YearEndBalance, YearEndInterest}
    return { currentBalance, yearEndInterest };
}


// --- Helper: displayReport ---
// Purpose: Formats and displays one of the two static reports.
void InvestmentCalculator::displayReport(string t_reportTitle, InvestmentData t_data, double t_monthlyDeposit) {

    // Set formatting for currency output
    cout << fixed << setprecision(2);

    // Display formatted report title
    cout << "\n" << setfill('=') << setw(68) << "=" << endl;
    cout << setfill(' ') << left << setw(68) << t_reportTitle << endl;
    cout << setfill('-') << setw(68) << "-" << endl;

    // Display header row for the table
    cout << left << setw(10) << "Year"
        << left << setw(25) << "Year End Balance"
        << left << setw(25) << "Year End Earned Interest" << endl;
    cout << setfill('-') << setw(68) << "-" << endl;

    double currentBalance = t_data.initialInvestmentAmount;

    for (int year = 1; year <= t_data.numberOfYears; ++year) {

        // Calculate the results for the current year
        pair<double, double> resultPair = calculateYearEnd(
            currentBalance,
            t_data.annualInterestRate,
            t_monthlyDeposit
        );

        // Update the balance for the next year's opening amount
        currentBalance = resultPair.first; // resultPair.first is Year End Balance

        // Display formatted report line
        cout << left << setw(10) << year
            << "$" << right << setw(24) << currentBalance
            << "$" << right << setw(24) << resultPair.second << endl; // resultPair.second is Year End Interest
    }
}


// --- Public Method: getDataInput ---
// Purpose: Handles user interaction and input validation.
InvestmentData InvestmentCalculator::getDataInput() {
    InvestmentData inputData;
    bool isValid = false;

    // Display formatted header
    cout << setfill('*') << setw(50) << "" << endl;
    cout << setfill(' ') << left << setw(18) << "" << "Data Input" << right << setw(22) << "" << endl;
    cout << setfill('*') << setw(50) << "" << endl;

    // --- Initial Investment Amount Validation ---
    do {
        cout << "Initial Investment Amount: $";
        if (cin >> inputData.initialInvestmentAmount && inputData.initialInvestmentAmount > 0) {
            isValid = true;
        }
        else {
            isValid = false;
            cerr << "Invalid input. Please enter a positive numerical amount." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!isValid);

    // --- Monthly Deposit Validation ---
    do {
        cout << "Monthly Deposit: $";
        if (cin >> inputData.monthlyDepositAmount && inputData.monthlyDepositAmount >= 0) {
            isValid = true;
        }
        else {
            isValid = false;
            cerr << "Invalid input. Please enter a non-negative numerical amount." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!isValid);

    // --- Annual Interest Rate Validation ---
    do {
        cout << "Annual Interest Percentage: (e.g Enter 5 for 5%) ";
        if (cin >> inputData.annualInterestRate && inputData.annualInterestRate > 0) {
            isValid = true;
        }
        else {
            isValid = false;
            cerr << "Invalid input. Please enter a positive interest rate." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!isValid);

    // --- Number of Years Validation ---
    do {
        cout << "Number of years: ";
        if (cin >> inputData.numberOfYears && inputData.numberOfYears > 0) {
            isValid = true;
        }
        else {
            isValid = false;
            cerr << "Invalid input. Please enter a positive whole number for years." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!isValid);

    // Wait for user to continue to the reports.
    cout << "Press any key to continue . . ." << endl;

    // Clear the input buffer from the last numerical entry
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // Wait for the key press
    cin.get();

    return inputData;
}


// --- Public Method: displayReports ---
// Purpose: Main driver for the report generation.
void InvestmentCalculator::displayReports(InvestmentData t_data) {

    // Report 1: No Monthly Deposits (t_monthlyDeposit = 0.0)
    displayReport(
        "Balance and Interest Without Additional Monthly Deposits",
        t_data,
        0.0
    );

    // Report 2: With Monthly Deposits (t_monthlyDeposit = actual input)
    displayReport(
        "Balance and Interest With Additional Monthly Deposits",
        t_data,
        t_data.monthlyDepositAmount
    );
}