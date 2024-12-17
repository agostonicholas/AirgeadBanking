#include "Header.h"
//   Nicholas Agosto
//   11/29/2024
int main()
{
    double initialBalance, monthlyDeposit, annualInterest;
    int numYears;

    // display welcome
    displayWelcomeMessage();

    // user inputs
    getInput(initialBalance, monthlyDeposit, annualInterest, numYears);

    // calculations and display results
    calculateAndDisplayResults(initialBalance, monthlyDeposit, annualInterest, numYears);

    return 0;
}