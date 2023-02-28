/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:00:51 by ziloughm          #+#    #+#             */
/*   Updated: 2023/02/28 12:38:52 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

/********************************************************************/
/*                     Constructors  and Destructor                 */
/********************************************************************/

ShrubberyCreationForm::ShrubberyCreationForm():Form()
{
    std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
    setName("ShrubberyCreationForm");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):Form(target, S_SL, E_SL)
{
    std::cout << "ShrubberyCreationForm Parameter constroctur called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &ob):Form(ob)
{
    std::cout << "ShrubberyCreationForm Copy constroctur called" << std::endl;
    setName("ShrubberyCreationForm");
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
    return dynamic_cast<ShrubberyCreationForm &>(Form::operator=(ob));
}

/********************************************************************/



/********************************************************************/
/*                             Exceptions                           */
/********************************************************************/

const char* ShrubberyCreationForm::FileError::what(void) const throw()
{
     return ("Une erreur s'est produite lors de l'ouverture du fichier ShrubberyCreationForm");
}

/********************************************************************/




/********************************************************************/
/*                          Public functions                        */
/********************************************************************/


void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    std::ofstream *outputfile;
    std::string shrubbery = "      @@      \n"
                            "   @@@@@@@@   \n"
                            " @@@@@@@@@@@@ \n"
                            "@@@@@@@@@@@@@@\n"
                            "@@@@|    |@@@@\n"
                            "  @@|    |@@  \n"
                            "    |    |    \n"
                            "    |    |    \n"
                            "____|____|____\n";
    Form::executeForm(executor);
    outputfile = new std::ofstream (this->getName() + "_shrubbery", std::ofstream::out | std::ofstream::trunc);
    if (!outputfile->good())
        throw(ShrubberyCreationForm::FileError());
    *(outputfile) << shrubbery;
    *(outputfile) << shrubbery;
    *(outputfile) << shrubbery;
    outputfile->close();
}

/********************************************************************/

