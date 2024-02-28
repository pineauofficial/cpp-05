/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:26:57 by pineau            #+#    #+#             */
/*   Updated: 2024/02/28 17:28:45 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", false, 145, 137), _target("default") {
	// std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	// std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : AForm("ShrubberyCreationForm", false, 145, 137), _target(target) {
	// std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm("ShrubberyCreationForm", false, 145, 137), _target(src._target) {
	// std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = src;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs) {
	// std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
	(void)rhs;
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return _target;
}

void ShrubberyCreationForm::execute(const Bureaucrat &rhs) const {
	executeCheck(rhs);
	std::string filename = _target + "_shrubbery";
	std::ofstream outputfile(filename.c_str());
	if (outputfile.is_open())
	{
		outputfile << "      /\\      " << std::endl;
		outputfile << "     /\\*\\     " << std::endl;
		outputfile << "    /\\O\\*\\    " << std::endl;
		outputfile << "   /*/\\/\\/\\   " << std::endl;
		outputfile << "  /\\O\\/\\*\\/\\  " << std::endl;
		outputfile << " /\\*\\/\\*\\/\\/\\ " << std::endl;
		outputfile << "/\\O\\/\\/*/\\/O/\\" << std::endl;
		outputfile << "      ||      " << std::endl;
		outputfile << "      ||      " << std::endl;
		outputfile << "      ||      " << std::endl;
		outputfile << "  =========" << std::endl;
		outputfile.close();
	}
	else
		std::cerr << "Error: could not create file" << std::endl;
}

std::ostream &operator<<(std::ostream &ost, const ShrubberyCreationForm &rhs) {
	return ost << rhs.getName() << ", form grade to sign " << rhs.getSignGrade() << ", form grade to execute " << rhs.getExecGrade() << ", form is " << rhs.getToSign() << ", target is " << rhs.getTarget();
}