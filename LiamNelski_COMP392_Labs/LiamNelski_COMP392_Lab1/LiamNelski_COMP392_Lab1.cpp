// LiamNelski_COMP_123_Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>


bool tryParse(std::string& input, int& output) {
    try {
        output = std::stoi(input);
    }
    catch (std::invalid_argument) {
        return false;
    }
    return true;
}

int main()
{
    std::cout << "What is your name?\n";
    std::string name;
    getline(std::cin, name);

    std::cout << "What is your Salary?\n";    
    std::string input;
    int salary;

    getline(std::cin, input);

    while (!tryParse(input, salary))
    {
        std::cout << "You must enter in a number\n";
        getline(std::cin, input);
    }

    std::cout << "Hello, " << name << ", Your salary is: " << salary;

}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
