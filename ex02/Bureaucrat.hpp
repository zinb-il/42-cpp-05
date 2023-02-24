/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:49:47 by ziloughm          #+#    #+#             */
/*   Updated: 2023/02/24 20:05:18 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

class Form;

class Bureaucrat
{
    private:
        std::string const name;
        int               grade;
    public:
        Bureaucrat();
        virtual ~Bureaucrat();
        Bureaucrat(std::string n, int g);
        Bureaucrat(Bureaucrat const &ob);

        Bureaucrat &    operator=(Bureaucrat const &ob);
        std::string     getName(void) const;
        int             getGrade(void) const;
        void            up_grade();
        void            down_grade();
        void            test_grade(int grade);
        void            signForm(Form const & f) const;
        class           GradeTooHighException : public std::exception
        {
            public:
                const char* what(void) const throw();
        };
        class           GradeTooLowException : public std::exception
        {
            public:
                const char* what(void) const throw();
        };
};

std::ostream & operator<<(std::ostream &o, Bureaucrat const &ref);

#   endif