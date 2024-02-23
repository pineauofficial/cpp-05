/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:36:54 by pineau            #+#    #+#             */
/*   Updated: 2024/02/23 18:40:36 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat a("Jean", 50);
	Bureaucrat b("Paul", 150);
	Bureaucrat c("Jacques", 1);
	try
	{
		std::cout << "First try" << std::endl;
		Bureaucrat d("Marie", 155);
	}
	catch(std::exception const & e) {
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "Second try" << std::endl;
		b.decrementGrade();
	}
	catch(std::exception const & e) {
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "Third try" << std::endl;
		c.incrementGrade();
	}
	catch(std::exception const & e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << a << std::endl;
	return 0;
}
