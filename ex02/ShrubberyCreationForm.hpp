/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:10:55 by ziloughm          #+#    #+#             */
/*   Updated: 2023/02/27 18:14:03 by ziloughm         ###   ########.fr       */
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
		virtual void	execute(Bureaucrat const & executor) const;
		class           FileError : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
};

#   endif