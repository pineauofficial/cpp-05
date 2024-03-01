/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:19:11 by pineau            #+#    #+#             */
/*   Updated: 2024/03/01 17:20:37 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern& src) {
	*this = src;
}

Intern::~Intern() {
}

Intern&	Intern::operator=(const Intern& rhs) {
	(void)rhs;
	return *this;
}

AForm*	Intern::makeForm(std::string name, std::string target) {
	std::string	form_names[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	AForm* (Intern::*ptr[3])(std::string target) = {&Intern::makeRobotomyRequest, &Intern::makePresidentialPardon, &Intern::makeShrubberyCreation};
	for (int i = 0; i < 3; i++) {
		if (name == form_names[i])
			return (this->*ptr[i])(target);
	}
	std::cout << "This form does not exist" << std::endl;
	return NULL;
}

AForm*	Intern::makeRobotomyRequest(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm*	Intern::makePresidentialPardon(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeShrubberyCreation(std::string target) {
	return new ShrubberyCreationForm(target);
}