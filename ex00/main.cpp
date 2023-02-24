/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:25:33 by ziloughm          #+#    #+#             */
/*   Updated: 2023/02/24 17:50:37 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

void    b_init(std::string n, int grade)
{
    try 
    {
        Bureaucrat b(n, grade);
        std::cout << b;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void    call_up_down(Bureaucrat *b, void(Bureaucrat::*f)(void))
{
    try 
    {
        ((b)->*f)();
    }
    catch(std::exception &e)
    {
        std::cout << e.what() <<std::endl;
    }
}


int main(void)
{
    std::cout << GRN << "Tes1" << WHT << std::endl;
    try 
    {
        Bureaucrat b1("Bureaucrat1", 1);
        Bureaucrat b2("Bureaucrat2", 150);
        Bureaucrat b3("Bureaucrat3", 7);
        Bureaucrat *y = new Bureaucrat("Test", 888);
        
        call_up_down(&b1, &Bureaucrat::up_grade);
        call_up_down(&b2, &Bureaucrat::down_grade);
        std::cout << b1 << b2;
        call_up_down(&b2, &Bureaucrat::up_grade);
        call_up_down(&b1, &Bureaucrat::down_grade);
        std::cout << b1 << b2;
        std::cout << GRN << std::setfill('*') << std::setw(100) << WHT << std::endl;
        std::cout << RED << std::setfill('*') << std::setw(150) << WHT << std::endl;
        std::cout << GRN << "Tes5" << WHT << std::endl;
        std::cout << *y << std::endl;
        std::cout << RED << std::setfill('*') << std::setw(150) << WHT << std::endl << std::endl;

        std::cout << b3;
        b3 = b2;
        std::cout << b1;
        delete(y);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() <<std::endl;
    }
    // std::cout << RED << std::setfill('*') << std::setw(150) << WHT << std::endl << std::endl;
    // std::cout << RED << std::setfill('*') << std::setw(150) << WHT << std::endl;
    // std::cout << GRN << "Tes3" << WHT << std::endl;
    // b_init("Bureaucrat3", 20);
    // b_init("Bureaucrat4", 50);
    // std::cout << RED << std::setfill('*') << std::setw(150) << WHT << std::endl << std::endl;
    
    // std::cout << RED << std::setfill('*') << std::setw(150) << WHT << std::endl; 
    // std::cout << GRN << "Tes4" << WHT << std::endl;
    // b_init("Bureaucrat3", 0);
    // b_init("Bureaucrat4", 151);
    // b_init("Bureaucrat4", -8);
    // std::cout << RED << std::setfill('*') << std::setw(150) << WHT << std::endl << std::endl;
    return 0;
}