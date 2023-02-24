/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:00:51 by ziloughm          #+#    #+#             */
/*   Updated: 2023/02/24 20:30:57 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

/********************************************************************/
/*                     Constructors  and Destructor                 */
/********************************************************************/

ShrubberyCreationForm::ShrubberyCreationForm():Form()
{
    std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):Form(target, S_SL, E_SL)
{
    std::cout << "ShrubberyCreationForm Parameter constroctur called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &ob):Form(ob)
{
    std::cout << "ShrubberyCreationForm Copy constroctur called" << std::endl;
    *this = ob;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm Destructor called " << std::endl;
}
/********************************************************************/



/********************************************************************/
/*                    Assignment Operator Overload                  */
/********************************************************************/

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const &ob)
{
    std::cout << "ShrubberyCreationForm Copy assignment operator called" << std::endl;
    return (*this);
}

/********************************************************************/


/********************************************************************/
/*                             Exceptions                           */
/********************************************************************/

const char* ShrubberyCreationForm::GradeTooHighException::what(void) const throw()
{
     return ("The grade is too heigher");
}

const char* ShrubberyCreationForm::GradeTooLowException::what(void) const throw()
{
     return ("The grade is too lower");
}

/********************************************************************/



/********************************************************************/
/*                  Getters and Setters functions                   */
/********************************************************************/

void ShrubberyCreationForm::test_grade(int grade)
{
    if(grade < H)
        throw(ShrubberyCreationForm::GradeTooHighException());
    if(grade > S_SL)
        throw(ShrubberyCreationForm::GradeTooLowException());
}

std::string ShrubberyCreationForm::getName(void) const
{
    return (this->name);
}

int ShrubberyCreationForm::getSGrade(void) const
{
    return (this->s_grade);
}

int ShrubberyCreationForm::getEGrade(void) const
{
    return (this->e_grade);
}

bool    ShrubberyCreationForm::getSigned(void) const
{
    return (this->signe);
}

/********************************************************************/




/********************************************************************/
/*                          Public functions                        */
/********************************************************************/


void    ShrubberyCreationForm::beSigned(Bureaucrat const & b)
{
    if (b.getGrade() > this->s_grade)
       throw(ShrubberyCreationForm::GradeTooLowException());
    this->signe = true;
}

/********************************************************************/


std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const &ref)
{
    std::cout <<  "ShrubberyCreationForm \"" << ref.getName() << "\" is signed : "
    << (!ref.getSigned() ? "'No'" : "\"Yes\"") << 
    ", it's signe grade is: " << ref.getSGrade() << 
    ", it's execute grade is: " << ref.getEGrade() << std::endl; 
    return o;
}
