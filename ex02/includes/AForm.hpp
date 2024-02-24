/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:46:01 by pineau            #+#    #+#             */
/*   Updated: 2024/02/24 16:24:20 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class AForm {
	public :
		class GradeTooHighException : public std::exception {
			public:
				const char * what() const throw()
				{
					return ("Grade is too high");
				}	
		};
		class GradeTooLowException : public std::exception {
			public:
				const char * what() const throw()
				{
					return ("Grade is too low");
				}		
		};

		AForm(std::string name, bool toSign,int signGrade, int execGrade);
		~AForm();

		void		beSigned(Bureaucrat const &rhs) = 0;

		std::string getName() const;
		bool		getToSign() const;
		int			getSignGrade() const;
		int			getExecGrade() const;
	private :
		std::string const	_name;
		bool				_toSign;
		int const			_signGrade;
		int const			_execGrade;
};

std::ostream &operator<<(std::ostream &ost, const AForm &rhs);

#endif