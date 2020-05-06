/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 20:25:45 by jcruz-y-          #+#    #+#             */
/*   Updated: 2020/01/26 15:22:34 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_H
# define IMONITORMODULE_H
#include <iostream>
#include <string>
#include <stdexcept>
#include "ft_gkrellm.h"
#include <ncurses.h>
//#include "HostnameModule.hpp"

class IMonitorModule{

public:

    // IMonitorModule( void );               // default constructor
    // IMonitorModule( int const n );        // 
    //IMonitorModule( IMonitorModule const &src ); // copy constructor, taking as a param 
                                  // instance of this class and making a copy
    virtual void    update(WINDOW* win, int *y) = 0;
    virtual ~IMonitorModule( void ) {};

    //IMonitorModule &operator=( const IMonitorModule &rhs ); // Operator overload to update the
    
//    virtual int getFoo( void ) const;
    // virtual void run();
//private:

};

#endif

