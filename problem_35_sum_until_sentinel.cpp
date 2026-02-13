// ===========================================================
// Problem_35 - Sum Until Sentinel Value (Production-Level)
// ===========================================================

#include <iostream>
#include <string>
#include <limits>
#include <cctype>

// ===========================================================
// Configuration
// ===========================================================

namespace Config
{
    constexpr int SENTINEL_VALUE = -99;
}

// ===========================================================
// Utility
// ===========================================================

void clearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// ===========================================================
// Domain Models
// ===========================================================

struct SumResult
{
    long long totalSum{};
};

// ===========================================================
// Input
// ===========================================================

int readInteger(const std::string& prompt)
{
    int value{};

    while (true)
    {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail())
        {
            std::cout << "❌ Invalid input. Please enter a valid integer.\n";
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();
        return value;
    }
}

// ===========================================================
// Business Logic (Pure)
// ===========================================================

SumResult calculateSumUntilSentinel()
{
    SumResult result{};
    int counter = 1;

    std::cout << "Enter numbers to sum. Enter "
              << Config::SENTINEL_VALUE << " to finish.\n\n";

    while (true)
    {
        int value = readInteger("Please enter number " + std::to_string(counter) + ": ");

        if (value == Config::SENTINEL_VALUE)
            break;

        result.totalSum += value;
        ++counter;
    }

    return result;
}

// ===========================================================
// Presentation
// ===========================================================

void printResult(const SumResult& result)
{
    std::cout << "\n✅ The total sum is: " << result.totalSum << "\n";
}

// ===========================================================
// Control Flow
// ===========================================================

bool shouldRepeat()
{
    char choice{};

    while (true)
    {
        std::cout << "\nDo you want to repeat the program? (y/n): ";
        std::cin >> choice;
        clearInputBuffer();

        choice = static_cast<char>(
            std::tolower(static_cast<unsigned char>(choice)));

        if (choice == 'y') return true;
        if (choice == 'n') return false;

        std::cout << "❌ Invalid selection.\n";
    }
}

void runApplication()
{
    do
    {
        SumResult result = calculateSumUntilSentinel();
        printResult(result);

    } while (shouldRepeat());
}

// ===========================================================
// Entry Point
// ===========================================================

int main()
{
    runApplication();
    std::cout << "\n🙏 Thanks for using this program!\n";
    return 0;
}
