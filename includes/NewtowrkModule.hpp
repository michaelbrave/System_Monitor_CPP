/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NewtowrkModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 20:25:45 by jcruz-y-          #+#    #+#             */
/*   Updated: 2020/01/26 19:28:41 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEWTOWRKMODULE_H
# define NEWTOWRKMODULE_H
#include <iostream>
#include <string>
#include <stdexcept>
#include "ft_gkrellm.h"

class NewtowrkModule : public IMonitorModule
{

public:

    NewtowrkModule( void );               // default constructor
    NewtowrkModule( int const n );        // 
    NewtowrkModule( NewtowrkModule const &src ); // copy constructor, taking as a param 
                                  // instance of this class and making a copy
    ~NewtowrkModule( void );

    NewtowrkModule &operator=( const NewtowrkModule &rhs ); // Operator overload to update the
                                              // current instance (make assignments
                                              // of this class

    void         update(WINDOW *w, int *y);
    void         network(void *s);
    int          getFoo( void ) const;

private:

    int  _foo;

};

#endif

