// ===========================================================
// Problem_43: Configurable Alphabet Printer
// Purpose: Prints a range of characters with robust validation.
// ===========================================================

#include <iostream>
#include <limits>
#include <cctype>

// Application settings for easy maintenance
namespace config
{
    constexpr char FIRST = 'A';
    constexpr char LAST  = 'Z';
}

// Resets the input stream to prevent infinite loops on invalid input
void clearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Logic to iterate and display the defined character range
void printAlphabet()
{
    // Note: Using constants ensures UI stays synced with config
    std::cout << "\n✅ The English alphabet from " << config::FIRST << " to " << config::LAST << ":\n";

    for (char letter = config::FIRST; letter <= config::LAST; ++letter)
    {
        std::cout << letter << ' ';
    }

    std::cout << '\n';
}

// Handles user interaction for repeating the program flow
bool askToRepeat()
{
    while (true)
    {
        std::cout << "\nRepeat program? (y/n): ";

        char choice{};
        std::cin >> choice;

        // Check if the input was a valid character
        if (std::cin.fail())
        {
            clearInputBuffer();
            std::cout << "❌ Invalid input. Please enter a character.\n";
            continue;
        }

        clearInputBuffer();

        // Convert input to lowercase safely to support 'Y' and 'y'
        choice = static_cast<char>(
            std::tolower(static_cast<unsigned char>(choice))
        );

        if (choice == 'y') return true;
        if (choice == 'n') return false;

        std::cout << "❌ Invalid choice. Please enter 'y' or 'n'.\n";
    }
}

// Orchestrates the high-level program execution
void runProgram()
{
    do
    {
        printAlphabet();
    }
    while (askToRepeat());
}

// Program Entry Point
int main()
{
    runProgram();

    std::cout << "\n🙏 Thanks for using this program.\n";
    return 0;
}
