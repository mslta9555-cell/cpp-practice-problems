// ===========================================================
// Problem_37 
// ===========================================================

#include <iostream>
#include <limits>
#include <string>
#include <cctype>
#include <iomanip>

// ===========================================================
// Configuration
// ===========================================================
namespace config
{
    constexpr double SERVICE_FEE_RATE = 0.10; // 10%
    constexpr double SALES_TAX_RATE   = 0.06; // 6%
}

// ===========================================================
// Domain Models
// ===========================================================
struct BillInput
{
    double invoiceAmount{};
};

struct BillBreakdown
{
    double baseAmount{};
    double serviceFee{};
    double salesTax{};
    double total{};
};

// ===========================================================
// Utility
// ===========================================================
void clearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// ===========================================================
// Input Layer
// ===========================================================
double readPositiveAmount(const std::string& prompt)
{
    double value{};

    while (true)
    {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail() || value <= 0)
        {
            std::cout << "❌ Invalid input. Please enter a positive number.\n";
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();
        return value;
    }
}

BillInput readBillInput()
{
    return { readPositiveAmount("💰 Enter invoice amount: ") };
}

// ===========================================================
// Business Logic (Pure & Testable)
// ===========================================================
BillBreakdown calculateBill(const BillInput& input)
{
    BillBreakdown result{};
    result.baseAmount = input.invoiceAmount;
    result.serviceFee = input.invoiceAmount * config::SERVICE_FEE_RATE;
    result.salesTax   = input.invoiceAmount * config::SALES_TAX_RATE;
    result.total      = result.baseAmount + result.serviceFee + result.salesTax;
    return result;
}

// ===========================================================
// Presentation Layer
// ===========================================================
void printBill(const BillBreakdown& bill)
{
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\n==================================\n";
    std::cout << "           🧾 BILL SUMMARY         \n";
    std::cout << "==================================\n";
    std::cout << "Base Amount:       $" << bill.baseAmount << "\n";
    std::cout << "Service Fee (10%): $" << bill.serviceFee << "\n";
    std::cout << "Sales Tax (6%):    $" << bill.salesTax << "\n";
    std::cout << "----------------------------------\n";
    std::cout << "TOTAL:             $" << bill.total << "\n";
    std::cout << "==================================\n";
}

// ===========================================================
// Control Flow
// ===========================================================
bool shouldRepeat()
{
    char choice{};

    while (true)
    {
        std::cout << "\nRepeat program? (y/n): ";
        std::cin >> choice;
        clearInputBuffer();

        choice = static_cast<char>(std::tolower(static_cast<unsigned char>(choice)));
        if (choice == 'y') return true;
        if (choice == 'n') return false;

        std::cout << "❌ Please enter 'y' or 'n'.\n";
    }
}

void runApplication()
{
    do
    {
        BillInput input = readBillInput();
        BillBreakdown bill = calculateBill(input);
        printBill(bill);

    } while (shouldRepeat());
}

// ===========================================================
// Entry Point
// ===========================================================
int main()
{
    runApplication();
    std::cout << "\n🙏 Thanks for using the Billing System!\n";
    return 0;
}
