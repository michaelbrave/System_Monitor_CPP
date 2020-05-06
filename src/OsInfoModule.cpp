/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OsInfoModule.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 20:25:45 by jcruz-y-          #+#    #+#             */
/*   Updated: 2020/01/26 16:37:54 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_gkrellm.h"

void	OsInfoModule::update(WINDOW *w, int *y)
{
	struct utsname buffer;
	errno = 0;
	if (uname(&buffer) != 0) {
		perror("uname");
		throw std::exception();
	}
	//this->_output = ;
	//this->OurgetHostName();
	mvwprintw(w, (*y)++, getbegx(w)/2, "  - - - - - - -  OS Info  - - - - - - - - - ");
    wattron(w, COLOR_PAIR(3));
	mvwprintw(w, (*y)++, getbegx(w) + 2, "System Name: %s", buffer.sysname);
	mvwprintw(w, (*y)++, getbegx(w) + 2, "Realease (Kernel) Verion: %s", buffer.release);
	mvwprintw(w, (*y)++, getbegx(w) + 2, "Machine Arch: %s", buffer.machine);
	mvwprintw(w, (*y)++, getbegx(w) + 2, "Kernel Build Timestamp:");
	mvwprintw(w, (*y)++, getbegx(w) + 2, "%40s", buffer.version);
    wattroff(w, COLOR_PAIR(3));
    mvwprintw(w, (*y)++, getbegx(w)/2, "  - - - - - - - - - - - - - - - - - - - -  ");
	
}

OsInfoModule::OsInfoModule( void ) : IMonitorModule()//: _foo( 0 )
{
	this->_name = "OS info";
	std::cout << "OsInfoModule default constructor called\n";
    return;
}

OsInfoModule::OsInfoModule( OsInfoModule const & src ) //: _foo(src.getFoo()) 
{
	std::cout << "Copy constructor called\n";
	*this = src;
	return;
}

OsInfoModule& OsInfoModule::operator=( const OsInfoModule &rhs_operand )
{
    (void)rhs_operand;
	std::cout << "OsInfoModule assignment constructor called\n";
	// some assignment ex: this->_fixed_point_val = rhs_operand.getRawBits();
	return (*this);
}

OsInfoModule::~OsInfoModule( void ) {

	//std::cout << "OsInfoModule destructor called\n";
	return;
}


