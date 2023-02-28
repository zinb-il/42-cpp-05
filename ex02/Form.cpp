/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:00:51 by ziloughm          #+#    #+#             */
/*   Updated: 2023/02/28 12:27:42 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

/********************************************************************/
/*                     Constructors  and Destructor                 */
/********************************************************************/

Form::Form():name("Form"), signe(false) , executed(false), s_grade(L), e_grade(L)
{
    std::cout << "Form Default constructor called" << std::endl;
}

Form::Form(std::string n, int s_g, int e_g):name(n), signe(false), executed(false), s_grade(s_g), e_grade(e_g)
{
    this->test_grade(s_g, L);
    this->test_grade(e_g, L);
    std::cout << "Form Parameter constroctur called" << std::endl;
}

Form::Form(Form const &ob):s_grade(L), e_grade(L)
{
    std::cout << "Form Copy constroctur called" << std::endl;
    *this = ob;
}

Form::~Form()
{
    std::cout << "Form Destructor called " << std::endl;
}
/********************************************************************/



/********************************************************************/
/*                    Assignment Operator Overload                  */
/********************************************************************/

Form & Form::operator=(Form const &ob)
{
    std::cout << "Form Copy assignment operator called" << std::endl;
    const_cast<std::string &>(name) = ob.getName();
    const_cast<int &>(s_grade) = ob.getSGrade();
    const_cast<int &>(e_grade) = ob.getEGrade();
    this->signe = ob.getSigned();
    this->executed = ob.getExecuted();
    return (*this);
}

/********************************************************************/


/********************************************************************/
/*                             Exceptions                           */
/********************************************************************/

const char* Form::GradeTooHighException::what(void) const throw()
{
     return ("The grade is too heigher");
}

const char* Form::GradeTooLowException::what(void) const throw()
{
     return ("The grade is too lower");
}
const char* Form::FormNotSigned::what(void) const throw()
{
     return ("The form is not signed");
}
const char* Form::FormIsExecuted::what(void) const throw()
{
     return ("The form is already executed");
}

/********************************************************************/



/********************************************************************/
/*                  Getters and Setters functions                   */
/********************************************************************/

void Form::test_grade(int grade, int limit)
{
    if(grade < H)
        throw(Form::GradeTooHighException());
    if(grade > limit)
        throw(Form::GradeTooLowException());
}

void Form::setName(std::string const n)
{
    const_cast<std::string &>(name) = n;
}

std::string Form::getName(void) const
{
    return (this->name);
}


int Form::getSGrade(void) const
{
    return (this->s_grade);
}

int Form::getEGrade(void) const
{
    return (this->e_grade);
}

bool    Form::getSigned(void) const
{
    return (this->signe);
}
bool    Form::getExecuted(void) const
{
    return (this->executed);
}

/********************************************************************/




/********************************************************************/
/*                          Public functions                        */
/********************************************************************/


void    Form::beSigned(Bureaucrat const & b)
{
    if (b.getGrade() > this->s_grade)
       throw(Form::GradeTooLowException());
    this->signe = true;
}

void Form::executeForm(Bureaucrat const & executor)
{
    if (executor.getGrade() > this->e_grade)
       throw(Form::GradeTooLowException());
    if (!this->signe)
        throw(Form::FormNotSigned());
    if (this->executed)
        throw(Form::FormIsExecuted());
    this->executed = true;
    
}

/********************************************************************/


std::ostream & operator<<(std::ostream & o, Form const &ref)
{
    std::cout <<  "Form \"" << ref.getName() << "\" is signed : "
    << (!ref.getSigned() ? "'No'" : "\"Yes\"") << 
    "\" is executed : " << (!ref.getExecuted() ? "'No'" : "\"Yes\"") << 
    ", it's signe grade is: " << ref.getSGrade() << 
    ", it's execute grade is: " << ref.getEGrade() << std::endl; 
    return o;
}
