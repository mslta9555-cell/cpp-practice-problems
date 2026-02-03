// Problem_12: Find the largest number among three positive numbers

#include <iostream>
#include <ios>
#include <cctype>
#include <limits>
#include <string>
#include <algorithm>

// -------------------------
// Clear invalid input from the input buffer
// -------------------------
void ClearInputLine() {
    std::cin.clear();  // Reset fail state
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Remove remaining input
}

// -------------------------
// Struct to store three numbers
// -------------------------
struct Numbers {
    int firstNumber{}, secondNumber{}, ThirdNumber{};  // Store 3 numbers
};

// -------------------------
// Read a positive number with input validation
// -------------------------
int ReadPositiveNumber(const std::string& Prompt) {
    int number;
    while (true) {
        std::cout << Prompt;
        std::cin >> number;

        // Check for invalid input (non-numeric)
        if (std::cin.fail()) {
            std::cout << "❌ Invalid Input! Please enter a valid number.\n";
            ClearInputLine();
            continue;
        }
        // Check if number is positive
        else if (number <= 0) {
            std::cout << "❌ Invalid Input! Please enter a positive number.\n";
            ClearInputLine();
            continue;
        }
        else {
            ClearInputLine();
            return number;
        }
    }
}

// -------------------------
// Read all three numbers from user
// -------------------------
Numbers ReadNumbers() {
    Numbers number;
    number.firstNumber = ReadPositiveNumber("\nPlease enter the first number: ");
    number.secondNumber = ReadPositiveNumber("Please enter the second number: ");
    number.ThirdNumber = ReadPositiveNumber("Please enter the third number: ");
    return number;
}

// -------------------------
// Return the largest number
// -------------------------
int GetBignumber(const Numbers& number) {
    return std::max({ number.firstNumber, number.secondNumber, number.ThirdNumber });
}

// -------------------------
// Print the comparison result
// -------------------------
void PrintResult(const Numbers& number) {
    int BigNumber = GetBignumber(number);

    std::cout << "\n--- Comparison Result ---\n";

    // Check if all numbers are equal
    if (number.firstNumber == number.secondNumber && number.secondNumber == number.ThirdNumber) {
        std::cout << "✅ All three numbers are equal: " << BigNumber << ".\n";
    }
    else {
        std::cout << "✅ The largest number among (" 
                  << number.firstNumber << ", " 
                  << number.secondNumber << ", " 
                  << number.ThirdNumber << ") is: " 
                  << BigNumber << ".\n";
    }
}

// -------------------------
// Ask user if they want to repeat the program
// -------------------------
bool DoYouWantToRepeat() {
    char Answer;
    do {
        std::cout << "\n\n🔁 Do you want to repeat the program? (y/n): ";
        std::cin >> Answer;
        ClearInputLine();

        Answer = static_cast<char>(std::tolower(static_cast<unsigned char>(Answer)));
        if (Answer == 'y') return true;
        if (Answer == 'n') return false;

        std::cout << "❌ Invalid input! Please enter y or n.\n";
    } while (true);
}

// -------------------------
// Main program loop
// -------------------------
void RunProgram() {
    do {
        PrintResult(ReadNumbers());
    } while (DoYouWantToRepeat());
}

// -------------------------
// Program entry point
// -------------------------
int main() {
    RunProgram();
    std::cout << "\n✨ Thanks for using this program! Goodbye! 🙏\n";
    return 0;
}
