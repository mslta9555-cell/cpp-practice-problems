// Problem_19 - Area of a Circle Inscribed in a Square
// Production-Ready Version

#include <iostream>
#include <limits>
#include <string>
#include <cmath>

// Clears invalid input from the input buffer
void clearInputLine()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Represents a square
struct Square
{
    float sideLength{};
};

// Reads a validated positive number from the user
float readPositiveNumber(const std::string& prompt)
{
    float value{};

    while (true)
    {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail() || value <= 0)
        {
            std::cout << "❌ Please enter a valid positive number.\n";
            clearInputLine();
            continue;
        }

        clearInputLine();
        return value;
    }
}

// Reads square dimensions
Square readSquare()
{
    return { readPositiveNumber("Please enter the square's side length: ") };
}

// Calculates the area of a circle inscribed in a square
float calculateInscribedCircleArea(const Square& square)
{
    constexpr float PI = 3.14159265359f;
    float diameter = square.sideLength;

    return (PI * diameter * diameter) / 4.0f;
}

// Displays the result
void printArea(float area)
{
    std::cout << "\n✅ The area of the inscribed circle is: "
              << area << " units²\n";
}

// Asks the user if they want to repeat the program
bool shouldRepeat()
{
    char choice{};

    while (true)
    {
        std::cout << "\n🔁 Do you want to repeat the program? (y/n): ";
        std::cin >> choice;
        clearInputLine();

        choice = static_cast<char>(std::tolower(static_cast<unsigned char>(choice)));

        if (choice == 'y') return true;
        if (choice == 'n') return false;

        std::cout << "❌ Invalid choice. Please enter y or n.\n";
    }
}

// Controls program execution
void runProgram()
{
    do
    {
        Square square = readSquare();
        float area = calculateInscribedCircleArea(square);
        printArea(area);

    } while (shouldRepeat());
}

// Program entry point
int main()
{
    runProgram();
    std::cout << "\nThanks for using this program 🙏\n";
    return 0;
}
