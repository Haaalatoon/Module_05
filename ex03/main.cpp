#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main()
{
    Intern someRandomIntern;
    AForm *rrf = NULL;

    // Valid form: robotomy request
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf) {
        Bureaucrat b("Bob", 1);
        b.signForm(*rrf);
        b.executeForm(*rrf);
        delete rrf;
    }

    // Valid form: shrubbery creation
    AForm *shrub = someRandomIntern.makeForm("shrubbery creation", "home");
    if (shrub) {
        Bureaucrat b("Gardener", 137);
        b.signForm(*shrub);
        b.executeForm(*shrub);
        delete shrub;
    }

    // ✅ NEW TEST: presidential pardon
    AForm *pardon = someRandomIntern.makeForm("presidential pardon", "Arthur");
    if (pardon) {
        Bureaucrat b("President", 1);
        b.signForm(*pardon);
        b.executeForm(*pardon);
        delete pardon;
    }

    // Invalid form name
    AForm *bad = someRandomIntern.makeForm("coffee request", "espresso");
    if (!bad)
        std::cout << "No form created (expected)" << std::endl;

    return 0;
}