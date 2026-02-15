// ===========================================================
// Problem_38 - Convert Hours to Weeks, Days, and Hours
// ===========================================================

#include <iostream>
#include <limits>
#include <cctype>
#include <string>

// -----------------------------------------------------------
// Configuration constants (avoid magic numbers)
// -----------------------------------------------------------
namespace config
{
    const int hoursInDay = 24;   // Number of hours in one day
    const int daysInWeek = 7;    // Number of days in one week
}

// -----------------------------------------------------------
// Clears input buffer to handle invalid input safely
// -----------------------------------------------------------
void clearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// -----------------------------------------------------------
// Holds the breakdown of time units
// -----------------------------------------------------------
struct TimeBreakdown
{
    int weeks{};            // Calculated number of weeks
    int days{};             // Remaining days after weeks
    int remainingHours{};   // Remaining hours after days
};

// -----------------------------------------------------------
// Reads a non-negative integer from the user
// -----------------------------------------------------------
int readPositiveNumber(const std::string& prompt)
{
    int value{};
    while (true)
    {
        std::cout << prompt;
        std::cin >> value;

        // Check for invalid input
        if (std::cin.fail())
        {
            std::cout << "❌ Invalid input! Please enter a number.\n";
            clearInputBuffer();
            continue;
        }

        // Ensure the number is non-negative
        if (value < 0)
        {
            std::cout << "❌ Invalid input! Please enter a positive number.\n";
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();
        return value;
    }
}

// -----------------------------------------------------------
// Converts total hours into weeks, days, and remaining hours
// -----------------------------------------------------------
TimeBreakdown calculateTimeBreakdown(int totalHours)
{
    TimeBreakdown result{};

    const int hoursPerWeek = config::hoursInDay * config::daysInWeek;

    result.weeks = totalHours / hoursPerWeek;        // Calculate weeks
    int remaining = totalHours % hoursPerWeek;       // Remaining hours

    result.days = remaining / config::hoursInDay;    // Calculate days
    result.remainingHours = remaining % config::hoursInDay; // Remaining hours

    return result;
}

// -----------------------------------------------------------
// Prints the final calculated results
// -----------------------------------------------------------
void printResults(const TimeBreakdown& data, int totalHours)
{
    std::cout << "\n----------------------------------\n";
    std::cout << "✅ Total Hours: " << totalHours << '\n';
    std::cout << "✅ Equivalent to:\n";
    std::cout << "  - " << data.weeks << " Weeks\n";
    std::cout << "  - " << data.days << " Days\n";
    std::cout << "  - " << data.remainingHours << " Hours\n";
    std::cout << "----------------------------------\n";
}

// -----------------------------------------------------------
// Asks the user if they want to repeat the program
// -----------------------------------------------------------
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

// -----------------------------------------------------------
// Main application flow
// -----------------------------------------------------------
void runApplication()
{
    do
    {
        int totalHours = readPositiveNumber("Please enter the number of hours: ");
        TimeBreakdown breakdown = calculateTimeBreakdown(totalHours);
        printResults(breakdown, totalHours);

    } while (shouldRepeat());
}

// -----------------------------------------------------------
// Program entry point
// -----------------------------------------------------------
int main()
{
    runApplication();
    std::cout << "\nThanks for using this program.\n";
    return 0;
}
