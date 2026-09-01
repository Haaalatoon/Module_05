#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
# include <string>

class Bureaucrat;

class AForm
{
public:
    AForm();
    AForm(std::string const &name, int gradeToSign, int gradeToExecute);
    AForm(AForm const &other);
    AForm &operator=(AForm const &other);
    virtual ~AForm();

    std::string const   &getName() const;
    bool                isSigned() const;
    int                 getGradeToSign() const;
    int                 getGradeToExecute() const;

    void beSigned(Bureaucrat const &b);

    // Public execute: checks signed + grade, then calls executeAction()
    void execute(Bureaucrat const &executor) const;

    class GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
    class FormNotSignedException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

protected:
    // Subclasses implement this — it's what the form actually does
    virtual void executeAction() const = 0;

private:
    std::string const   _name;
    bool                _signed;
    int const           _gradeToSign;
    int const           _gradeToExecute;
};

std::ostream &operator<<(std::ostream &os, AForm const &f);

#endif