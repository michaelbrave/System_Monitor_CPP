/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicalDisplay.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 20:25:45 by jcruz-y-          #+#    #+#             */
/*   Updated: 2020/01/26 07:21:06 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/GraphicalDisplay.hpp"

GraphicalDisplay::GraphicalDisplay( void ) //: _foo( 0 )
{
	std::cout << "GraphicalDisplay default constructor called\n";
    return;
}


GraphicalDisplay::GraphicalDisplay( int const n ) //: _foo( n ) 
{
	(void)n;
    std::cout << "GraphicalDisplay parametric Constructor called\n";
	return;
}

GraphicalDisplay::GraphicalDisplay( GraphicalDisplay const & src ) //: _foo(src.getFoo()) 
{
	std::cout << "Copy constructor called\n";
	*this = src;
	return;
}

GraphicalDisplay& GraphicalDisplay::operator=( const GraphicalDisplay &rhs_operand )
{
    (void)rhs_operand;
	std::cout << "GraphicalDisplay assignment constructor called\n";
	// some assignment ex: this->_fixed_point_val = rhs_operand.getRawBits();
	return (*this);
}

GraphicalDisplay::~GraphicalDisplay( void ) {

	//std::cout << "GraphicalDisplay destructor called\n";
	return;
}


