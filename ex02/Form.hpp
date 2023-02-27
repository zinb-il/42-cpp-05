/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:00:56 by ziloughm          #+#    #+#             */
/*   Updated: 2023/02/27 17:30:08 by ziloughm         ###   ########.fr       */
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
		void		    setName(std::string const n);
		int             getSGrade(void) const;
		int             getEGrade(void) const;
		bool            getSigned(void) const;
		virtual void	test_grade(int grade, int limit);
		void			beSigned(Bureaucrat const & b);
		virtual void	execute(Bureaucrat const & executor) const = 0;
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
		class           FormNotSigned : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
		
};

std::ostream & operator<<(std::ostream &o, Form const &ref);

#   endif