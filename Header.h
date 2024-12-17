#pragma once
// all the declarations are self explanatory
void displayWelcomeMessage();

void displayInputMenu();

void displayUpdatedMenu(double initialBalance, double monthlyDeposit, double annualInterest, int numYears);

void getInput(double& initialBalance, double& monthlyDeposit, double& annualInterest, int& numYears);

void calculateAndDisplayResults(double initialBalance, double monthlyDeposit, double annualInterest, int numYears);

void resetInputs(double& initialBalance, double& monthlyDeposit, double& annualInterest, int& numYears);