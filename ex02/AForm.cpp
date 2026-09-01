#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    : _name("Classified Form"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(AForm const &other)
    : _name(other._name), _signed(other._signed),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

AForm &AForm::operator=(AForm const &other)
{
    if (this != &other)
        _signed = other._signed;
    return *this;
}

AForm::~AForm() {}

std::string const   &AForm::getName() const           { return _name; }
bool                AForm::isSigned() const           { return _signed; }
int                 AForm::getGradeToSign() const     { return _gradeToSign; }
int                 AForm::getGradeToExecute() const  { return _gradeToExecute; }

void AForm::beSigned(Bureaucrat const &b)
{
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _signed = true;
}

// The elegant approach: base class checks conditions, then calls pure virtual
void AForm::execute(Bureaucrat const &executor) const
{
    if (!_signed)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();
    executeAction(); // polymorphic dispatch to concrete class
}

const char *AForm::GradeTooHighException::what() const throw()  { return "Form grade too high!"; }
const char *AForm::GradeTooLowException::what() const throw()   { return "Form grade too low!"; }
const char *AForm::FormNotSignedException::what() const throw()  { return "Form is not signed!"; }

std::ostream &operator<<(std::ostream &os, AForm const &f)
{
    os << "Form " << f.getName()
       << " | signed: " << (f.isSigned() ? "yes" : "no")
       << " | grade to sign: " << f.getGradeToSign()
       << " | grade to execute: " << f.getGradeToExecute();
    return os;
}