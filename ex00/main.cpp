/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:25:33 by ziloughm          #+#    #+#             */
/*   Updated: 2023/02/28 16:10:41 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"


int main(void)
{
    std::cout << GRN << "Tes1" << WHT << std::endl;
    try 
    {
        Bureaucrat b1("Bureaucrat1", 1);
        Bureaucrat b2("Bureaucrat2", 150);
        Bureaucrat b3("Bureaucrat3", 7);
        Bureaucrat *y = new Bureaucrat("Test", 888);
        
        b1.up_grade();
        b2.down_grade();
        std::cout << b1 << b2;
        b2.up_grade();
        b1.down_grade();
        std::cout << b1 << b2;
        std::cout << GRN << std::setfill('*') << std::setw(100) << WHT << std::endl;
        std::cout << RED << std::setfill('*') << std::setw(150) << WHT << std::endl;
        std::cout << GRN << "Tes5" << WHT << std::endl;
        std::cout << *y << std::endl;
        std::cout << RED << std::setfill('*') << std::setw(150) << WHT << std::endl << std::endl;

        std::cout << b3;
        b3 = b2;
        std::cout << b3;
        delete(y);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() <<std::endl;
    }
    return 0;
}