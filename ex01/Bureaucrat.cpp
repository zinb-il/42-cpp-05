/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:00:51 by ziloughm          #+#    #+#             */
/*   Updated: 2023/02/24 18:31:32 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

/********************************************************************/
/*                     Constructors  and Destructor                 */
/********************************************************************/

Bureaucrat::Bureaucrat():name("Bureaucrat"), grade(L)
{
    std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string n, int g):name(n)
{
    this->test_grade(g);
    this->grade = g;
    std::cout << "Bureaucrat Parameter constroctur called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &ob)
{
    std::cout << "Bureaucrat Copy constroctur called" << std::endl;
    *this = ob;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat Destructor called " << std::endl;
}
/********************************************************************/



/********************************************************************/
/*                    Assignment Operator Overload                  */
/********************************************************************/

Bureaucrat & Bureaucrat::operator=(Bureaucrat const &ob)
{
    std::cout << "Bureaucrat Copy assignment operator called" << std::endl;

    const_cast<std::string &>(name) = ob.getName();
    this->grade = ob.getGrade();
    return (*this);
}

/********************************************************************/


/********************************************************************/
/*                             Exceptions                           */
/********************************************************************/

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
     return ("The heigher grade of a Bureaucrat is 1");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
     return ("The lower grade of a Bureaucrat is 150");
}

/********************************************************************/



/********************************************************************/
/*                  Getters and Setters functions                   */
/********************************************************************/

void Bureaucrat::test_grade(int grade)
{
    if(grade < H)
        throw(Bureaucrat::GradeTooHighException());
    if(grade > L)
        throw(Bureaucrat::GradeTooLowException());
}

std::string Bureaucrat::getName(void) const
{
    return (this->name);
}

int Bureaucrat::getGrade(void) const
{
    return (this->grade);
}

/********************************************************************/




/********************************************************************/
/*                          Public functions                        */
/********************************************************************/


void    Bureaucrat::up_grade()
{
    this->test_grade(this->grade - 1);
    this->grade --;
}

void    Bureaucrat::down_grade()
{
    this->test_grade(this->grade + 1);
    this->grade ++;
}

void    Bureaucrat::signForm(Form const & f) const
{
    try
    {
        const_cast<Form &>(f).beSigned(*this);
        std::cout << this->name << " signed " << f.getName() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << this->name << " couldn’t sign " << f.getName() 
        << " because " << e.what()<< std::endl;
    }
}

/********************************************************************/


std::ostream & operator<<(std::ostream & o, Bureaucrat const &ref)
{
    std::cout << ref.getName() << ", bureaucrat grade " << ref.getGrade() << std::endl; 
    return o;
}
