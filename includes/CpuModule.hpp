/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CpuModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 20:25:45 by jcruz-y-          #+#    #+#             */
/*   Updated: 2020/01/26 17:10:13 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUMODULE_H
# define CPUMODULE_H
#include <iostream>
#include <string>
#include <stdexcept>
#include "ft_gkrellm.h"

class CpuModule : public IMonitorModule
{

public:

    CpuModule( void );               // default constructor
    CpuModule( int const n );        // 
    CpuModule( CpuModule const &src ); // copy constructor, taking as a param 
                                  // instance of this class and making a copy
    ~CpuModule( void );

    CpuModule &operator=( const CpuModule &rhs ); // Operator overload to update the
                                              // current instance (make assignments
                                              // of this class

    float       calculateCpuLoad(unsigned long long idleTicks, unsigned long long totalTicks);
    float       getCpuLoad();
    void        update(WINDOW *w, int *y);
    std::string exec(const char *cmd);

private:


};

#endif

