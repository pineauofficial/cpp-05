/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:36:54 by pineau            #+#    #+#             */
/*   Updated: 2024/03/29 14:37:27 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		std::cout << "First try" << std::endl;
		Bureaucrat a("Jean", 50);
		std::cout << a << std::endl;
	}
	catch(std::exception const & e) {
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b("Paul", 150);
		std::cout << "Second try" << std::endl;
		b.decrementGrade();
	}
	catch(std::exception const & e) {
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat c("Jacques", 1);
		std::cout << "Third try" << std::endl;
		c.incrementGrade();
	}
	catch(std::exception const & e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
