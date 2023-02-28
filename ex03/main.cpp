/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:25:33 by ziloughm          #+#    #+#             */
/*   Updated: 2023/02/28 15:46:25 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

int main(void)
{
    try
    {
        Intern someRandomIntern;
        Bureaucrat b("B1", 1);
        Form* rrf0;
        Form* rrf1;
        Form* rrf2;
        Form* rrf3;
        
        std::cout << RED << std::setfill('*') << std::setw(150) << WHT << std::endl;
        rrf0 = someRandomIntern.makeForm("robotomy request", "Bender1");
        rrf0->beSigned(b);
        rrf0->execute(b);
        std::cout << RED << std::setfill('*') << std::setw(150) << WHT << std::endl;

        std::cout << RED << std::setfill('*') << std::setw(150) << WHT << std::endl;
        rrf1 = someRandomIntern.makeForm("shrubbery creation", "Bender2");
        rrf1->beSigned(b);
        rrf1->execute(b);
        std::cout << RED << std::setfill('*') << std::setw(150) << WHT << std::endl;

        std::cout << RED << std::setfill('*') << std::setw(150) << WHT << std::endl;
        rrf2 = someRandomIntern.makeForm("presidential pardon", "Bender3");
        rrf2->beSigned(b);
        rrf2->execute(b);
        std::cout << RED << std::setfill('*') << std::setw(150) << WHT << std::endl;

        
        rrf3 = someRandomIntern.makeForm("test", "Bender");

        delete(rrf0);
        delete(rrf1);
        delete(rrf2);
        if (rrf3)
            delete(rrf3);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}