// Problem_10: Average Calculation with Pass/Fail Status
#include <iostream>
#include <limits>
#include <cctype>
#include <string>
#include <iomanip> 

// -------------------------
// Constants
// -------------------------
constexpr int MIN_NUMBER = 0;          
constexpr int MAX_NUMBER = 100;        
constexpr int NUMBER_OF_GRADES = 3;    
constexpr float PASS_MARK = 50.0f;     

// -------------------------
// Clear invalid input from buffer
// -------------------------
void clearInputLine() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// -------------------------
// Store 3 marks
// -------------------------
struct Marks {
    int firstMark{};
    int secondMark{};
    int thirdMark{};
};

// -------------------------
// Read a number safely within range
// -------------------------
int readNumberInRange(const std::string& prompt)
{
    int number;
    while (true)
    {
        std::cout << prompt;
        std::cin >> number;

        if (std::cin.fail()) { clearInputLine(); std::cout << "❌ Invalid input!\n"; continue; }
        if (number < MIN_NUMBER || number > MAX_NUMBER) { clearInputLine(); std::cout << "❌ Number must be between " << MIN_NUMBER << " and " << MAX_NUMBER << ".\n"; continue; }

        clearInputLine();
        return number;
    }
}

// -------------------------
// Read all 3 marks from user
// -------------------------
Marks readMarks()
{
    Marks marks;
    marks.firstMark = readNumberInRange("Enter first mark: ");
    marks.secondMark = readNumberInRange("Enter second mark: ");
    marks.thirdMark = readNumberInRange("Enter third mark: ");
    return marks;
}

// -------------------------
// Calculate sum of 3 marks
// -------------------------
int calculateSum(const Marks& mark)
{
    return mark.firstMark + mark.secondMark + mark.thirdMark;
}

// -------------------------
// Calculate average of 3 marks
// -------------------------
float calculateAverage(const Marks& mark)
{
    return static_cast<float>(calculateSum(mark)) / NUMBER_OF_GRADES;
}

// -------------------------
// Determine Pass/Fail
// -------------------------
std::string getPassFailStatus(float average)
{
    return (average >= PASS_MARK) ? "✅ PASS" : "❌ FAIL";
}

// -------------------------
// Display marks, average, and status
// -------------------------
void printAverage(const Marks& mark)
{
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\n--- Average Result ---\n";
    std::cout << "Marks: (" << mark.firstMark << ", " << mark.secondMark << ", " << mark.thirdMark << ")\n";

    float avg = calculateAverage(mark);
    std::cout << "✅ Average: " << avg << "\n";
    std::cout << "Status: " << getPassFailStatus(avg) << "\n";
}

// -------------------------
// Ask user if they want to repeat
// -------------------------
bool doYouWantToRepeat()
{
    char answer;
    do
    {
        std::cout << "\n🔁 Calculate another average? (y/n): ";
        std::cin >> answer;
        clearInputLine();

        answer = static_cast<char>(std::tolower(static_cast<unsigned char>(answer)));
        if (answer == 'y') return true;
        if (answer == 'n') return false;
        std::cout << "❌ Enter y or n.\n";
    } while (true);
}

// -------------------------
// Main program loop
// -------------------------
void runProgram()
{
    do
    {
        printAverage(readMarks());
    } while (doYouWantToRepeat());
}

// -------------------------
// Program entry point
// -------------------------
int main()
{
    runProgram();
    std::cout << "\nThanks for using this program 🙏\n";
    return 0;
}
