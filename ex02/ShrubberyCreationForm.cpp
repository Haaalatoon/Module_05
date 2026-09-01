#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const
{
    std::string filename = _target + "_shrubbery";
    std::ofstream file(filename.c_str()); // c_str() needed in C++98
    if (!file.is_open())
        throw std::runtime_error("Cannot open file");
    file << "       *       " << std::endl;
    file << "      ***      " << std::endl;
    file << "     *****     " << std::endl;
    file << "    *******    " << std::endl;
    file << "   *********   " << std::endl;
    file << "      |||      " << std::endl;
    file << "       *       " << std::endl;
    file << "      ***      " << std::endl;
    file << "     *****     " << std::endl;
    file << "      |||      " << std::endl;
    file.close();
}