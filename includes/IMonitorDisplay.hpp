/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 20:25:45 by jcruz-y-          #+#    #+#             */
/*   Updated: 2020/01/26 07:57:53 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_H
# define IMONITORDISPLAY_H
#include <iostream>
#include <string>
#include <stdexcept>

class IMonitorDisplay{

public:

    //IMonitorDisplay( void );               // default constructor
    // IMonitorDisplay( int const n );        // 
    //IMonitorDisplay( IMonitorDisplay const &src ); // copy constructor, taking as a param 
                                  // instance of this class and making a copy
    virtual ~IMonitorDisplay( void ) = 0;

    //IMonitorDisplay &operator=( const IMonitorDisplay &rhs ); // Operator overload to update the
                                              // current instance (make assignments
                                              // of this class

    //virtual void refresh();
    //virtual void run();

//private:


};

#endif

