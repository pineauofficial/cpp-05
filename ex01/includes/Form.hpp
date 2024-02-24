/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:46:01 by pineau            #+#    #+#             */
/*   Updated: 2024/02/24 15:43:08 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class Form {
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

		Form(std::string name, bool toSign,int signGrade, int execGrade);
		~Form();

		void		beSigned(Bureaucrat const &rhs);

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

std::ostream &operator<<(std::ostream &ost, const Form &rhs);

#endif