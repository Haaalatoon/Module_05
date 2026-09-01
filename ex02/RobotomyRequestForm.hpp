#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
    RobotomyRequestForm(std::string const &target);
    RobotomyRequestForm(RobotomyRequestForm const &other);
    RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
    ~RobotomyRequestForm();

protected:
    void executeAction() const;

private:
    std::string _target;
};

#endif