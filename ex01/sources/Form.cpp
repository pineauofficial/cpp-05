/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:46:36 by pineau            #+#    #+#             */
/*   Updated: 2024/02/24 15:41:12 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, bool toSign, int signGrade, int execGrade) : _name(name), _toSign(toSign), _signGrade(signGrade), _execGrade(execGrade) {
	// std::cout << "Form default constructor called" << std::endl;
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

Form::~Form() {
	// std::cout << "Form destructor called" << std::endl;
}

std::string Form::getName() const {
	return _name;
}

bool Form::getToSign() const {
	return _toSign;
}

int Form::getSignGrade() const {
	return _signGrade;
}

int Form::getExecGrade() const {
	return _execGrade;
}

std::ostream &operator<<(std::ostream &ost, const Form &rhs)
{
	return ost << rhs.getName() << ", form grade to sign " << rhs.getSignGrade() << ", form grade to execute " << rhs.getExecGrade() << ", form is " << rhs.getToSign();
}

void	Form::beSigned(Bureaucrat const &rhs)
{
	if (rhs.getGrade() > _signGrade)
		throw GradeTooLowException();
	_toSign = true;
}
