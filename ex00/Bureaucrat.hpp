#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;

	void	setGrade(int grade);

public:
	// OCF
	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	~Bureaucrat();

	Bureaucrat	&operator=(const Bureaucrat &other);

	// Getters
	const std::string	&getName() const;
	int					getGrade() const;

	// Grade modification
	void	incrementGrade();
	void	decrementGrade();

	// Exceptions
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &b);

#endif