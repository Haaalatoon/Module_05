#include "Form.hpp"
#include "Bureaucrat.hpp"


/* Constructors / Destructor */
Form::Form()
    : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &other)
    : _name(other._name), _signed(other._signed),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

Form::~Form() {}


/* Assignment */
Form    &Form::operator=(const Form &other)
{
    if (this != &other)
        _signed = other._signed;
    return (*this);
}


/* Getters */
const std::string   &Form::getName() const          { return (_name); }
bool                Form::isSigned() const          { return (_signed); }
int                 Form::getGradeToSign() const    { return (_gradeToSign); }
int                 Form::getGradeToExecute() const { return (_gradeToExecute); }


/* beSigned */
void    Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _signed = true;
}


/* Exceptions */
const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}


/* Ostream */
std::ostream    &operator<<(std::ostream &os, const Form &f)
{
    os << "Form: "             << f.getName()
       << " | Signed: "        << (f.isSigned() ? "yes" : "no")
       << " | Grade to sign: " << f.getGradeToSign()
       << " | Grade to exec: " << f.getGradeToExecute() ;
    return (os);
}