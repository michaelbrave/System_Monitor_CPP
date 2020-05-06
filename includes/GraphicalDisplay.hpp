/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicalDisplay.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 20:25:45 by jcruz-y-          #+#    #+#             */
/*   Updated: 2020/01/26 06:26:39 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICALDISPLAY_H
# define GRAPHICALDISPLAY_H
#include <iostream>
#include <string>
#include <stdexcept>

class GraphicalDisplay{

public:

    GraphicalDisplay( void );               // default constructor
    GraphicalDisplay( int const n );        // 
    GraphicalDisplay( GraphicalDisplay const &src ); // copy constructor, taking as a param 
                                  // instance of this class and making a copy
    ~GraphicalDisplay( void );

    GraphicalDisplay &operator=( const GraphicalDisplay &rhs ); // Operator overload to update the
                                              // current instance (make assignments
                                              // of this class

private:


};

#endif

