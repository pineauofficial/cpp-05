/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:27:41 by pineau            #+#    #+#             */
/*   Updated: 2024/02/28 17:28:07 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", false, 72, 45), _target("default") {
	// std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	// std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) : AForm("RobotomyRequestForm", false, 72, 45), _target(target) {
	// std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm("RobotomyRequestForm", false, 72, 45), _target(src._target) {
	// std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = src;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs) {
	// std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
	(void)rhs;
	return *this;
}

std::string RobotomyRequestForm::getTarget() const {
	return _target;
}

void RobotomyRequestForm::execute(const Bureaucrat &rhs) const {
	executeCheck(rhs);
	std::cout << "Drilling noises" << std::endl;
	int	random = std::rand();
	std::string targetname = _target;
	if (random % 2)
		std::cout << targetname << " has been properly robotomized\n";  
	else
		std::cout << "I'am affraid that " << targetname << " robotomy failed\n";
}

std::ostream &operator<<(std::ostream &ost, const RobotomyRequestForm &rhs) {
	return ost << rhs.getName() << ", form grade to sign " << rhs.getSignGrade() << ", form grade to execute " << rhs.getExecGrade() << ", form is " << rhs.getToSign() << ", target is " << rhs.getTarget();
}
