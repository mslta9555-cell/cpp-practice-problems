// Problem_9
// ------------------------------------------
// This program reads three marks from the user,
// validates them (0–100), calculates the average,
// and allows repeating the process.
// ------------------------------------------

#include <iostream>
#include <cctype>
#include <limits>
#include <string>
#include <iomanip> 

// Constants for validation and calculation
constexpr int MIN_NUMBER = 0; 
constexpr int MAX_NUMBER = 100;
constexpr int NUMBER_OF_GRADES = 3;

// Clears the input buffer to avoid invalid input issues
void clearInputLine() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Structure to store three marks
struct Marks {
    int firstMark = 0;
    int secondMark = 0;
    int thirdMark = 0;
};

// Reads a number from the user within a valid range
int readNumberInRange(const std::string& prompt)
{
    int number;
    while (true)
    {
        std::cout << prompt;
        std::cin >> number;

        // Check for non-numeric input
        if (std::cin.fail())
        {
            std::cout << "❌ Invalid Input! Please enter a valid number.\n";
            clearInputLine();
            continue;
        }

        // Check if number is outside allowed range
        if (number < MIN_NUMBER || number > MAX_NUMBER)
        {
            std::cout << "Invalid input. Please enter a number between ("
                      << MIN_NUMBER << " and " << MAX_NUMBER << ")\n";
            clearInputLine();
            continue;
        }

        clearInputLine();
        return number;
    }
}

// Reads all three marks from the user
Marks readMarks()
{
    Marks marks;
    marks.firstMark  = readNumberInRange("\nPlease enter the first mark: ");
    marks.secondMark = readNumberInRange("Please enter the second mark: ");
    marks.thirdMark  = readNumberInRange("Please enter the third mark: ");
    return marks;
}

// Calculates the sum of the marks
int calculateSum(const Marks& mark)
{
    return mark.firstMark + mark.secondMark + mark.thirdMark;
}

// Calculates the average of the marks
float calculateAverage(const Marks& mark)
{
    return static_cast<float>(calculateSum(mark)) / NUMBER_OF_GRADES;
}

// Prints the marks and their average
void printAverage(const Marks& mark)
{
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\n--- Average Result ---\n";
    std::cout << "Marks: (" << mark.firstMark << ", "
              << mark.secondMark << ", "
              << mark.thirdMark << ")\n";
    std::cout << "✅ The Average is: " << calculateAverage(mark) << "\n";
}

// Asks the user if they want to repeat the program
bool doYouWantToRepeat()
{
    char answer;
    do
    {
        std::cout << "\n🔁 Do you want to calculate another average? (y/n): ";
        std::cin >> answer;
        clearInputLine();

        answer = static_cast<char>(std::tolower(static_cast<unsigned char>(answer)));

        if (answer == 'y') return true;
        if (answer == 'n') return false;

        std::cout << "❌ Invalid input! Please enter y or n.\n";
    } while (true);
}

// Controls the overall flow of the program
void runProgram()
{
    do
    {
        std::cout << "\n--- 🧮 Average Calculation Program ---\n";
        printAverage(readMarks());
    } while (doYouWantToRepeat());
}

// Program entry point
int main()
{
    runProgram();
    std::cout << "\nThanks for using this program 🙏\n";
    return 0;
}
