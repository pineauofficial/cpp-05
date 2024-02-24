/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:36:54 by pineau            #+#    #+#             */
/*   Updated: 2024/02/24 15:56:59 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		std::cout <<"----- First try -----" << std::endl;
		Bureaucrat a("Jean", 50);
		std::cout << a << std::endl;
		Form f("Formulaire 1", false, 50, 50);
		std::cout << f << std::endl;
		a.signForm(f);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout <<"----- Second try -----" << std::endl;
		Bureaucrat b("Paul", 150);
		std::cout << b << std::endl;
		Form g("Formulaire 2", false, 50, 150);
		std::cout << g << std::endl;
		b.signForm(g);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout <<"----- Third try -----" << std::endl;
		Bureaucrat c("Jacques", 10);
		std::cout << c << std::endl;
		Form h("Formulaire 3", false, 10, 1);
		std::cout << h << std::endl;
		c.signForm(h);
		std::cout << h << std::endl;
		Bureaucrat cc ("Jacques", 10);
		cc.signForm(h);
		std::cout << h << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
