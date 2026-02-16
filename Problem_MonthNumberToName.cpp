// Problem_42
// Program that reads a month number (1–12) and prints the corresponding month name

#include <iostream>
#include <limits>
#include <cctype>
#include <string>

// Configuration values for valid month range
namespace config
{
    constexpr int MIN_MONTH = 1;
    constexpr int MAX_MONTH = 12;
}

// Enum representing months of the year
enum Month {
    January = 1, February, March,
    April, May, June, July,
    August, September, October,
    November, December
};

// Clears the input buffer to handle invalid input safely
void clearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Reads a valid month number from the user (1 to 12)
int readMonthNumber()
{
    int month{};

    while (true)
    {
        std::cout << "Please enter a number between 1 and 12: ";
        std::cin >> month;

        // Check for invalid input or out-of-range value
        if (std::cin.fail() || month < config::MIN_MONTH || month > config::MAX_MONTH)
        {
           std::cout << "❌ Invalid input. Please enter a number between 1 and 12.\n";
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();
        return month;
    }
}

// Returns the month name based on the month number
std::string getMonthName(const int MonthNumber)
{
    switch (MonthNumber)
    {
        case Month::January:   return "January";
        case Month::February:  return "February";
        case Month::March:     return "March";
        case Month::April:     return "April";
        case Month::May:       return "May";
        case Month::June:      return "June";
        case Month::July:      return "July";
        case Month::August:    return "August";
        case Month::September: return "September";
        case Month::October:   return "October";
        case Month::November:  return "November";
        case Month::December:  return "December";
        default:               return "Invalid Input";
    }
}

// Prints the month name
void printMonth(const std::string& Month)
{
    std::cout << "\n✅ The Month is " << Month << '\n';
}

// Asks the user whether to repeat the program
bool shouldRepeat()
{
    char choice{};
    while (true)
    {
        std::cout << "\nRepeat program? (y/n): ";
        std::cin >> choice;
        clearInputBuffer();

        // Convert input to lowercase for consistency
        choice = static_cast<char>(std::tolower(static_cast<unsigned char>(choice)));

        if (choice == 'y') return true;
        if (choice == 'n') return false;

        std::cout << "❌ Invalid choice. Please enter 'y' or 'n'.\n";
    }
}

// Main program loop
void runProgram()
{
    do
    {
        int monthName = readMonthNumber();
        std::string Month = getMonthName(monthName);
        printMonth(Month);

    } while (shouldRepeat());
}

int main()
{
    runProgram();
    std::cout << "\nThanks for using this program.\n";
    return 0;
}
