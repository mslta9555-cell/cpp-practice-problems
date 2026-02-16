// Problem_39
// Convert days, hours, minutes, and seconds into total seconds

#include <iostream>
#include <limits>
#include <cctype>
#include <string>

// Configuration constants to avoid magic numbers
namespace config
{
    constexpr long long HOURS_PER_DAY = 24;
    constexpr long long MINUTES_PER_HOUR = 60;
    constexpr long long SECONDS_PER_MINUTE = 60;
}

// Clears input buffer after invalid input
void clearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Holds time values entered by the user
struct TimeData
{
    long long days{};
    long long hours{};
    long long minutes{};
    long long seconds{};
};

// Reads a positive number with validation
int readPositiveNumber(const std::string& prompt)
{
    int value{};
    while (true)
    {
        std::cout << prompt;
        std::cin >> value;

        // Validate input
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

// Reads all time data from the user
TimeData ReadData()
{
    return
    {
        readPositiveNumber("Please enter number of days: "),
        readPositiveNumber("Please enter number of hours: "),
        readPositiveNumber("Please enter number of minutes: "),
        readPositiveNumber("Please enter number of seconds: ")
    };
}

// Converts all time units into total seconds
long long CalculateTotalSeconds(const TimeData& data)
{
    return data.days * config::HOURS_PER_DAY
                     * config::MINUTES_PER_HOUR
                     * config::SECONDS_PER_MINUTE
         + data.hours * config::MINUTES_PER_HOUR
                      * config::SECONDS_PER_MINUTE
         + data.minutes * config::SECONDS_PER_MINUTE
         + data.seconds;
}

// Prints the total seconds result
void PrintTotalSeconds(long long totalSeconds)
{
    std::cout << "\n✅ The total seconds is: " << totalSeconds << '\n';
}

// Asks the user if they want to repeat the program
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

// Main program loop
void runProgram()
{
    do
    {
        TimeData data = ReadData();
        long long totalSeconds = CalculateTotalSeconds(data);
        PrintTotalSeconds(totalSeconds);

    } while (shouldRepeat());
}

// Program entry point
int main()
{
    runProgram();
    std::cout << "\nThanks for using this program.\n";
    return 0;
}
