#ifndef AIRGEADBANKINGAPP_INVESTMENT_H_
#define AIRGEADBANKINGAPP_INVESTMENT_H_

#include <string>

// 1. Data Structure Class (InvestmentData)
// Types start with upper case (e.g., InvestmentData) 
class InvestmentData {
public:
    // Variables start with lower case (e.g., initialInvestmentAmount) 
    double initialInvestmentAmount;
    double monthlyDepositAmount;
    double annualInterestRate;
    int numberOfYears;
};


// 2. Logic Class (InvestmentCalculator)
class InvestmentCalculator {
public:
    // Functions start with lower case (e.g., getDataInput) 

    // Function to get all input data from the user
    InvestmentData getDataInput();

    // Function to calculate and display the reports for both scenarios
    void displayReports(InvestmentData t_data); // Parameters use t_ prefix 

private:
    // Helper function to perform the core calculation for a single year
    // Note: It's private because it's only used internally by displayReports.
    std::pair<double, double> calculateYearEnd(double t_openingBalance, double t_annualInterestRate, double t_monthlyDeposit);

    // Function to display the formatted table for a single report
    void displayReport(std::string t_reportTitle, InvestmentData t_data, double t_monthlyDeposit);

};

#endif // AIRGEADBANKINGAPP_INVESTMENT_H_