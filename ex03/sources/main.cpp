/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:36:54 by pineau            #+#    #+#             */
/*   Updated: 2024/03/29 14:54:06 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main()
{
	Intern		eric;
	AForm *fr1;
	AForm *fs1;
	AForm *fp1;
	try
	{
		Bureaucrat	bob("Bob", 1);

		std::cout<<"\n";
		fr1 = eric.makeForm("robotomy request", "Jean");
		fs1 = eric.makeForm("shrubbery creation", "house1");
		fp1 = eric.makeForm("presidential pardon", "Jean");
		std::cout<<"\n";

		bob.signForm(*fr1);
		bob.signForm(*fs1);
		bob.signForm(*fp1);
		std::cout<<"\n";

		bob.executeForm(*fr1);
		std::cout<<"\n";
		bob.executeForm(*fs1);
		std::cout<<"\n";
		bob.executeForm(*fp1);
		std::cout<<"\n----------------------------------------";
	}
	catch (std::exception const &e)
	{
		std::cout<< e.what()<<std::endl;
	}

	delete fr1;
	delete fs1;
	delete fp1;

	try
	{
		std::cout<<"\n";
		Bureaucrat	jean("Jean", 150);

		std::cout<<"\n";
		fr1 = eric.makeForm("robotomy request", "Jean");
		fs1 = eric.makeForm("shrubbery creation", "house2");
		fp1 = eric.makeForm("presidential pardon", "Jean");
		std::cout<<"\n";

		jean.signForm(*fr1);
		jean.signForm(*fs1);
		jean.signForm(*fp1);
		std::cout<<"\n";

		jean.executeForm(*fr1);
		std::cout<<"\n";
		jean.executeForm(*fs1);
		std::cout<<"\n";
		jean.executeForm(*fp1);
		std::cout<<"\n";
	}
	catch (std::exception const &e)
	{
		std::cout<< e.what()<<std::endl;
	}

	delete fr1;
	delete fs1;
	delete fp1;

	try
	{
		std::cout<<"\n";
		Bureaucrat	bob("Bob", 1);
		Bureaucrat	marc("Marc", 42);
		Intern		eric;

		std::cout<<"\n";
		fr1 = eric.makeForm("robotomy request", "Jean");
		fs1 = eric.makeForm("shrubbery creation", "house3");
		fp1 = eric.makeForm("presidential pardon", "Jean");
		std::cout<<"\n";

		marc.signForm(*fr1);
		marc.signForm(*fs1);
		bob.signForm(*fp1);
		std::cout<<"\n";

		marc.executeForm(*fr1);
		std::cout<<"\n";
		marc.executeForm(*fs1);
		std::cout<<"\n";
		marc.executeForm(*fp1);
		std::cout<<"\n";
	}
	catch (std::exception const &e)
	{
		std::cout<< e.what()<<std::endl;
	}
	delete fr1;
	delete fs1;
	delete fp1;
	
	return (0);
}
