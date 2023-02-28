/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:03:35 by ziloughm          #+#    #+#             */
/*   Updated: 2023/02/28 15:37:57 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

/********************************************************************/
/*                     Constructors  and Destructor                 */
/********************************************************************/

Intern::Intern()
{
    std::cout << "Intern Default constructor called" << std::endl;
}

Intern::~Intern()
{
   std::cout << "Intern Destructor called " << std::endl;
}

Intern::Intern(Intern const &ob)
{
    std::cout << "Intern Copy constroctur called" << std::endl;
    *this = ob;
}
/********************************************************************/



/********************************************************************/
/*                    Assignment Operator Overload                  */
/********************************************************************/
Intern & Intern::operator=(Intern const &ob)
{
    std::cout << "Intern Copy assignment operator called" << std::endl;
    static_cast<void>(ob);
    return(*this);
}
/********************************************************************/




/********************************************************************/
/*                          Public functions                        */
/********************************************************************/

Form * Intern::makeForm(std::string type, std::string target)
{
    std::string types[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
    int p = -1;
    
    for (size_t i = 0; i < 3; i++)
    {
        if (types[i] == type)
        {
            std::cout << GRN << "Intern creates " << target << WHT <<std::endl;
            p = i;
        }
        switch(p)
        {
            case 0:
                return(new RobotomyRequestForm(target));
            case 1:
                return(new ShrubberyCreationForm(target));
            case 2:
                return(new PresidentialPardonForm(target));
            default:
                continue;
        }
    }
    throw(Intern::TypeNotExist());
    return NULL;
    
}

/********************************************************************/

const char* Intern::TypeNotExist::what(void) const throw()
{
    return ("This type doesn't exist");
}