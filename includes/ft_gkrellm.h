/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gkrellm.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:01:19 by jcruz-y-          #+#    #+#             */
/*   Updated: 2020/01/26 18:10:27 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GKRELLM_H
# define FT_GKRELLM_H

#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"
#include "TextDisplay.hpp"
#include "GraphicalDisplay.hpp"
#include "CpuModule.hpp"
#include "DateTimeModule.hpp"
#include "HostnameModule.hpp"
#include "NewtowrkModule.hpp"
#include "RamModule.hpp"
#include "OsInfoModule.hpp"
#include "FCat.hpp"

#include <ncurses.h>
#include <curses.h>

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <stdexcept>

// for ram available
#include <sys/types.h>
#include <sys/sysctl.h>

// for ram used
#include <mach/vm_statistics.h>
#include <mach/mach_types.h>
#include <mach/mach_init.h>
#include <mach/mach_host.h>

// for get hostname
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// for get cpu
#include <mach/mach_init.h>
#include <mach/mach_error.h>
#include <mach/mach_host.h>
#include <mach/vm_map.h>

// for os info and time
#include <sys/utsname.h>
#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>

#endif