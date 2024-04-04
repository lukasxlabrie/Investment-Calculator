#ifndef BANK_ACCOUNT_H_
#define BANK_ACCOUNT_H_

#include <vector>
#include <memory>

// Defines a BankAccount for tracking investment growth over time.
class BankAccount {
public:
    // Initializes a new BankAccount instance.
    BankAccount(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterestRate, int t_investmentDuration);
    void calculateGrowthWithoutMonthlyDeposits();
    void calculateGrowthWithMonthlyDeposits();
    void displayInvestmentSummary() const;

private:
    // Calculates monthly interest; used by growth calculation methods.
    double calculateMonthlyInterest(double t_balance, double t_monthlyDeposit = 0.0) const;

    double m_initialInvestment;
    double m_monthlyDeposit; 
    double m_annualInterestRate;
    int m_investmentDuration; // in years
    std::vector<std::pair<double, double>> m_growthWithoutDeposits; // Stores growth data without deposits.
    std::vector<std::pair<double, double>> m_growthWithDeposits; // Stores growth data with deposits.
};

#endif // BANK_ACCOUNT_H_
