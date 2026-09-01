#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    // Valid sign: bureaucrat grade 50 can sign form requiring grade 75
    // (50 is a higher rank than 75, so condition passes)
    try
    {
        Bureaucrat  alice("Alice", 50);
        Form        f1("Tax Return", 75, 50);
        std::cout << f1 << std::endl;
        alice.signForm(f1);
        std::cout << f1 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Failed sign: bureaucrat grade 100 cannot sign form requiring grade 50
    try
    {
        Bureaucrat  bob("Bob", 100);
        Form        f2("Classified", 50, 25);
        bob.signForm(f2);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Invalid form — grade too high
    try
    {
        Form bad("Bad", 0, 50);
    }
    catch (std::exception &e)
    {
        std::cout << "Expected: " << e.what() << std::endl;
    }

    // Invalid form — grade too low
    try
    {
        Form bad("Bad", 50, 151);
    }
    catch (std::exception &e)
    {
        std::cout << "Expected: " << e.what() << std::endl;
    }

    return (0);
}