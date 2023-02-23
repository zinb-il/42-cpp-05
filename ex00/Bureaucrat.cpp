/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:00:51 by ziloughm          #+#    #+#             */
/*   Updated: 2023/02/23 18:06:44 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

/********************************************************************/
/*                     Constructors  and Destructor                 */
/********************************************************************/

Bureaucrat::Bureaucrat():name("Bureaucrat"), grade(150)
{
    std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string n, int g):name(n), grade(g)
{
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
    this->name = ob.getName();
    this->grade = ob.getGrade();
    return (*this);
}

/********************************************************************/



/********************************************************************/
/*                  Getters and Setters functions                   */
/********************************************************************/


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
    this->grade --;
}

void    Bureaucrat::down_grade()
{
    this->grade ++;
}

/********************************************************************/


std::ostream & operator<<(std::ostream & o, Bureaucrat const &ref)
{
    std::cout << ref.getName() << " , bureaucrat grade " << ref.getGrade() << std::endl; 
    return o;
}
