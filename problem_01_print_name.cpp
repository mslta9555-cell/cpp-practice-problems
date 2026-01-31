#include <iostream>
#include <string>

// Prints the user's name to the console
void PrintName(const std::string& name)
{
    std::cout << "Your name is: " << name << '\n';
}

int main()
{
    std::string name = "Mostafa Sultan Hassan";
    PrintName(name);
    return 0;
}
