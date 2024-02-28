/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:46:36 by pineau            #+#    #+#             */
/*   Updated: 2024/02/28 17:02:24 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string name, bool toSign, int signGrade, int execGrade) : _name(name), _toSign(toSign), _signGrade(signGrade), _execGrade(execGrade) {
	// std::cout << "Form default constructor called" << std::endl;
	if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
	else if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
}

AForm::~AForm() {
	// std::cout << "Form destructor called" << std::endl;
}

std::string AForm::getName() const {
	return _name;
}

bool AForm::getToSign() const {
	return _toSign;
}

int AForm::getSignGrade() const {
	return _signGrade;
}

int AForm::getExecGrade() const {
	return _execGrade;
}

std::ostream &operator<<(std::ostream &ost, const AForm &rhs)
{
	return ost << rhs.getName() << ", form grade to sign " << rhs.getSignGrade() << ", form grade to execute " << rhs.getExecGrade() << ", form is " << rhs.getToSign();
}

void	AForm::beSigned(Bureaucrat const &rhs)
{
	if (rhs.getGrade() > _signGrade)
		throw GradeTooLowException();
	_toSign = true;
}

void	AForm::executeCheck(Bureaucrat const & executor) const
{
	if (executor.getGrade() > _execGrade)
		throw (GradeTooLowException());
	if (_toSign == false)
		throw (FormNotSignedException());
}
