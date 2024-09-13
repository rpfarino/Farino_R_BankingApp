// BankingApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Robert Farino
// Southern New Hampshire University
// CS 210 - Programming Languages


#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include "YearEndBalAndInterest.h"
using namespace std;


// Asks the user for the initial investment amount, monthly deposit, annual interest, and number of years.
void inputAmts(double& t_investAmount, double& t_monthlyDeposit, int& t_annInterest, int& t_numYears) {

    cout << endl;
    cout << "**********************************" << endl;
    cout << "********** Data Input ************" << endl;
    cout << "Initial Investment Amount: $";
    cin >> t_investAmount;
    cout << "Monthly Deposit: $";
    cin >> t_monthlyDeposit;
    cout << "Annual Interest: %";
    cin >> t_annInterest;
    cout << "Number of years: ";
    cin >> t_numYears;
    cin.ignore();
    cout << "Press any key to continue . . ." << endl;
    cin.get();
}

// Calculates the monthly interest given the amount and annual interest rate percentage.
double amtInterest(double t_amount, int t_annInterest) {

    return t_amount * ((t_annInterest / 100.0) / 12);
}

// Calculates the closing balance given the investment amount, monthly deposit, and 
// monthly interest accrued.
double closingBal(double t_investAmount, double t_monthlyDeposit, double t_interestAmt) {

    return t_investAmount + t_monthlyDeposit + t_interestAmt;
}

// Calculates the year-end balance and annual interest for each year given the 
// initial investment amount, monthly deposit, annual interest percentage, and 
// number of years. The results are stored in the t_yearEndData vector.
void calcYearEndBalAndIntData(double t_investAmount, double t_monthlyDeposit, int t_annInterest, int t_numYears,
                              vector<YearEndBalAndInterest>& t_yearEndData)
{
    double openingAmount = t_investAmount;
    double totalAmount;
    double interestAmount;
    double closingBalance;
    double yearEndInterest;

    // For the number of years we are performing calculations.
    for (int yearNum = 1; yearNum <= t_numYears; ++yearNum)
    {
        yearEndInterest = 0;

        // For each month in the current year.
        for (int monthNum = 1; monthNum <= 12; ++monthNum)
        {
            // Calculate the monthly interest amount, update the year-end interest,
            // and calculate the closing balance which will be the opening balance
            // for the following month.
            totalAmount = openingAmount + t_monthlyDeposit;
            interestAmount = amtInterest(totalAmount, t_annInterest);
            yearEndInterest += interestAmount;
            closingBalance = closingBal(openingAmount, t_monthlyDeposit, interestAmount);
            openingAmount = closingBalance;
        }

        // Add a record with the year number, year-end closing balance, and year-end interest to the vector.
        t_yearEndData.push_back(YearEndBalAndInterest(yearNum, closingBalance, yearEndInterest));
    }
}

// Prints a table containing the data in the t_yearEndData vector.
// For each record, the year, year-end balance, and annual interest are printed.
// The title of the table will vary depending on the "With Monthly Deposits" flag.
void showYearEndBalAndIntData(bool t_withMonthlyDep, vector<YearEndBalAndInterest> t_yearEndData) {
     
    ostringstream yearEndBalSS;
    ostringstream yearEndEarnedIntSS;

    cout << endl;
    cout << endl;

    // Print table title.
    if (t_withMonthlyDep)
        cout << "    Balance and Interest With Additional Monthly Deposits" << endl;
    else
        cout << "    Balance and Interest Without Additional Monthly Deposits" << endl;

    // Print table header.
    cout << "===============================================================" << endl;
    cout << " Year         Year End Balance     Year End Earned Interest" << endl;
    cout << "---------------------------------------------------------------" << endl;

    // For each year-end data record in the vector.
    for (int i = 0; i < t_yearEndData.size(); ++i)
    {
        // Initialize strings containing the '$' symbol.
        yearEndBalSS.str("");
        yearEndEarnedIntSS.str("");

        // Create year-end balance and year-end earned interest strings with the '$' symbol.
        yearEndBalSS << "$" << fixed << setprecision(2) << t_yearEndData.at(i).getYearEndBalance();
        yearEndEarnedIntSS << "$" << fixed << setprecision(2) << t_yearEndData.at(i).getYearEndEarnedInterest();

        // Print year, year-end balance, and year-end earned interest.
        cout << right
            << setw(4) << t_yearEndData.at(i).getYear()
            << setw(26) << yearEndBalSS.str()
            << setw(29) << yearEndEarnedIntSS.str();
        cout << endl;
    }
}


int main()
{
    double investAmount;
    double monthlyDeposit;
    int annInterest; 
    int numYears;
    char inputChar = 'Y';
    vector<YearEndBalAndInterest> yearEndDataWithDeposit;
    vector<YearEndBalAndInterest> yearEndDataWithoutDeposit;

    // Re-run program until the user wants to exit.
    while (inputChar == 'Y' || inputChar == 'y')
    {
        // Clear the vectors in case the program is run more than once.
        yearEndDataWithDeposit.clear();
        yearEndDataWithoutDeposit.clear();

        // Ask user for inputs. 
        inputAmts(investAmount, monthlyDeposit, annInterest, numYears);

        // Calculate balance and interest without additional monthly deposits.
        calcYearEndBalAndIntData(investAmount, 0, annInterest, numYears, yearEndDataWithoutDeposit);

        // Calculate balance and interest with additional monthly deposits.
        calcYearEndBalAndIntData(investAmount, monthlyDeposit, annInterest, numYears, yearEndDataWithDeposit);

        // Display balance and interest without additional monthly deposits.
        showYearEndBalAndIntData(false, yearEndDataWithoutDeposit);

        // Display balance and interest with additional monthly deposits.
        showYearEndBalAndIntData(true, yearEndDataWithDeposit);

        // Ask the user if they would like to run the program again.
        cout << endl << "Would you like to continue (Y/N)?" << endl;
        cin >> inputChar;
    }
}

