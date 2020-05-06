/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FCat.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 20:25:45 by jcruz-y-          #+#    #+#             */
/*   Updated: 2020/01/26 19:38:32 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FCat.hpp"

void	FCat::update(WINDOW *w, int *y)
{
	static int	g = 0;
	std::string c1 = "\n\
                *  ,MMM8&&&.            *    \n\
                  MMMM88&&&&&    .			 \n\
                 MMMM88&&&&&&&				 \n\
     *           MMM88&&&&&&&&				 \n\
                 MMM88&&&&&&&&				 \n\
                 'MMM88&&&&&&'				 \n\
                   'MMM8&&&'      *			 \n\
          |\\___/|							 \n\
          )     (        .              '	 \n\
         =\\     /=							 \n\
           )===(       *					 \n\
          /     \\							 \n\
          |     |							 \n\
         /       \\							 \n\
         \\       /							 \n\
  _/\\_/\\_/\\__  _/_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_\n\
  |  |  |  |( (  |  |  |  |  |  |  |  |  |  |\n\
  |  |  |  | ) ) |  |  |  |  |  |  |  |  |  |\n\
  |  |  |  |(_(  |  |  |  |  |  |  |  |  |  |\n\
  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |\n\
  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |\n";

  	std::string c2 ="\n\
             *     ,MMM8&&&.            *	\n\
                  MMMM88&&&&&    .			\n\
                 MMMM88&&&&&&&				\n\
     *           MMM88&&&&&&&&				\n\
                 MMM88&&&&&&&&				\n\
                 'MMM88&&&&&&'				\n\
                   'MMM8&&&'      *			\n\
          |\\___/|							\n\
         =) ^Y^ (=            .             \n\
          \\  ^  /							\n\
           )=*=(       *					\n\
          /     \\							\n\
          |     |							\n\
         /| | | |\\							\n\
         \\| | |_|/\\							 \n\
  jgs_/\\_//_// ___/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_\n\
  |  |  |  | \\_) |  |  |  |  |  |  |  |  |  |\n\
  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |\n\
  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |\n\
  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |\n\
  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |\n";

  	std::string c3 ="\n\
             *     ,MMM8&&&.            *    \n\
                  MMMM88&&&&&    .           \n\
                 MMMM88&&&&&&&				 \n\
     *           MMM88&&&&&&&&			     \n\
                 MMM88&&&&&&&&			     \n\
                 'MMM88&&&&&&'				 \n\
                   'MMM8&&&'      *    _	 \n\
          |\\___/|                      \\    \n\
         =) ^Y^ (=   |\\_/|              ||   \n\
          \\  ^  /    )a a '._.-""""-.  //    \n\
           )=*=(    =\\T_= /    ~  ~  \\//     \n\
          /     \\     `\"\\   ~   / ~  /      \n\
          |     |         |~   \\ |  ~/		 \n\
         /| | | |\\         \\  ~/- \\ ~\\		 \n\
         \\| | |_|/|        || |  // /`		 \n\
  jgs_/\\_//_// __//\\_/\\_/\\_((_|\\((_//\\_/\\_/\\_\n\
  |  |  |  | \\_) |  |  |  |  |  |  |  |  |  |\n\
  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |\n\
  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |\n\
  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |\n\
  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |\n";
  
	std::string c4 ="\n\
           *       ,MMM8&&&.          *     \n\
                  MMMM88&&&&&    .			 \n\
                 MMMM88&&&&&&&               \n\
     *           MMM88&&&&&&&&               \n\
                 MMM88&&&&&&&&               \n\
                 'MMM88&&&&&&'               \n\
                   'MMM8&&&'        *        \n\
          |\\___/|     /\\___/\\             \n\
          )     (     )    ~( . `  		     \n\
         =\\     /=   =\\~    /=			 \n\
           )===(       ) ~ (				 \n\
          /     \\     /     \\				 \n\
          |     |     ) ~   (				 \n\
         /       \\   /     ~ \\				 \n\
         \\       /   \\~     ~/			 \n\
  jgs_/\\_/\\__  _/_/\\_/\\__~__/_/\\_/\\_/\\_/\\_/\\_\n\
  |  |  |  |( (  |  |  | ))  |  |  |  |  |  |\n\
  |  |  |  | ) ) |  |  |//|  |  |  |  |  |  |\n\
  |  |  |  |(_(  |  |  (( |  |  |  |  |  |  |\n\
  |  |  |  |  |  |  |  |\\)|  |  |  |  |  |  |\n\
  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |\n";

	mvwprintw(w, (*y)++, getbegx(w), "%d", g);
	if (g < 1)
		mvwprintw(w, (*y)++, getbegx(w), "%s", c1.c_str());
	else if (g < 2)
		mvwprintw(w, (*y)++, getbegx(w), "%s", c2.c_str());
	else if (g < 4)
		mvwprintw(w, (*y)++, getbegx(w), "%s", c3.c_str());
	else if (g < 5)
		mvwprintw(w, (*y)++, getbegx(w), "%s", c4.c_str());
	else
		g = 0;
	g++;
}

FCat::FCat( void ) //: _foo( 0 )
{
	std::cout << "FCat default constructor called\n";
    return;
}


FCat::FCat( int const n ) //: _foo( n ) 
{
	(void)n;
    std::cout << "FCat parametric Constructor called\n";
	return;
}

FCat::FCat( FCat const & src ) //: _foo(src.getFoo()) 
{
	std::cout << "Copy constructor called\n";
	*this = src;
	return;
}

FCat& FCat::operator=( const FCat &rhs_operand )
{
    (void)rhs_operand;
	std::cout << "FCat assignment constructor called\n";
	// some assignment ex: this->_fixed_point_val = rhs_operand.getRawBits();
	return (*this);
}

FCat::~FCat( void ) {

	//std::cout << "FCat destructor called\n";
	return;
}


