// ===========================================================
// Problem_44: Loan Payoff Calculator
// ===========================================================

#include <iostream>
#include <limits>
#include <cctype>
#include <string>
#include <cmath> 

// Standard utility to flush the input buffer and prevent infinite loops
void clearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Domain model representing a financial loan entity
struct Loan
{
    double loanAmount{};
    double monthlyPayment{};
};

// Generic input handler to enforce positive numeric values
double ReadPositiveNumber(const std::string& prompt)
{
    double value;
    while (true)
    {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail() || value <= 0)
        {
            std::cout << "❌ Invalid input! Please enter a positive number.\n";
            clearInputBuffer();
            continue;
        }
        
        clearInputBuffer();
        return value;
    }
}

// Orchestrates the data collection for the Loan object
Loan ReadLoanData()
{
    Loan loan;
    loan.loanAmount = ReadPositiveNumber("Please enter the loan amount: ");
    
    // Ensure monthly payment is non-zero to prevent division errors
    do
    {
        loan.monthlyPayment = ReadPositiveNumber("Please enter the monthly payment amount: ");
        if (loan.monthlyPayment == 0)
        {
            std::cout << "❌ Invalid input! Payment cannot be zero.\n";
        }
    } while (loan.monthlyPayment == 0);

    return loan;
}

// Business logic: Uses ceiling to account for partial final months
double CalculateNumberOfMonths(const Loan& loan)
{
    // Real-world logic: Any remaining balance requires a full extra month
    return std::ceil(loan.loanAmount / loan.monthlyPayment);
}

// Presentation layer for the calculation result
void PrintNumberOfMonths(int numberOfMonths)
{
    std::cout << "\n✅ The number of months to pay off the loan is: " << numberOfMonths << '\n';
}

// Robust yes/no handler for program flow control
bool askUserToRepeat()
{
    while (true)
    {
        std::cout << "\nRepeat program? (y/n): ";
        char input{};
        std::cin >> input;

        if (std::cin.fail())
        {
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();
        
        // Normalize input to lowercase safely
        input = static_cast<char>(std::tolower(static_cast<unsigned char>(input)));

        if (input == 'y') return true;
        if (input == 'n') return false;

        std::cout << "❌ Invalid choice. Please enter 'y' or 'n'.\n";
    }
}

// Main application loop
void runProgram()
{
    do
    {
        Loan loan = ReadLoanData();
        int numberOfMonths = CalculateNumberOfMonths(loan);
        PrintNumberOfMonths(numberOfMonths);
    } while (askUserToRepeat());
}

int main()
{
    runProgram();
    std::cout << "\n🙏 Thanks for using this program.\n";
    return 0;
}
