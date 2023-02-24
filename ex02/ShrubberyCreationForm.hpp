/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:10:55 by ziloughm          #+#    #+#             */
/*   Updated: 2023/02/24 20:29:19 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef SHRUBBERYCREATIONFORM_HPP
# define ShrubberyCreationForm_HPP


class ShrubberyCreationForm : public Form
{

	public:
		ShrubberyCreationForm();
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &ob);

		ShrubberyCreationForm &    operator=(ShrubberyCreationForm const &ob);
		std::string     getName(void) const;
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
};

std::ostream & operator<<(std::ostream &o, ShrubberyCreationForm const &ref);

#   endif