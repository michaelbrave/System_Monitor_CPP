/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FCat.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 20:25:45 by jcruz-y-          #+#    #+#             */
/*   Updated: 2020/01/26 18:13:14 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FCAT_H
# define FCAT_H
#include <iostream>
#include <string>
#include <stdexcept>
#include "ft_gkrellm.h"

class FCat : public IMonitorModule
{

public:

    FCat( void );               // default constructor
    FCat( int const n );        // 
    FCat( FCat const &src ); // copy constructor, taking as a param 
                                  // instance of this class and making a copy
    ~FCat( void );

    FCat &operator=( const FCat &rhs ); // Operator overload to update the
                                              // current instance (make assignments
                                              // of this class

    void    update(WINDOW *w, int *y);

private:

};

#endif

