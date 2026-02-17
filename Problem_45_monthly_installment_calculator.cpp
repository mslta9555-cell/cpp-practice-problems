// ===========================================================
// Problem_45: Monthly Installment Calculator
// Purpose: Computes fixed monthly payments for a given loan.
// ===========================================================

#include <iostream>
#include <limits>
#include <cctype>
#include <string>

// Entity representing the core data for a loan
struct Loan
{
    double loanAmount{};
    double NumberOfMonths{};
};

// Utility to clean the input stream and handle errors gracefully
void clearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Reusable function to ensure the user enters a numeric value > 0
double ReadPositiveNumber(const std::string& prompt)
{
    double value;
    while (true)
    {
        std::cout << prompt;
        std::cin >> value;

        // Check for non-numeric input or zero/negative values
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

// Data collection layer using modern brace initialization
Loan ReadLoanAndMonthlyPayment()
{
    return
    {
        ReadPositiveNumber("\nPlease enter the loan amount : "),
        ReadPositiveNumber("Please enter Number Of Month : ")
    };
}

// Pure business logic: Passed by const reference for performance
double CalculateMonthlyInstallment(const Loan& Lone)
{
    return Lone.loanAmount / Lone.NumberOfMonths;
}

// Output layer to present the final result to the user
void PrintMonthlyInstallment(double MonthlyInstallment)
{
    std::cout << "\nThe Monthly Installment is : " << MonthlyInstallment << '\n';
}

// Loop control to allow the user to perform multiple calculations
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
        
        // Normalize input for flexible user interaction ('Y' or 'y')
        input = static_cast<char>(std::tolower(static_cast<unsigned char>(input)));

        if (input == 'y') return true;
        if (input == 'n') return false;

        std::cout << "❌ Invalid choice. Please enter 'y' or 'n'.\n";
    }
}

// Orchestrates the main flow of the application
void runProgram()
{
    do
    {
        Loan Lone = ReadLoanAndMonthlyPayment();
        double MonthlyInstallment = CalculateMonthlyInstallment(Lone);
        PrintMonthlyInstallment(MonthlyInstallment);   
    } while (askUserToRepeat());
}

// Main Entry Point
int main()
{
    runProgram();
    std::cout << "\n🙏 Thanks for using this program.\n";
    return 0;
}
