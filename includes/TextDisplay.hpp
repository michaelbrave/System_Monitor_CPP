/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TextDisplay.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 20:25:45 by jcruz-y-          #+#    #+#             */
/*   Updated: 2020/01/26 15:22:57 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTDISPLAY_H
# define TEXTDISPLAY_H
#include <iostream>
#include <string>
#include <stdexcept>
#include "ft_gkrellm.h"
#include <list>
#include <vector>
#include <ncurses.h>

class IMonitorModule;

class TextDisplay{

public:

    TextDisplay( void );               // default constructor
    TextDisplay( std::list<std::string> args, int argc );        // 
    TextDisplay( TextDisplay const &src ); // copy constructor, taking as a param 
                                  // instance of this class and making a copy
    virtual ~TextDisplay( void );

    TextDisplay &operator=( const TextDisplay &rhs ); // Operator overload to update the
                                              // current instance (make assignments
                                              // of this class

    
    std::list<std::string>  getArgs() const;

    void    run();
    void    createModules();
    void    reload();
    void    refresh( void );

//private:

    std::vector<IMonitorModule*>    _modules;
    std::list<std::string>          _args;
    WINDOW*                         _win;
    int                             _argc;
    int                             _y;
    

};

#endif

