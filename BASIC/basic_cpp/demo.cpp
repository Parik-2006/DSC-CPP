#include <iostream> // Required for input/output operations (cout, cin)
#include <string>   // Required for using the string data type

int main() {
    // Print "Hello, World!" to the console
    std::cout << "Hello, World!" << std::endl; 

    // Declare a string variable to store the user's name
    std::string name;

    // Prompt the user to enter their name
    std::cout << "What is your name? ";
    
    // Read the user's input into the 'name' variable
    std::cin >> name; 

    // Greet the user using their entered name
    std::cout << "Nice to meet you, " << name << "!" << std::endl;

    return 0; // Indicate successful program execution
}