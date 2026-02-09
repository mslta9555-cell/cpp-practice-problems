// Problem_25 - Print Numbers in Descending Order (Senior-Level Version)

#include <iostream>
#include <limits>
#include <cctype>
#include <string>

// Clears invalid or leftover input from the input buffer
void clearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Reads a validated positive integer from the user
int readPositiveInteger(const std::string& prompt)
{
    int value{};

    while (true)
    {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail())
        {
            std::cout << "❌ Input error. Please enter a numeric value.\n";
        }
        else if (value <= 0)
        {
            std::cout << "❌ Value must be greater than zero.\n";
        }
        else
        {
            clearInputBuffer();
            return value;
        }

        clearInputBuffer();
    }
}

// Core business logic: prints numbers from n down to zero
void printDescendingFrom(int number)
{
    for (int i = number; i >= 0; --i)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}

// Asks the user whether to repeat the program
bool askToRepeat()
{
    char choice{};

    while (true)
    {
        std::cout << "\n🔁 Do you want to repeat the program? (y/n): ";
        std::cin >> choice;
        clearInputBuffer();

        choice = static_cast<char>(std::tolower(static_cast<unsigned char>(choice)));

        if (choice == 'y') return true;
        if (choice == 'n') return false;

        std::cout << "❌ Invalid choice. Please enter y or n.\n";
    }
}

// Orchestrates program flow
void runApplication()
{
    do
    {
        int number = readPositiveInteger("🔢 Please enter a positive number: ");
        printDescendingFrom(number);

    } while (askToRepeat());
}

// Entry point
int main()
{
    runApplication();
    std::cout << "\n🙏 Thanks for using this program!\n";
    return 0;
}
