/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:10:55 by ziloughm          #+#    #+#             */
/*   Updated: 2023/02/28 12:27:12 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP


class PresidentialPardonForm : public Form
{

	public:
		PresidentialPardonForm();
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &ob);

		PresidentialPardonForm &    operator=(PresidentialPardonForm const &ob);
		virtual void	execute(Bureaucrat const & executor) const;
		void		    executeForm(Bureaucrat const & executor);
};

#   endif