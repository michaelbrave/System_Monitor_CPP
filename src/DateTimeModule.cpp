/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateTimeModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 20:25:45 by jcruz-y-          #+#    #+#             */
/*   Updated: 2020/01/26 16:09:23 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_gkrellm.h"

char* DateTimeModule::getTime()
{
	time_t unixTime;
	struct tm * timeLocal;
    time (&unixTime);
    timeLocal = localtime(&unixTime);
	return (asctime(timeLocal));
}

void	DateTimeModule::update(WINDOW *w, int *y)
{
	mvwprintw(w, (*y)++, getbegx(w)/2, "  - - - - - - -   Time   - - - - - - - - - ");
    wattron(w, COLOR_PAIR(2));
	mvwprintw(w, (*y)++, getbegx(w) + 2, "%s", getTime());
    wattroff(w, COLOR_PAIR(2));
    mvwprintw(w, (*y)++, getbegx(w)/2, "  - - - - - - - - - - - - - - - - - - - -  ");
}

DateTimeModule::DateTimeModule( void ) : IMonitorModule()
{
	this->_name = "DateTime";
	std::cout << "DateTimeModule default constructor called\n";
    return;
}


DateTimeModule::DateTimeModule( int const n ) //: _foo( n ) 
{
	(void)n;
    std::cout << "DateTimeModule parametric Constructor called\n";
	return;
}

DateTimeModule::DateTimeModule( DateTimeModule const & src ) //: _foo(src.getFoo()) 
{
	std::cout << "Copy constructor called\n";
	*this = src;
	return;
}

DateTimeModule& DateTimeModule::operator=( const DateTimeModule &rhs_operand )
{
    (void)rhs_operand;
	std::cout << "DateTimeModule assignment constructor called\n";
	// some assignment ex: this->_fixed_point_val = rhs_operand.getRawBits();
	return (*this);
}

DateTimeModule::~DateTimeModule( void ) {

	//std::cout << "DateTimeModule destructor called\n";
	return;
}


