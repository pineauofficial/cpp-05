/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:36:54 by pineau            #+#    #+#             */
/*   Updated: 2024/03/01 17:25:11 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	AForm	*vif = 0;

	try
	{
		Bureaucrat	gerald = Bureaucrat("Gerald", 5);
		
		vif = new ShrubberyCreationForm("Norminet's garden");

		std::cout << *vif << "\n\n";
		gerald.executeForm(*vif);
		gerald.signForm(*vif);
		std::cout << *vif << "\n\n";
		gerald.executeForm(*vif);

		std::cout << "\n\n";

		delete vif;
		vif = new RobotomyRequestForm("Marvin");
		gerald.signForm(*vif);
		std::cout << *vif << "\n\n";

		for (int i = 0; i < 13; i++)
			gerald.executeForm(*vif);

		std::cout << "\n\n";

		delete vif;
		vif = new PresidentialPardonForm("Marvin");
		gerald.signForm(*vif);
		std::cout << *vif << "\n\n";
		gerald.executeForm(*vif);
	
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete vif;
}
