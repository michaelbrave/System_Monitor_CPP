/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TextDisplay.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 20:25:45 by jcruz-y-          #+#    #+#             */
/*   Updated: 2020/01/26 19:32:10 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_gkrellm.h"
//#include "../includes/HostnameModule.hpp"
//#include <list>

class HostnameModule;

std::list<std::string> TextDisplay::getArgs() const
{
	return (this->_args);
}

void	TextDisplay::refresh()
{
	mvwprintw(this->_win, getbegy(this->_win), getbegx(this->_win) + 2, "*************************", this->_modules.size());
	wrefresh(this->_win);
	mvwprintw(this->_win, getbegy(this->_win), getbegx(this->_win) + 2, "*************************", this->_modules.size());
}

void	TextDisplay::run()
{
	std::vector<IMonitorModule*>::iterator it;

	int		tick = 0;
	int		ch;

	ch = getch();
	clear();
	while (ch != 'q')
	{
		this->_y = getbegy(this->_win) + 2;
		it = this->_modules.begin();
		while (it != this->_modules.end())
		{
			(*it)->update(this->_win, &this->_y);
			it++;
		}
    	wborder(this->_win, 0, 0, 0, 0, 0, 0, 0, 0);
		mvwprintw(this->_win, getmaxy(this->_win) - 3, getmaxx(this->_win)/2 - 8, "%s", "Press 'q' to exit");
		wrefresh(this->_win);
		tick++;
		ch = getch();
	}
}

TextDisplay::TextDisplay( void ) //: _foo( 0 )
{
    return;
}

TextDisplay::TextDisplay( std::list<std::string> args , int argc) : _args(args), _argc(argc)
{

	//(void)n;
    std::cout << " args " << args.size() << '\n';
    //std::cout << " args " << this->_args.size() << '\n';
    std::cout << "TextDisplay parametric Constructor called\n";
	std::srand(time(NULL));
	//this->_modules = std::vector<IMonitorModule*>(s);
    //time_t  timer;
    //this->_starttime = time(&timer);
    
	/* determine the terminal type, including its size and 
    features, and sets up the curses environment 
    based on what the terminal can support*/
    initscr();

    /* disable line buffering and sets curses
     to take one character at a time*/
    cbreak();

    /* tell curses not to echo the input back to the screen*/
    noecho();
    clear();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    this->_win = newwin(LINES, COLS, 0, 0);
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_BLUE, COLOR_BLACK);
    refresh();
	return;
}

TextDisplay::TextDisplay( TextDisplay const & src ) //: _foo(src.getFoo()) 
{
	std::cout << "Copy constructor called\n";
	*this = src;
	return;
}

TextDisplay& TextDisplay::operator=( const TextDisplay &rhs_operand )
{
    (void)rhs_operand;
	std::cout << "TextDisplay assignment constructor called\n";
	// some assignment ex: this->_fixed_point_val = rhs_operand.getRawBits();
	return (*this);
}

TextDisplay::~TextDisplay( void ) {
    delwin(this->_win);
	endwin();

	return;
}


