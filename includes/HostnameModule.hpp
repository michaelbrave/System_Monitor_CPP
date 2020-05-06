/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostnameModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 20:25:45 by jcruz-y-          #+#    #+#             */
/*   Updated: 2020/01/26 16:21:47 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOSTNAMEMODULE_H
# define HOSTNAMEMODULE_H
#include <iostream>
#include <string>
#include <stdexcept>
#include "ft_gkrellm.h"

class IMonitorModule;

class HostnameModule : public IMonitorModule
{

public:

    HostnameModule( void );               // default constructor
    //HostnameModule( int const n );        // 
    HostnameModule( HostnameModule const &src ); // copy constructor, taking as a param 
    //                               // instance of this class and making a copy
    HostnameModule &operator=( const HostnameModule &rhs ); // Operator overload to update the
    virtual ~HostnameModule( void );

                                              // current instance (make assignments
                                              // of this class
    void    OurgetHostName();
    void    ErrorcheckIPbuffer(char *IPbuffer);
    void    ErrorcheckHostEntry(struct hostent * hostentry);
    void    ErrorcheckHostName(int hostname);
    std::string     getOutput( void ) const;
    void    update(WINDOW *w, int *y);
    

private:
    
    std::string _output;
    std::string _name;

};

#endif

