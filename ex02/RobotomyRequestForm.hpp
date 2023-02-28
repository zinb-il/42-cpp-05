/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:10:55 by ziloughm          #+#    #+#             */
/*   Updated: 2023/02/28 12:27:22 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP


class RobotomyRequestForm : public Form
{

	public:
		RobotomyRequestForm();
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &ob);

		RobotomyRequestForm &    operator=(RobotomyRequestForm const &ob);
		virtual void	execute(Bureaucrat const & executor) const;
		void		    executeForm(Bureaucrat const & executor);
};

#   endif