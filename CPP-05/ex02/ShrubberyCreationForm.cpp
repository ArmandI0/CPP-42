/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:18:52 by aranger           #+#    #+#             */
/*   Updated: 2024/05/30 10:41:22 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string Target) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->_Target = Target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &cpy)
{
	*this = cpy;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const &cpy)
{
	this->_Target = cpy._Target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::string outName = this->_Target;
	outName.append("_shrubbery");
	std::ofstream outfile;

	if (this->getGradeToExec() < executor.getGrade())
		throw Bureaucrat::GradeTooLowException();
	if (this->getStatusAForm() == false)
		throw AForm::NeedToBeSigned();
	try
	{
		outfile.open(outName.c_str());
		if (outfile.is_open() == false)
			throw std::runtime_error("Unable to open file: " + outName);
	}
	catch(std::runtime_error& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return ;
	}
	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
	outfile << "###########################'`################################" << std::endl
	<< "###########################  V##'############################" << std::endl
	<< "#########################V'  `V  ############################" << std::endl
	<< "########################V'      ,############################" << std::endl
	<< "#########`#############V      ,A###########################V" << std::endl
	<< "########' `###########V      ,###########################V',#" << std::endl
	<< "######V'   ###########l      ,####################V~~~~'',###" << std::endl
	<< "#####V'    ###########l      ##P' ###########V~~'   ,A#######" << std::endl
	<< "#####l      d#########l      V'  ,#######V~'       A#########" << std::endl
	<< "#####l      ##########l         ,####V''         ,###########" << std::endl
	<< "#####l        `V######l        ,###V'   .....;A##############" << std::endl
	<< "#####A,         `######A,     ,##V' ,A#######################" << std::endl
	<< "#######A,        `######A,    #V'  A########'''''##########''" << std::endl
	<< "##########,,,       `####A,           `#''           '''  ,,," << std::endl
	<< "#############A,                               ,,,     ,######" << std::endl
	<< "######################oooo,                 ;####, ,#########" << std::endl
	<< "##################P'                   A,   ;#####V##########" << std::endl
	<< "#####P'    ''''       ,###             `#,     `V############" << std::endl
	<< "##P'                ,d###;              ##,       `V#########" << std::endl
	<< "##########A,,   #########A              )##,    ##A,..,ooA###" << std::endl
	<< "#############A, Y#########A,            )####, ,#############" << std::endl
	<< "###############A ############A,        ,###### ##############" << std::endl
	<< "###############################       ,#######V##############" << std::endl
	<< "###############################      ,#######################" << std::endl
	<< "##############################P    ,d########################" << std::endl
	<< "##############################'    d#########################" << std::endl
	<< "##############################     ##########################" << std::endl
	<< "##############################     ##########################" << std::endl
	<< "#############################P     ##########################" << std::endl
	<< "#############################'     ##########################" << std::endl
	<< "############################P      ##########################" << std::endl
	<< "###########################P'     ;##########################" << std::endl
	<< "###########################'     ,###########################" << std::endl
	<< "##########################       ############################" << std::endl
	<< "#########################       ,############################" << std::endl
	<< "########################        d###########P'    `Y#########" << std::endl
	<< "#######################        ,############        #########" << std::endl
	<< "######################        ,#############        #########" << std::endl
	<< "#####################        ,##############b.    ,d#########" << std::endl
	<< "####################        ,################################" << std::endl
	<< "###################         #################################" << std::endl
	<< "##################          #######################P'  `V##P'" << std::endl
	<< "#######P'     `V#           ###################P'" << std::endl
	<< "#####P'                    ,#################P'" << std::endl
	<< "###P'                      d##############P''" << std::endl
	<< "##P'                       V##############'" << std::endl
	<< "#P'                         `V###########'" << std::endl
	<< "#'                             `V##P'" << std::endl;
}
