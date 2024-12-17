#include "Header.h" //reference to header
#include <iostream> //input/output
#include <iomanip> //formatting
#include <limits> //clearing

void displayWelcomeMessage() {
    std::cout << "***********************************" << std::endl;
    std::cout << "**********   Welcome!   ***********" << std::endl;
    std::cout << "***********************************" << std::endl;
}

void displayInputMenu() {
    std::cout << "***********************************" << std::endl;
    std::cout << "**********   Data Input   *********" << std::endl;
    std::cout << "***********************************" << std::endl;
    std::cout << "Initial Investment Amount: " << std::endl;
    std::cout << "Monthly Deposit: " << std::endl;
    std::cout << "Annual Interest: " << std::endl;
    std::cout << "Number of years: " << std::endl;
}

void displayUpdatedMenu(double initialBalance, double monthlyDeposit, double annualInterest, int numYears)
{
    //stores the user input in an updated menu
    std::cout << "\n***********************************" << std::endl;
    std::cout << "**********   Data Input   *********" << std::endl;
    std::cout << "***********************************" << std::endl;
    std::cout << "Initial Investment Amount: $" << std::fixed << std::setprecision(2) << initialBalance << std::endl;
    std::cout << "Monthly Deposit: $" << std::fixed << std::setprecision(2) << monthlyDeposit << std::endl;
    std::cout << "Annual Interest: " << std::fixed << std::setprecision(2) << annualInterest << "%" << std::endl;
    std::cout << "Number of years: " << numYears << std::endl;
}

void getInput(double& initialBalance, double& monthlyDeposit, double& annualInterest, int& numYears) {
    // input from user
    std::cout << "Initial Investment Amount: $";
    std::cin >> initialBalance;

    std::cout << "Monthly Deposit: $";
    std::cin >> monthlyDeposit;

    std::cout << "Annual Interest: %";
    std::cin >> annualInterest;

    std::cout << "Number of years: ";
    std::cin >> numYears;

    // clear
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // display updated menu
    displayUpdatedMenu(initialBalance, monthlyDeposit, annualInterest, numYears);

    std::cout << "\nPress any key to continue . . . ";
    std::cin.get();
}

void calculateAndDisplayResults(double initialBalance, double monthlyDeposit, double annualInterest, int numYears)
{
    double balance = initialBalance;

    std::cout << "\nYear\tYear-End Balance\tYearly Interest Earned\n";
    std::cout << "------------------------------------------------\n";
    // years
    for (int year = 1; year <= numYears; ++year) {
        double yearlyInterest = 0.0;
        // calculations/month
        for (int month = 1; month <= 12; ++month) {
            double monthlyInterest = (balance + monthlyDeposit) * (annualInterest / 100) / 12;
            yearlyInterest += monthlyInterest;
            balance += monthlyDeposit + monthlyInterest;
        }

        // display the results
        std::cout << year << "\t$" << std::fixed << std::setprecision(2) << balance
            << "\t\t$" << yearlyInterest << "\n";
    }

    std::cout << "------------------------------------------------\n";
    
    //take new inputs
    
    char resetOption;
    std::cout << "\nWould you like to reset the inputs and start again? (y/n): ";
    std::cin >> resetOption;

    if (resetOption == 'y' || resetOption == 'Y') {
        // Reset inputs and restart the process
        resetInputs(initialBalance, monthlyDeposit, annualInterest, numYears);
        getInput(initialBalance, monthlyDeposit, annualInterest, numYears);
        calculateAndDisplayResults(initialBalance, monthlyDeposit, annualInterest, numYears);
    } else {
        std::cout << "\nThank you!" << std::endl;
        std::cout << "Press any key to exit . . . ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }
}

void resetInputs(double& initialBalance, double& monthlyDeposit, double& annualInterest, int& numYears)
{
    initialBalance = 0.0;
    monthlyDeposit = 0.0;
    annualInterest = 0.0;
    numYears = 0;

}