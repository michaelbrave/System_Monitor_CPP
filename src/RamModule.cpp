/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RamModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 20:25:45 by jcruz-y-          #+#    #+#             */
/*   Updated: 2020/01/26 16:35:16 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_gkrellm.h"

int RamModule::totalRamAvailable() //returns a zero?
{
    int mib[2];
    size_t length;
    int64_t physical_memory;
    mib[0] = CTL_HW;
    mib[1] = HW_MEMSIZE;
    length = sizeof(int64_t);
    //printf("%d", sysctl(mib, 2, &physical_memory, &length, NULL, 0));
	return (sysctl(mib, 2, &physical_memory, &length, NULL, 0));
}

void	RamModule::update(WINDOW* w, int *y)
{
	vm_size_t page_size;
    mach_port_t mach_port;
    mach_msg_type_number_t count;
    vm_statistics64_data_t vm_stats;
    mach_port = mach_host_self();
    count = sizeof(vm_stats) / sizeof(natural_t);
    if (KERN_SUCCESS == host_page_size(mach_port, &page_size) &&
        KERN_SUCCESS == host_statistics64(mach_port, HOST_VM_INFO,
                                        (host_info64_t)&vm_stats, &count))
    {
        long long free_memory = (int64_t)vm_stats.free_count * (int64_t)page_size;
        long long used_memory = ((int64_t)vm_stats.active_count +
                                 (int64_t)vm_stats.inactive_count +
                                 (int64_t)vm_stats.wire_count) *  (int64_t)page_size;
	
	mvwprintw(w, (*y)++, getbegx(w)/2, "  - - - - - - -   RAM   - - - - - - - - - ");
    wattron(w, COLOR_PAIR(4));
	mvwprintw(w, (*y)++, getbegx(w) + 2, "Free memory: %lld", free_memory);
	mvwprintw(w, (*y)++, getbegx(w) + 2, "Used memory: %lld", used_memory);
	//mvwprintw(w, (*y)++, getbegx(w) + 2, "Total memory: %d", this->totalRamAvailable());
    wattroff(w, COLOR_PAIR(4));
    mvwprintw(w, (*y)++, getbegx(w)/2, "  - - - - - - - - - - - - - - - - - - - -  ");
	}
}

RamModule::RamModule( void ) //: _foo( 0 )
{
	std::cout << "RamModule default constructor called\n";
    return;
}


RamModule::RamModule( int const n ) //: _foo( n ) 
{
	(void)n;
    std::cout << "RamModule parametric Constructor called\n";
	return;
}

RamModule::RamModule( RamModule const & src ) //: _foo(src.getFoo()) 
{
	std::cout << "Copy constructor called\n";
	*this = src;
	return;
}

RamModule& RamModule::operator=( const RamModule &rhs_operand )
{
    (void)rhs_operand;
	std::cout << "RamModule assignment constructor called\n";
	// some assignment ex: this->_fixed_point_val = rhs_operand.getRawBits();
	return (*this);
}

RamModule::~RamModule( void ) {

	//std::cout << "RamModule destructor called\n";
	return;
}


