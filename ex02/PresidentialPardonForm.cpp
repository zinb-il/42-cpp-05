/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:00:51 by ziloughm          #+#    #+#             */
/*   Updated: 2023/02/27 18:44:49 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

/********************************************************************/
/*                     Constructors  and Destructor                 */
/********************************************************************/

PresidentialPardonForm::PresidentialPardonForm():Form()
{
    std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
    setName("PresidentialPardonForm");
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):Form(target, S_PL, E_PL)
{
    std::cout << "PresidentialPardonForm Parameter constroctur called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &ob):Form(ob)
{
    std::cout << "PresidentialPardonForm Copy constroctur called" << std::endl;
    setName("PresidentialPardonForm");
    *this = ob;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm Destructor called " << std::endl;
}
/********************************************************************/



/********************************************************************/
/*                    Assignment Operator Overload                  */
/********************************************************************/

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const &ob)
{
    std::cout << "PresidentialPardonForm Copy assignment operator called" << std::endl;
    return dynamic_cast<PresidentialPardonForm &>(Form::operator=(ob));
}

/********************************************************************/


/********************************************************************/
/*                          Public functions                        */
/********************************************************************/


void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > this->getEGrade())
       throw(Form::GradeTooLowException());
    if (!this->getSigned())
        throw(Form::FormNotSigned());
    std::cout << this->getName() << " has been pardoned by" 
    << " Zaphod Beeblebrox" <<std::endl;
}

/********************************************************************/

