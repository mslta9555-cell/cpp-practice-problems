// ===========================================================
// Problem_46: Secure Password Access Program
// Purpose: Requests password from user, validates it, and displays balance.
// ===========================================================

#include <iostream>
#include <limits>
#include <string>
#include <cctype>

namespace config
{
    constexpr char correctPassword[] = "1234"; // Use string for flexibility
    constexpr int kBalance = 7000;
    constexpr int kMaxAttempts = 3; // Maximum password attempts
}

// Utility to clear the input buffer
void clearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Generic function to read integer inputs safely
int ReadInteger(const std::string& prompt)
{
    int value{};
    while (true)
    {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail())
        {
            std::cout << "❌ Invalid input! Please enter a number.\n";
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();
        return value;
    }
}

// Function to read the correct password with limited attempts
bool ReadCorrectPassword()
{
    std::string input;
    int attempts = 0;

    while (attempts < config::kMaxAttempts)
    {
        std::cout << "Please enter the correct password: ";
        std::cin >> input;
        clearInputBuffer();

        if (input == config::correctPassword)
        {
            std::cout << "\n✅ Correct Password. Access granted!\n";
            std::cout << "Your balance is: " << config::kBalance << "\n";
            return true;
        }

        attempts++;
        std::cout << "❌ Invalid password! Attempts left: " 
                  << (config::kMaxAttempts - attempts) << "\n";
    }

    std::cout << "\n⚠️ Maximum attempts reached. Access denied.\n";
    return false;
}

// Ask user whether to repeat program
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
        input = static_cast<char>(std::tolower(static_cast<unsigned char>(input)));

        if (input == 'y') return true;
        if (input == 'n') return false;

        std::cout << "❌ Invalid choice. Please enter 'y' or 'n'.\n";
    }
}

// Main program flow
void runProgram()
{
    do
    {
        ReadCorrectPassword();
    } while (askUserToRepeat());
}

// Entry point
int main()
{
    runProgram();
    std::cout << "\n🙏 Thanks for using this program.\n";
    return 0;
}
