/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateTimeModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 20:25:45 by jcruz-y-          #+#    #+#             */
/*   Updated: 2020/01/26 16:08:04 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATETIMEMODULE_H
# define DATETIMEMODULE_H
#include <iostream>
#include <string>
#include <stdexcept>
#include "ft_gkrellm.h"


class DateTimeModule : public IMonitorModule
{

public:

    DateTimeModule( void );               // default constructor
    DateTimeModule( int const n );        // 
    DateTimeModule( DateTimeModule const &src ); // copy constructor, taking as a param 
                                  // instance of this class and making a copy
    ~DateTimeModule( void );

    DateTimeModule &operator=( const DateTimeModule &rhs ); // Operator overload to update the
                                              // current instance (make assignments
                                              // of this class

    void    update(WINDOW *w, int *y);
    char*   getTime();
    int getFoo( void ) const;

private:

    int  _foo;
    std::string _name;

};

#endif

