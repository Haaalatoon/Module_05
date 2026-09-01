#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
    PresidentialPardonForm(std::string const &target);
    PresidentialPardonForm(PresidentialPardonForm const &other);
    PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
    ~PresidentialPardonForm();

protected:
    void executeAction() const;

private:
    std::string _target;
};

#endif