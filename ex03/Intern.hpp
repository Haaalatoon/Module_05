#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include <string>

class Intern
{
public:
    Intern();
    Intern(Intern const &other);
    Intern &operator=(Intern const &other);
    ~Intern();

    AForm *makeForm(std::string const &name, std::string const &target);

private:
    // Member functions (not static)
    AForm *makeShrubbery(std::string const &target);
    AForm *makeRobotomy(std::string const &target);
    AForm *makePresidential(std::string const &target);
};

#endif