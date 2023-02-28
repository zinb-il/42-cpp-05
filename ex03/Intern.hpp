/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:01:01 by ziloughm          #+#    #+#             */
/*   Updated: 2023/02/28 15:28:44 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef INTERN_HPP
# define INTERN_HPP

class Intern
{
    public:
        Intern();
        ~Intern();
        Intern(Intern const &ob);
        Intern & operator=(Intern const &ob);

        Form * makeForm(std::string type, std::string target);

        class           TypeNotExist : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
};

#   endif
