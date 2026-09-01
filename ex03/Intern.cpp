#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}
Intern::Intern(Intern const &other) { (void)other; }
Intern &Intern::operator=(Intern const &other) { (void)other; return *this; }
Intern::~Intern() {}

// Factory functions — one per form type
static AForm *makeShrubbery(std::string const &target)
{
    return new ShrubberyCreationForm(target);
}

static AForm *makeRobotomy(std::string const &target)
{
    return new RobotomyRequestForm(target);
}

static AForm *makePardon(std::string const &target)
{
    return new PresidentialPardonForm(target);
}

// Table maps name → factory function. No if/else needed.
AForm *Intern::makeForm(std::string const &name, std::string const &target)
{
    struct FormEntry {
        std::string formName;
        AForm       *(*create)(std::string const &);
    };

    FormEntry forms[] = {
        {"shrubbery creation", makeShrubbery},
        {"robotomy request",   makeRobotomy},
        {"presidential pardon", makePardon}
    };

    int size = 3;
    for (int i = 0; i < size; i++) {
        if (forms[i].formName == name) {
            std::cout << "Intern creates " << name << std::endl;
            return forms[i].create(target);
        }
    }

    std::cerr << "Error: unknown form name '" << name << "'" << std::endl;
    return NULL;
}