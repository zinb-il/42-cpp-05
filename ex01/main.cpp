/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:25:33 by ziloughm          #+#    #+#             */
/*   Updated: 2023/02/28 12:41:57 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

int main(void)
{
    try
    {
        Form f("F1", 1, 1);
        Form f1("F1", FL, FL);
        Form f2("F2", 10, 15);
        Bureaucrat b("B1",74);
        Bureaucrat b1("B2",75);

        std::cout << f1;
        f1.beSigned(b);
        std::cout << f1;
        f1 = f2;
        std::cout << f1;
        b1.signForm(f);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}