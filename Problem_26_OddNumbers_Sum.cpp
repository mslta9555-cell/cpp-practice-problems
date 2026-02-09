// Problem_26 - Print Odd Numbers up to N and their Sum

#include <iostream>
#include <limits>
#include <string>
#include <cctype>

// ✅ Clears the input buffer to handle invalid or leftover input
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// ✅ Struct to hold the user-entered number
struct NumberInfo {
    int value = 0;
};

// ✅ Reads a validated positive integer from the user
int readPositiveNumber(const std::string& prompt) {
    int number = 0;

    while (true) {
        std::cout << prompt;
        std::cin >> number;

        // Check for invalid/non-numeric input
        if (std::cin.fail()) {
            std::cout << "❌ Invalid input! Please enter a valid number.\n";
            clearInputBuffer();
            continue;
        }

        // Check for non-positive numbers
        if (number <= 0) {
            std::cout << "❌ Invalid input! Please enter a number greater than 0.\n";
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();
        return number;
    }
}

// ✅ Checks if a number is odd
bool isOdd(int number) {
    return number % 2 != 0;
}

// ✅ Prints all odd numbers less than the entered number and calculates their sum
void printOddNumbers(const NumberInfo& num) {
    std::cout << "\n--- Odd Numbers up to " << num.value << " ---\n";
    int sum = 0;

    for (int i = 1; i < num.value; ++i) {
        if (isOdd(i)) {
            std::cout << i << " ";  // Print odd number
            sum += i;               // Add to sum
        }
    }

    std::cout << "\n✅ Sum of odd numbers: " << sum << "\n";
}

// ✅ Asks the user if they want to repeat the program
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

// ✅ Main program loop
void runProgram() {
    do {
        NumberInfo num{ readPositiveNumber("🔢 Please enter a number: ") };
        printOddNumbers(num);
    } while (askToRepeat());
}

// ✅ Program entry point
int main() {
    runProgram();
    std::cout << "\n🙏 Thanks for using this program!\n";
    return 0;
}
