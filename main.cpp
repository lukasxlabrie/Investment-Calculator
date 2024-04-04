#include "BankAccount.h"
#include <iostream>
#include <limits>
#include <memory>

// Function to get/validate user input
double getValidatedInput(const std::string& prompt) {
    double value;
    std::cout << prompt;
    // Loop until a valid positive number is entered.
    while (!(std::cin >> value) || value < 0) {
        std::cout << "Invalid input. Please enter a positive numeric value: ";
        std::cin.clear(); // Clears errors
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignores remaining input.
    }
    return value;
}

int main() {
    try {
        std::cout << "Welcome to the Investment Calculator\n";
        // Prompts investment details (from user)
        auto initialInvestment = getValidatedInput("Enter Initial Investment Amount: ");
        auto monthlyDeposit = getValidatedInput("Enter Monthly Deposit Amount: ");
        auto annualInterestRate = getValidatedInput("Enter Annual Interest Rate (percentage): ");
        auto investmentDuration = static_cast<int>(getValidatedInput("Enter Number of Years: "));

        // Creates a BankAccount object with details provided by user
        auto account = std::make_unique<BankAccount>(initialInvestment, monthlyDeposit, annualInterestRate, investmentDuration);

        std::cout << "Calculating... Press Enter to continue.\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); std::cin.get();

        // Calculates and displays investments
        account->calculateGrowthWithoutMonthlyDeposits();
        account->calculateGrowthWithMonthlyDeposits();

        account->displayInvestmentSummary();
    } catch (const std::exception& e) {
        // Catches and reports errors
        std::cerr << "An error occurred: " << e.what() << '\n';
    }

    return 0;
}
