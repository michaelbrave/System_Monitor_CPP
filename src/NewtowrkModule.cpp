/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NewtowrkModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 20:25:45 by jcruz-y-          #+#    #+#             */
/*   Updated: 2020/01/26 19:18:52 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/ft_gkrellm.h"



void *network(void *s)
{
	FILE *f = popen("netstat -w1", "r");

	if (!f)
		return s;

	char buf[4096];

	long input = 0;
	long output = 0;

	while (fgets(buf, 4096, f) != NULL)
	{
		std::string line(buf);

		if (line.compare(0, 17, "            input") == 0 ||
				line.compare(0, 10, "   packets") == 0)
			continue;

		long a;
		std::stringstream ss(line);

		ss >> a; // packets
		ss >> a; // errs
		ss >> input; // bytes
		ss >> a; // packets
		ss >> a; // errs
		ss >> output; // bytes

		std::stringstream ss2;

		ss2 << input;
		ss2 << "/s in, ";
		ss2 << output;
		ss2 << "/s out";

		*reinterpret_cast<std::string *>(s) = ss2.str();
	}

	return s;
}

#include <sstream>
#include <fstream>
#include <vector>


void	NewtowrkModule::update(WINDOW *w, int *y)
{

    std::system("nettop -J bytes_in,bytes_out -x -l1 > ./netinfo");
    std::ifstream				netinfos("./netinfo");
	std::string					netline = "";
	std::vector<std::string>			net;

	long	packet_in = 0;
	long	packet_out = 0;
	int		i = 0;

	while (getline(netinfos, netline, ' '))
	{
		if (netline != "" && (netline.find_first_not_of("0123456789") == std::string::npos))
		{
			if (i % 2 == 0)
				packet_in = packet_in + stol(netline);
			else
				packet_out = packet_out + stol(netline);
			i++;
		}
	}

	std::stringstream 			strcnvrt;

	

	
	//std::cout << strcnvrt.str() << std::endl; //replace this

	


	//this->_output = ;
	//this->OurgetHostName();
//	std::string s;
	mvwprintw(w, (*y)++, getbegx(w)/2, "  - - - - - - -  Network  - - - - - - - - - ");
    wattron(w, COLOR_PAIR(5));

	//network(&s);
	//mvwprintw(w, (*y)++, getbegx(w) + 2, "%s", s.c_str()); //this->getOutput().c_str());
	strcnvrt << "Packets In: " << packet_in;
	//std::cout << strcnvrt.str() << std::endl; //replace this
	
	mvwprintw(w, (*y)++, getbegx(w) + 2, "%s", strcnvrt.str().c_str());
	strcnvrt.str("");
	strcnvrt << "Packets Out: " << packet_out;
	mvwprintw(w, (*y)++, getbegx(w) + 2, "%s", strcnvrt.str().c_str());

    wattroff(w, COLOR_PAIR(5));
    mvwprintw(w, (*y)++, getbegx(w)/2, "  - - - - - - - - - - - - - - - - - - - -  ");
	netinfos.close();
}

NewtowrkModule::NewtowrkModule( void ) : IMonitorModule() //: _foo( 0 )
{
	std::cout << "NewtowrkModule default constructor called\n";
    return;
}


// NewtowrkModule::NewtowrkModule( int const n ) //: _foo( n ) 
// {
// 	(void)n;
//     std::cout << "NewtowrkModule parametric Constructor called\n";
// 	return;
// }

NewtowrkModule::NewtowrkModule( NewtowrkModule const & src ) //: _foo(src.getFoo()) 
{
	std::cout << "Copy constructor called\n";
	*this = src;
	return;
}

NewtowrkModule& NewtowrkModule::operator=( const NewtowrkModule &rhs_operand )
{
    (void)rhs_operand;
	std::cout << "NewtowrkModule assignment constructor called\n";
	// some assignment ex: this->_fixed_point_val = rhs_operand.getRawBits();
	return (*this);
}

NewtowrkModule::~NewtowrkModule( void ) {

	//std::cout << "NewtowrkModule destructor called\n";
	return;
}


