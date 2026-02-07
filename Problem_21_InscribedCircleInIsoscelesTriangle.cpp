// Problem_21 - Area of a Circle Inscribed in an Isosceles Triangle
#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <cmath>

// Clears invalid input from input buffer
void clearInputLine()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Structure to hold triangle dimensions
struct IsoscelesTriangle
{
    float side{};  // Equal side length
    float base{};  // Base length
};

// Reads a positive number from user with validation
float readPositiveNumber(const std::string& prompt)
{
    float value;

    while (true)
    {
        std::cout << prompt;
        std::cin >> value;

        // Check for invalid input or non-positive numbers
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

// Reads the triangle's sides from the user
IsoscelesTriangle readTriangleData()
{
    return
    {
        readPositiveNumber("Please enter the equal side of the triangle: "),
        readPositiveNumber("Please enter the base of the triangle: ")
    };
}

// Calculates the area of the inscribed circle
float calculateInscribedCircleArea(const IsoscelesTriangle& triangle)
{
    // Validate triangle dimensions
    if (triangle.base >= 2 * triangle.side)
    {
        std::cout << "❌ Error: A triangle with these dimensions cannot exist.\n";
        return 0;
    }

    constexpr float PI = 3.14159265359;

    // Calculate triangle height
    float h = sqrt((triangle.side * triangle.side) - (triangle.base / 2 * triangle.base));
    
    // Radius of inscribed circle
    float r = (triangle.base * h) / (triangle.base + 2 * triangle.side);
    
    // Return area of the circle
    return PI * (r * r);
}

// Prints the result
void printInscribedCircleArea(float area)
{
    std::cout << "\nThe area of the inscribed circle is: " << area << '\n';
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

        std::cout << "❌ Invalid choice. Enter y or n.\n";
    }
}

// Program controller
void runProgram()
{
    do
    {
        IsoscelesTriangle triangleData = readTriangleData(); 
        float area = calculateInscribedCircleArea(triangleData);

        if (area > 0)
        {
            printInscribedCircleArea(area);
        }
        
    } while (shouldRepeat());
}

// Entry point
int main()
{
    runProgram();
    std::cout << "\nThanks for using this program 🙏\n";
    return 0;
}
