/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:25:33 by ziloughm          #+#    #+#             */
/*   Updated: 2023/02/28 16:18:28 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

int main(void)
{
    try
    {
        Form f1("F1", 1, 1);
        Form f2("F2", FL, FL);
        Form f3("F3", 10, 15);
        Bureaucrat b("B1",74);
        Bureaucrat b1("B2",75);

        std::cout << f1;
        f2.beSigned(b);
        std::cout << f1;
        f2 = f3;
        std::cout << f1;
        b1.signForm(f1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}