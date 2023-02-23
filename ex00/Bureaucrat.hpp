/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:49:47 by ziloughm          #+#    #+#             */
/*   Updated: 2023/02/23 18:04:27 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP


class Bureaucrat
{
    private:
        std::string name;
        int         grade;
    public:
        Bureaucrat();
        virtual ~Bureaucrat();
        Bureaucrat(std::string n, int g);
        Bureaucrat(Bureaucrat const &ob);

        Bureaucrat & operator=(Bureaucrat const &ob);
        std::string getName(void) const;
        int getGrade(void) const;
        void up_grade();
        void down_grade();
};

std::ostream & operator<<(std::ostream &o, Bureaucrat const &ref);

#   endif