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
        // check garden_shrubbery file was created
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Robotomy: sign 72, exec 45
    try {
        Bureaucrat robo("Robomaster", 45);
        RobotomyRequestForm robotomy("Bender");
        robo.signForm(robotomy);
        robo.executeForm(robotomy);
        robo.executeForm(robotomy); // run twice to see 50% randomness
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

    return 0;
}