#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other)
    : AForm(other), _target(other._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::executeAction() const
{
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}