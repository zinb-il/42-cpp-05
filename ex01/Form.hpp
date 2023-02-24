/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:00:56 by ziloughm          #+#    #+#             */
/*   Updated: 2023/02/24 17:53:36 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef FORM_HPP
# define FORM_HPP


class Form
{
	private:
		std::string const   name;
		bool                signe;
		int const			s_grade;
		int const			e_grade;
	public:
		Form();
		virtual ~Form();
		Form(std::string n, int s_g, int e_g);
		Form(Form const &ob);

		Form &    operator=(Form const &ob);
		std::string     getName(void) const;
		int             getSGrade(void) const;
		int             getEGrade(void) const;
		bool            getSigned(void) const;
		void            test_grade(int grade);
		void			beSigned(Bureaucrat const & b);
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

std::ostream & operator<<(std::ostream &o, Form const &ref);

#   endif