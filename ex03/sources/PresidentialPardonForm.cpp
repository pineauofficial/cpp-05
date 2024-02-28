/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:28:14 by pineau            #+#    #+#             */
/*   Updated: 2024/02/28 17:27:16 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", false, 25, 5) , _target("default") {
	// std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) : AForm("PresidentialPardonForm", false, 25, 5), _target(target) {
	// std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	// std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : AForm("PresidentialPardonForm", false, 25, 5), _target(src._target){
	// std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	*this = src;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs) {
	// std::cout << "PresidentialPardonForm assignation operator called" << std::endl;
	(void)rhs;
	return *this;
}

std::string PresidentialPardonForm::getTarget() const {
	return _target;
}

void	PresidentialPardonForm::execute(const Bureaucrat &rhs) const
{
	executeCheck(rhs);
	std::cout << _target << " has been forgiven by Zaphod Beeblebrox\n";
}

std::ostream &operator<<(std::ostream &ost, const PresidentialPardonForm &rhs)
{
	return ost << rhs.getName() << ", form grade to sign " << rhs.getSignGrade() << ", form grade to execute " << rhs.getExecGrade() << ", form is " << rhs.getToSign() << ", target is " << rhs.getTarget();
}
