// ===========================================================
// Problem_40 - Convert Total Seconds to Time Units
// Production-Level Refactor
// ===========================================================

#include <iostream>
#include <limits>
#include <cctype>
#include <string>

// ===========================================================
// Configuration (Centralized constants)
// ===========================================================
namespace config
{
    constexpr long long SECONDS_PER_MINUTE = 60;
    constexpr long long SECONDS_PER_HOUR   = 60 * SECONDS_PER_MINUTE;
    constexpr long long SECONDS_PER_DAY    = 24 * SECONDS_PER_HOUR;
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
struct TotalSeconds
{
    long long value{};
};

struct TimeBreakdown
{
    long long days{};
    long long hours{};
    long long minutes{};
    long long seconds{};
};

// ===========================================================
// Input Layer
// ===========================================================
long long readPositiveNumber(const std::string& prompt)
{
    long long value{};

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

TotalSeconds readTotalSeconds()
{
    return { readPositiveNumber("Please enter total seconds: ") };
}

// ===========================================================
// Business Logic (Pure Function)
// ===========================================================
TimeBreakdown convertSecondsToTime(const TotalSeconds& input)
{
    TimeBreakdown result{};
    long long remaining = input.value;

    result.days = remaining / config::SECONDS_PER_DAY;
    remaining %= config::SECONDS_PER_DAY;

    result.hours = remaining / config::SECONDS_PER_HOUR;
    remaining %= config::SECONDS_PER_HOUR;

    result.minutes = remaining / config::SECONDS_PER_MINUTE;
    remaining %= config::SECONDS_PER_MINUTE;

    result.seconds = remaining;

    return result;
}

// ===========================================================
// Presentation Layer
// ===========================================================
void printTimeBreakdown(const TimeBreakdown& data)
{
    std::cout << "\n========================================\n";
    std::cout << "⏱️  Time Conversion Result\n";
    std::cout << "========================================\n";
    std::cout << "Days     : " << data.days << '\n';
    std::cout << "Hours    : " << data.hours << '\n';
    std::cout << "Minutes  : " << data.minutes << '\n';
    std::cout << "Seconds  : " << data.seconds << '\n';
    std::cout << "========================================\n";
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

        std::cout << "❌ Invalid choice. Please enter 'y' or 'n'.\n";
    }
}

void runApplication()
{
    do
    {
        TotalSeconds input = readTotalSeconds();
        TimeBreakdown result = convertSecondsToTime(input);
        printTimeBreakdown(result);

    } while (shouldRepeat());
}

// ===========================================================
// Entry Point
// ===========================================================
int main()
{
    runApplication();
    std::cout << "\n🙏 Thanks for using the Time Converter!\n";
    return 0;
}
