/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:00:51 by ziloughm          #+#    #+#             */
/*   Updated: 2023/02/28 12:09:15 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

/********************************************************************/
/*                     Constructors  and Destructor                 */
/********************************************************************/

RobotomyRequestForm::RobotomyRequestForm():Form()
{
    std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
    setName("RobotomyRequestForm");
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):Form(target, S_RL, E_RL)
{
    std::cout << "RobotomyRequestForm Parameter constroctur called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &ob):Form(ob)
{
    std::cout << "RobotomyRequestForm Copy constroctur called" << std::endl;
    setName("RobotomyRequestForm");
    *this = ob;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm Destructor called " << std::endl;
}
/********************************************************************/



/********************************************************************/
/*                    Assignment Operator Overload                  */
/********************************************************************/

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const &ob)
{
    std::cout << "RobotomyRequestForm Copy assignment operator called" << std::endl;
    return dynamic_cast<RobotomyRequestForm &>(Form::operator=(ob));
}

/********************************************************************/


/********************************************************************/
/*                          Public functions                        */
/********************************************************************/


void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    int r;
    
    if (executor.getGrade() > this->getEGrade())
       throw(Form::GradeTooLowException());
    if (!this->getSigned())
        throw(Form::FormNotSigned());
    if (this->getExecuted())
        throw(Form::FormIsExecuted());
    srand((unsigned) time(NULL));
    r = rand() % 10 + 1;
    if (r > 5)
        std::cout << "Dr Dr "<< this->getName() << " has been robotomized"
        << "successfully 50\% of the time" <<std::endl;
    else
        std::cout << this->getName() << " hasn't been robotomized" <<std::endl;
}

/********************************************************************/

