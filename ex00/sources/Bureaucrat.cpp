/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:37:26 by pineau            #+#    #+#             */
/*   Updated: 2024/02/23 18:32:37 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade){
	// std::cout << "Bureaucrat default constructor called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {
	// std::cout << "Bureaucrat destructor called" << std::endl;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

std::string Bureaucrat::getName() const {
	return _name;
}

void Bureaucrat::incrementGrade() {
	if (_grade > 1)
		_grade--;
	else
		throw GradeTooHighException();
}

void Bureaucrat::decrementGrade() {
	if (_grade < 150)
		_grade++;
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &ost, const Bureaucrat &rhs)
{
	return ost << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
}
