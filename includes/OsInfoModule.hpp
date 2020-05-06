/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OsInfoModule.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 20:25:45 by jcruz-y-          #+#    #+#             */
/*   Updated: 2020/01/26 15:22:55 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSINFOMODULE_H
# define OSINFOMODULE_H
#include <iostream>
#include <string>
#include <stdexcept>
#include "ft_gkrellm.h"

//class IMonitorModule;

class OsInfoModule : public IMonitorModule 
{

public:

    OsInfoModule( void );               // default constructor
    OsInfoModule( int const n );        // 
    OsInfoModule( OsInfoModule const &src ); // copy constructor, taking as a param 
                                  // instance of this class and making a copy
    ~OsInfoModule( void );

    OsInfoModule &operator=( const OsInfoModule &rhs ); // Operator overload to update the
                                              // current instance (make assignments
                                              // of this class

    void update(WINDOW *w, int *y);
    int getFoo( void ) const;

private:

    int  _foo;
    std::string _name;

};

#endif

