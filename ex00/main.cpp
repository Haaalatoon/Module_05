#include "Bureaucrat.hpp"

int main()
{
    // Test valid construction
    try {
        Bureaucrat bob("Bob", 75);
        std::cout << bob << std::endl;
        bob.incrementGrade();
        std::cout << "After increment: " << bob << std::endl;
        bob.decrementGrade();
        bob.decrementGrade();
        std::cout << "After 2 decrements: " << bob << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test grade too high
    try {
        Bureaucrat bad("Bad", 0);
    } catch (std::exception &e) {
        std::cout << "Expected: " << e.what() << std::endl;
    }

    // Test grade too low
    try {
        Bureaucrat bad("Bad", 151);
    } catch (std::exception &e) {
        std::cout << "Expected: " << e.what() << std::endl;
    }

    // Test increment at boundary
    try {
        Bureaucrat top("Top", 1);
        top.incrementGrade();
    } catch (std::exception &e) {
        std::cout << "Expected: " << e.what() << std::endl;
    }

    // Test decrement at lower boundary (grade 150)
    try {
        Bureaucrat bottom("Bottom", 150);
        bottom.decrementGrade();
    } catch (std::exception &e) {
        std::cout << "Expected: " << e.what() << std::endl;
    }

    return 0;
}