/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:19:01 by pineau            #+#    #+#             */
/*   Updated: 2024/03/01 17:23:10 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern& src);
		~Intern();
		Intern&	operator=(const Intern& rhs);

		AForm*	makeForm(std::string name, std::string target);
		AForm*	makeRobotomyRequest(std::string target);
		AForm*	makePresidentialPardon(std::string target);
		AForm*	makeShrubberyCreation(std::string target);
};

#endif