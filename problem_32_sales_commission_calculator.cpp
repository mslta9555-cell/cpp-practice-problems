// ===========================================================
// Problem_32 - Sales Commission Calculator (Senior Refactor)
// ===========================================================

#include <iostream>
#include <limits>
#include <string>
#include <cctype>
#include <iomanip>

// ===========================================================
// 📌 Configuration & Constants
// ===========================================================

namespace CommissionConfig
{
    constexpr int TIER_LOW    = 50'000;
    constexpr int TIER_MEDIUM = 100'000;
    constexpr int TIER_HIGH   = 500'000;
    constexpr int TIER_TOP    = 1'000'000;

    constexpr float RATE_NONE   = 0.00f;
    constexpr float RATE_LOW    = 0.01f;
    constexpr float RATE_MEDIUM = 0.02f;
    constexpr float RATE_HIGH   = 0.03f;
    constexpr float RATE_TOP    = 0.05f;
}

// ===========================================================
// 🧾 Domain Model
// ===========================================================

struct Sales
{
    long long total{};
};

struct CommissionResult
{
    double rate{};
    double amount{};
};

// ===========================================================
// 🔧 Utility Functions
// ===========================================================

void clearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int readNonNegativeInt(const std::string& prompt)
{
    int value{};

    while (true)
    {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail())
        {
            std::cout << "❌ Invalid input! Please enter a valid number\n";
            clearInputBuffer();
            continue;
        }
        if (value < 0)
        { 
            std::cout << "❌ Invalid input! Please enter a non-negative number.\n"; 
            clearInputBuffer(); 
            continue;
        }
        clearInputBuffer();
        return value;
    }
}

// ===========================================================
// 📥 Input Layer
// ===========================================================

Sales readSales()
{
    return { readNonNegativeInt("Please enter total sales: ") };
}

// ===========================================================
// 🧠 Business Logic
// ===========================================================

float determineCommissionRate(int totalSales)
{
    using namespace CommissionConfig;

    if (totalSales >= TIER_TOP)    return RATE_TOP;
    if (totalSales >= TIER_HIGH)   return RATE_HIGH;
    if (totalSales >= TIER_MEDIUM) return RATE_MEDIUM;
    if (totalSales >= TIER_LOW)    return RATE_LOW;

    return RATE_NONE;

}

CommissionResult calculateCommission(const Sales& sales)
{
    CommissionResult result{};
    result.rate   = determineCommissionRate(sales.total);
    result.amount = sales.total * result.rate;
    return result;
}

// ===========================================================
// 🖨️ Presentation Layer
// ===========================================================

void printCommissionReport(const Sales& sales, const CommissionResult& result)
{
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "\n----------------------------------------\n";
    std::cout << "💼 Sales Commission Report\n";
    std::cout << "----------------------------------------\n";
    std::cout << "Total Sales      : $" << sales.total << "\n";
    std::cout << "Commission Rate  : " << result.rate * 100 << "%\n";
    std::cout << "Total Commission : $" << result.amount << "\n";
    std::cout << "----------------------------------------\n";
}

// ===========================================================
// 🔁 Control Flow
// ===========================================================

bool shouldRepeat()
{
    char choice{};

    while (true)
    {
        std::cout << "\nDo you want to repeat the program? (y/n): ";
        std::cin >> choice;
        clearInputBuffer();

        choice = static_cast<char>(std::tolower(static_cast<unsigned char>(choice)));

        if (choice == 'y') return true;
        if (choice == 'n') return false;

        std::cerr << "❌ Invalid selection. Please enter 'y' or 'n'.\n";
    }
}

void runApplication()
{
    do
    {
        Sales sales = readSales();
        CommissionResult result = calculateCommission(sales);
        printCommissionReport(sales, result);

    } while (shouldRepeat());
}

// ===========================================================
// 🚀 Entry Point
// ===========================================================

int main()
{
    runApplication();
    std::cout << "\n🙏 Thanks for using this program!\n";
    return 0;
}
