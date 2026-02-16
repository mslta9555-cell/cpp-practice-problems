// ===========================================================
// Problem_41 - Convert Day Number to Day Name
// ===========================================================

#include <iostream>
#include <limits>
#include <cctype>
#include <string>

// -----------------------------------------------------------
// Enum representing days from Saturday to Friday
// -----------------------------------------------------------
enum enDays { Saturday = 1, Sunday, Monday, Tuesday, Wednesday, Thursday, Friday };

// -----------------------------------------------------------
// Configuration constants for minimum and maximum day number
// -----------------------------------------------------------
namespace config {
    constexpr int MIN_DAY_NUMBER = 1;
    constexpr int MAX_DAY_NUMBER = 7;
}

// -----------------------------------------------------------
// Clear the input buffer to handle invalid input safely
// -----------------------------------------------------------
void clearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// -----------------------------------------------------------
// Read a positive number from the user
// -----------------------------------------------------------
int readPositiveNumber(const std::string& prompt)
{
    int value;
    while (true)
    {
        std::cout << prompt;
        std::cin >> value;

        // Check if input failed (e.g., non-numeric input)
        if (std::cin.fail())
        {
            std::cout << "❌ Invalid input! Please enter a number.\n";
            clearInputBuffer();
            continue;
        }

        // Ensure the number is positive
        if (value <= 0)
        {
            std::cout << "❌ Invalid input! Please enter a positive number.\n";
            continue;
        }

        clearInputBuffer();
        return value;
    }
}

// -----------------------------------------------------------
// Read the day number (1 to 7) and validate it
// -----------------------------------------------------------
int ReadDayNumber()
{
    int dayNumber{};
    do {
        dayNumber = readPositiveNumber("Please enter a number between 1 and 7: ");
        if (dayNumber < config::MIN_DAY_NUMBER || dayNumber > config::MAX_DAY_NUMBER)
        {
            std::cout << "❌ Invalid input! Please enter a number between " 
                      << config::MIN_DAY_NUMBER << " and " << config::MAX_DAY_NUMBER << '\n';
        }
    } while (dayNumber < config::MIN_DAY_NUMBER || dayNumber > config::MAX_DAY_NUMBER);
    return dayNumber;
}

// -----------------------------------------------------------
// Convert the day number to its corresponding day name
// -----------------------------------------------------------
std::string GetDayName(const int& dayNumber)
{
    switch (dayNumber)
    {
        case enDays::Saturday: return "Saturday";
        case enDays::Sunday:   return "Sunday";
        case enDays::Monday:   return "Monday";
        case enDays::Tuesday:  return "Tuesday";
        case enDays::Wednesday:return "Wednesday";
        case enDays::Thursday: return "Thursday";
        case enDays::Friday:   return "Friday";
        default: return "Invalid Day";  // Should not happen due to validation
    }
}

// -----------------------------------------------------------
// Print the day name
// -----------------------------------------------------------
void PrintDay(const std::string& dayName)
{
    std::cout << "\n✅ The day is " << dayName << '\n';
}

// -----------------------------------------------------------
// Ask the user if they want to repeat the program
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

        std::cout << "❌ Invalid choice. Please enter 'y' or 'n'.\n";
    }
}

// -----------------------------------------------------------
// Main program loop
// -----------------------------------------------------------
void runProgram()
{
    do
    {
        int dayNumber = ReadDayNumber();          // Read day number from user
        std::string dayName = GetDayName(dayNumber); // Convert number to day name
        PrintDay(dayName);                         // Print the day name
    } while (shouldRepeat());
}

// -----------------------------------------------------------
// Program entry point
// -----------------------------------------------------------
int main()
{
    runProgram();
    std::cout << "\nThanks for using this program.\n";
    return 0;
}
