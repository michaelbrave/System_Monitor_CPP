/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostnameModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 20:25:45 by jcruz-y-          #+#    #+#             */
/*   Updated: 2020/01/26 19:25:15 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../includes/ft_gkrellm.h"
#include "../includes/HostnameModule.hpp"

// Returns hostname for the local computer
void HostnameModule::ErrorcheckHostName(int hostname)
{
    if (hostname == -1)
    {
        perror("gethostname");
        exit(1);
    }
}

// Returns host information corresponding to host name
void HostnameModule::ErrorcheckHostEntry(struct hostent * hostentry)
{
    if (hostentry == NULL)
    {
        perror("gethostbyname");
        exit(1);
    }
}

// Converts space-delimited IPv4 addresses
// to dotted-decimal format
void HostnameModule::ErrorcheckIPbuffer(char *IPbuffer)
{
    if (NULL == IPbuffer)
    {
        perror("inet_ntoa");
        exit(1);
    }
}

void HostnameModule::OurgetHostName()
{
    char hostbuffer[256];
    char *IPbuffer;
    struct hostent *host_entry;
    int hostname;

    // To retrieve hostname
    hostname = gethostname(hostbuffer, sizeof(hostbuffer));
    this->ErrorcheckHostName(hostname);

    // To retrieve host information
    host_entry = gethostbyname(hostbuffer);
    this->ErrorcheckHostEntry(host_entry);

    // To convert an Internet network
    // address into ASCII string
    IPbuffer = inet_ntoa(*((struct in_addr*) host_entry->h_addr_list[0]));
    this->ErrorcheckIPbuffer(IPbuffer);

	this->_output = hostbuffer;
    //printf("Hostname: %s\n", hostbuffer);
    //printf("Host IP: %s", IPbuffer);

    // or use terminal commands and awk it
    // bash echo $HOSTNAME
    // bash uname -n
}

std::string	HostnameModule::getOutput() const
{
	return this->_output;
}

std::string	getUser()
{
	return (getenv("USER"));
}

// struct utsname		getOS()
// {
// 	struct utsname buffer;

// 	errno = 0;
// 	if (uname(&buffer) != 0) {
// 		perror("uname");
// 		exit(EXIT_FAILURE);
// 	}
//     std::cout << "System Name: " << buffer.sysname << std::endl;
//     std::cout << "Host Name: " << buffer.nodename << std::endl;
//     std::cout << "Release(Kernel) Version: " << buffer.release << std::endl;
//     std::cout << "Kernel Build Timestamp: " << buffer.version << std::endl;
//     std::cout << "Machine Arch: " << buffer.machine << std::endl;
// 	return buffer;
// }


void	HostnameModule::update(WINDOW *w, int *y)
{
	struct utsname buffer;
	errno = 0;
	if (uname(&buffer) != 0) {
		perror("uname");
		throw std::exception();
	}
	this->OurgetHostName();
	mvwprintw(w, (*y)++, getbegx(w)/2, "  - - - - - - - Hostname - - - - - - - - - ");
    wattron(w, COLOR_PAIR(6));
	
	mvwprintw(w, (*y)++, getbegx(w) + 2, "User Name: %s", getenv("USER"));
	mvwprintw(w, (*y)++, getbegx(w) + 2, "Host Name: %s", buffer.nodename);
	
    wattroff(w, COLOR_PAIR(6));
    mvwprintw(w, (*y)++, getbegx(w)/2, "  - - - - - - - - - - - - - - - - - - - - - ");
}

HostnameModule::~HostnameModule( void ) {

	//std::cout << "HostnameModule destructor called\n";
	return;
}


HostnameModule::HostnameModule( void )
{
	this->_name = "hostname";
	std::cout << "HostnameModule default constructor called\n";
    return;
}



HostnameModule::HostnameModule( HostnameModule const & src ) //: _foo(src.getFoo()) 
{
	std::cout << "Copy constructor called\n";
	*this = src;
	return;
}

HostnameModule& HostnameModule::operator=( const HostnameModule &rhs_operand )
{
    (void)rhs_operand;
	std::cout << "HostnameModule assignment constructor called\n";
	// some assignment ex: this->_fixed_point_val = rhs_operand.getRawBits();
	return (*this);
}



