#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(Intern const &other) { (void)other; }

Intern &Intern::operator=(Intern const &other) { (void)other; return *this; }

Intern::~Intern() {}

// Member functions (not static)
AForm *Intern::makeShrubbery(std::string const &target) {
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomy(std::string const &target) {
    return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidential(std::string const &target) {
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string const &name, std::string const &target) {
    // Define a struct holding a name and a pointer-to-member-function
    struct FormType {
        std::string name;
        AForm *     (Intern::*func)(std::string const &);
    };

    FormType const dispatch[] = {
        { "shrubbery creation", &Intern::makeShrubbery },
        { "robotomy request",   &Intern::makeRobotomy },
        { "presidential pardon", &Intern::makePresidential }
    };

    for (int i = 0; i < 3; ++i) {
        if (dispatch[i].name == name) {
            std::cout << "Intern creates " << name << '\n';
            // Call the member function using the pointer-to-member
            return (this->*dispatch[i].func)(target);
        }
    }

    std::cout << "Intern cannot create " << name << '\n';
    return NULL;
}