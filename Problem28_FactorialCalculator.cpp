//Problem_28
#include <iostream>
#include <limits>
#include <string>
#include <cctype>

// ✅ Clears the input buffer safely
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// ✅ Struct for holding user number
struct NumberInfo {
    int value{};
};

// ✅ Reads a positive integer (1–20) from the user
int readPositiveNumber(const std::string& prompt) {
    int number = 0;

    while (true) {
        std::cout << prompt;
        std::cin >> number;

        if (std::cin.fail()) {
            std::cout << "❌ Invalid input! Please enter a valid number.\n";
            clearInputBuffer();
            continue;
        }

        if (number <= 0 || number > 20) {
            std::cout << "❌ Invalid input! Please enter a number between 1 and 20.\n";
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();
        return number;
    }
}

// ✅ Calculates factorial safely
unsigned long long calculateFactorial(const NumberInfo& number) {
    unsigned long long factorial = 1;
    for (int i = number.value; i > 0; --i)
        factorial *= i;
    return factorial;
}

// ✅ Prints factorial steps for clarity
void printFactorialSteps(const NumberInfo& number, unsigned long long factorial) {
    std::cout << "\n🧮 Calculation: ";
    for (int i = number.value; i > 0; --i) {
        std::cout << i;
        if (i > 1) std::cout << " x ";
    }
    std::cout << " = " << factorial << std::endl;
}

// ✅ Asks the user if they want to repeat
bool askToRepeat()
{
    char choice{};
    while (true)
    {
        std::cout << "\n🔁 Do you want to repeat the program? (y/n): ";
        std::cin >> choice;
        clearInputBuffer();

        choice = static_cast<char>(std::tolower(static_cast<unsigned char>(choice)));

        if (choice == 'y') return true;  // Repeat program
        if (choice == 'n') return false; // Exit program

        std::cout << "❌ Invalid choice. Please enter y or n.\n";
    }
}

// ✅ Core program logic
void runProgram() {
    do {
        NumberInfo number{ readPositiveNumber("🔢 Please enter a number (max 20): ") };
        unsigned long long factorial = calculateFactorial(number);
        printFactorialSteps(number, factorial);
    } while (askToRepeat());
}

// ✅ Entry point
int main() {
    runProgram();
    std::cout << "\n🙏 Thanks for using this program!\n";
    return 0;
}
