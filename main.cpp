// Imari Sims
// COSC 1336
// This program is a Paycheck calculator that will calculates the gross pay to get net pay.
// To get net pay, federal, social security, and medicare taxes will be substracted from the
// gross pay. The progrm will ask the user to enter the gross pay, pay period, and filing status.
// The program will the compute the taxes using the standard tax tables and will display a pay stub.
// This program includes a main menu as well for navigation.

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Declarations
double calculateFIT(double grossPay, string payPeriod, string filingStatus);
double calculateSS(double grossPay);
double calculateMED(double grossPay);
void displayPayStub(double grossPay, double FIT, double SS, double MED, double netPay);
void getInput(double& grossPay, string& payPeriod, string& filingStatus);

int main() {
    char menuOption;

    do {
        // Show the menu
        cout << "\n--- Paycheck Calculator ---\n";
        cout << "=============================\n";
        cout << "Main Menu\n";
        cout << "1. Calculate a Paycheck\n";
        cout << "0. Exit Program\n";
        cout << "Enter Menu Option: ";
        cin >> menuOption;

        if (menuOption == '1') {
            double grossPay;
            string payPeriod, filingStatus;

            // Get user input
            getInput(grossPay, payPeriod, filingStatus);

            // Calculate taxes and net pay
            double FIT = calculateFIT(grossPay, payPeriod, filingStatus);
            double SS = calculateSS(grossPay);
            double MED = calculateMED(grossPay);
            double netPay = grossPay - FIT - SS - MED;

            // Display pay stub
            displayPayStub(grossPay, FIT, SS, MED, netPay);

        }
        else if (menuOption != '0') {
            cout << "\nInvalid option. Please try again.\n";
        }
    } while (menuOption != '0');

    cout << "\nExiting program. Goodbye!\n";
    system("pause");
    return 0;
}

// Function to get user input
void getInput(double& grossPay, string& payPeriod, string& filingStatus) {
    cout << "\nCalculate a Paycheck\n";
    cout << "======================\n";

    cout << "Enter gross pay: $";
    cin >> grossPay;

    cout << "\nChoose one of the following pay periods:\n";
    cout << "BW => BIWEEKLY (Every 2 weeks)\n";
    cout << "SM => SEMINWEEKLY (Twice every month)\n";
    cout << "MN => MONTHLY (Once every month)\n";
    cout << "Enter the abreviation of the Pay Period: ";
    cin >> payPeriod;

    cout << "\nChoose your filing status:\n";
    cout << "SEP => Seperate (Not Joint)\n";
    cout << "JNT => Joint (With someone else)\n";
    cout << "Enter the abbreviation of your filing status: ";
    cin >> filingStatus;
}

// Function that calculates federal income tax based on pay period and filing status
double calculateFIT(double grossPay, string payPeriod, string filingStatus) {
    double fit = 0.0;

    // Example tax table for BIWEEKLY & Joint filing status
    if (payPeriod == "BW" && filingStatus == "JNT") {
        if (grossPay <= 1065) fit = 0;
        else if (grossPay <= 1912) fit = 0 + 0.1 * (grossPay - 1065);
        else if (grossPay <= 4406) fit = 84.7 + 0.12 * (grossPay - 1912);
        // Include any additional tax brackets here
    }

    // Add any other logic for pay periods and filing statuses

    return fit;
}

// Function to calculate social security tax
double calculateSS(double grossPay) {
    return grossPay * 0.062;
}

// Function to calculate medicare tax
double calculateMED(double grossPay) {
    return grossPay * 0.0145;
}

// Display the Pay stub
void displayPayStub(double grossPay, double FIT, double SS, double MED, double netPay) {
    cout << "\nPay Stub\n";
    cout << "=============\n";
    cout << fixed << setprecision(2);
    cout << "Gross Pay: $" << setw(10) << grossPay << endl;
    cout << "Federal:   $" << setw(10) << FIT << endl;
    cout << "SOC SEC:   $" << setw(10) << SS << endl;
    cout << "Medicare:  $" << setw(10) << MED << endl;
    cout << "--------------\n";
    cout << "Net Pay:   $" << setw(10) << netPay << endl;
}
