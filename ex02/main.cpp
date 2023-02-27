/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:25:33 by ziloughm          #+#    #+#             */
/*   Updated: 2023/02/27 18:48:01 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

int main(void)
{
    try
    {
        // Form *f1 = new ShrubberyCreationForm("Zineb");
        // Bureaucrat b("B1", 8);

        // std::cout << *f1;
        // f1->beSigned(b);
        // std::cout << *f1;
        // f1->execute(b);
        
        // delete(f1);
        
        // Form *f1 = new RobotomyRequestForm("Zineb");
        // Bureaucrat b("B1", 45);

        // std::cout << *f1;
        // f1->beSigned(b);
        // std::cout << *f1;
        // f1->execute(b);
        
        // delete(f1);
        
        Form *f1 = new PresidentialPardonForm("Zineb");
        Bureaucrat b("B1", 5);

       std::cout << *f1;
       //f1->beSigned(b);
       b.signForm(*f1);
       std::cout << *f1;
       f1->execute(b);
        
        delete(f1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}