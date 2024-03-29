/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:37:40 by pineau            #+#    #+#             */
/*   Updated: 2024/03/29 14:47:12 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
	public:
		class GradeTooHighException : public std::exception {
			public:
				GradeTooHighException(void) throw() {}
				~GradeTooHighException(void) throw() {}
				const char * what() const throw()
				{
					return (char *)("Grade is too high");
				}	
		};
		class GradeTooLowException : public std::exception {
			public:
				GradeTooLowException(void) throw() {}
				~GradeTooLowException(void) throw() {}
				const char * what() const throw()
				{
					return (char *)("Grade is too low");
				}		
		};
		
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(Bureaucrat const & rhs);
		Bureaucrat & operator=(Bureaucrat const & rhs);
		Bureaucrat & operator<<(Bureaucrat const & rhs);

		void incrementGrade();
		void decrementGrade();
		void signForm(AForm &rhs);
		void executeForm(AForm &rhs) const;
		
		std::string getName() const;
		int getGrade() const;
	
	private:
		std::string const _name;
		int			_grade;
};

std::ostream &operator<<(std::ostream &ost, const Bureaucrat &rhs);

#endif