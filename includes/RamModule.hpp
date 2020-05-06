/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RamModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 20:25:45 by jcruz-y-          #+#    #+#             */
/*   Updated: 2020/01/26 16:32:28 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAMMODULE_H
# define RAMMODULE_H
#include <iostream>
#include <string>
#include <stdexcept>
#include "ft_gkrellm.h"

class RamModule : public IMonitorModule
{

public:

    RamModule( void );               // default constructor
    RamModule( int const n );        // 
    RamModule( RamModule const &src ); // copy constructor, taking as a param 
                                  // instance of this class and making a copy
    ~RamModule( void );

    RamModule &operator=( const RamModule &rhs ); // Operator overload to update the
                                              // current instance (make assignments
                                              // of this class

    int     totalRamAvailable();
    void    RAMUsed();
    void    update(WINDOW *w, int *y);
    int     getFoo( void ) const;

private:

    int  _foo;

};

#endif

