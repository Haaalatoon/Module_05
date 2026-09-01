#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    // Shrubbery: sign 145, exec 137
    try {
        Bureaucrat gardener("Gardener", 137);
        ShrubberyCreationForm shrub("garden");
        gardener.signForm(shrub);
        gardener.executeForm(shrub);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Robotomy: sign 72, exec 45
    try {
        Bureaucrat robo("Robomaster", 45);
        RobotomyRequestForm robotomy("Bender");
        robo.signForm(robotomy);
        robo.executeForm(robotomy);
        robo.executeForm(robotomy);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Pardon: sign 25, exec 5
    try {
        Bureaucrat prez("President", 5);
        PresidentialPardonForm pardon("Zaphod");
        prez.signForm(pardon);
        prez.executeForm(pardon);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Try to execute unsigned form
    try {
        Bureaucrat b("B", 1);
        ShrubberyCreationForm f("test");
        b.executeForm(f); // not signed → error message
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // TEST: signed form + executor whose grade is too low to execute
    try {
        Bureaucrat signer("Signer", 100);      // Can sign (100 <= 145) ✅
        Bureaucrat executor("Executor", 150);  // Cannot execute (150 > 137) ❌
        ShrubberyCreationForm shrub("test");
    
        signer.signForm(shrub);        // Form is now SIGNED ✅
        executor.executeForm(shrub);   // Should fail because grade 150 > 137
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}