#include <iostream>
#include <string>
#include <cctype> 
#include <limits> 
#include <ios>    

void clearInputLine()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int ReadPositiveNumber()
{
    int number = 0;
    while (true)
    {
        std::cout << "\nPlease enter a positive number: ";
        std::cin >> number;

        if (std::cin.fail())
        {
            std::cout << "\n❌ Invalid Input! Please enter a number.\n";
            clearInputLine();
        }
        else if (number <= 0)
        {
            std::cout << "\n❌ Invalid Input! Please enter a positive number (greater than 0).\n";
            clearInputLine();
        }
        else
        {
           clearInputLine();
            return number;
        }
    }
}

bool isEven(int number)
{
    return number % 2 == 0;
}

void PrintResult(int number)
{
    if (isEven(number))
    {
        std::cout << "The Number " << number << " is even" << std::endl;
    }
    else
    {
        std::cout << "The Number " << number << " Is odd" << std::endl;
    }
}

bool DoYouWantToRepeat()
{
    char answer;
    do
    {
        std::cout << "\n🔁 Do you want to repeat the program? (y/n): ";
        std::cin >> answer;
        clearInputLine();

       answer = static_cast<char>(std::tolower(static_cast<unsigned char>(answer)));

        if (answer == 'y') return true;
        if (answer == 'n') return false;

        std::cout << "❌ Invalid input! Please enter y or n.\n";
    } while (true);
}

void RunProgram()
{
    do
    {
        
        int Number = ReadPositiveNumber();
        
        PrintResult(Number);

    } while (DoYouWantToRepeat()); 
}

int main()
{
    RunProgram();
    std::cout << "\nThanks for using this program\n";
    return 0;
}
