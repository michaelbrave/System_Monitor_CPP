/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CpuModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 20:25:45 by jcruz-y-          #+#    #+#             */
/*   Updated: 2020/01/26 18:33:03 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_gkrellm.h"

static unsigned long long _previousTotalTicks = 0;
static unsigned long long _previousIdleTicks = 0;

// Returns 1.0f for "CPU fully pinned", 0.0f for "CPU idle", or somewhere in between
// You'll need to call this at regular intervals, since it measures the load between
// the previous call and the current one.

float CpuModule::calculateCpuLoad(unsigned long long idleTicks, unsigned long long totalTicks)
{
  unsigned long long totalTicksSinceLastTime = totalTicks-_previousTotalTicks;
  unsigned long long idleTicksSinceLastTime  = idleTicks-_previousIdleTicks;
  float ret = 1.0f-((totalTicksSinceLastTime > 0) ? ((float)idleTicksSinceLastTime)/totalTicksSinceLastTime : 0);
  _previousTotalTicks = totalTicks;
  _previousIdleTicks  = idleTicks;
  return ret;
}

float CpuModule::getCpuLoad()
{
   host_cpu_load_info_data_t cpuinfo;
   mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;
   if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, (host_info_t)&cpuinfo, &count) == KERN_SUCCESS)
   {
      unsigned long long totalTicks = 0;
      for(int i=0; i<CPU_STATE_MAX; i++) totalTicks += cpuinfo.cpu_ticks[i];
      return calculateCpuLoad(cpuinfo.cpu_ticks[CPU_STATE_IDLE], totalTicks);
   }
   else return -1.0f;
}


std::string CpuModule::exec(const char* cmd) 
{
    char buffer[128];
    std::string result = "";
    FILE* pipe = popen(cmd, "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    try {
        while (fgets(buffer, sizeof buffer, pipe) != NULL) {
            result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    return result;

    // std::array<char, 128>(buffer);
    // std::string result;
    // std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    // if (!pipe) {
    //     throw std::runtime_error("popen() failed!");
    // }
    // while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
    //     result += buffer.data();
    // }
    // return result;
}


void CpuModule::update(WINDOW *w, int *y)
{

	size_t sz;
    int32_t tmp;

    sz = sizeof(tmp);
    tmp = 0;

    //cores
	//sysctlbyname("machdep.cpu.core_count", &tmp, &sz, NULL, 0);
  //  printf("core count %d\n", tmp);
 //   //model
    //sysctlbyname("machdep.cpu.model", &tmp, &sz, NULL, 0);
    //printf("model %d\n", tmp);
    //threads
  //  sysctlbyname("hw.cpufrequency", &tmp, &sz, NULL, 0);
//    printf("name %d\n", tmp);

    // brand?
    //sysctlbyname("machdep.cpu.brand_string", &tmp, &sz, NULL, 0);
    //std::cout << system("sysctl -n machdep.cpu.brand_string") <<std::endl;



    char buff[256];

    std::string result = "";
    FILE* file = popen("top -l 1 | grep \"CPU usage\"", "r");
    while (fgets(buff, sizeof(buff), file) != NULL)
        result += buff;
    pclose(file);
    result.erase(result.find('\n', 0), 1);

    mvwprintw(w, (*y)++, getbegx(w)/2, "  - - - - - - -   CPU   - - - - - - - - - ");
    wattron(w, COLOR_PAIR(1));
    
    mvwprintw(w, (*y)++, getbegx(w) + 2, "%s", result.c_str());
    sysctlbyname("machdep.cpu.model", &tmp, &sz, NULL, 0); 
	mvwprintw(w, (*y)++, getbegx(w) + 2, "CPU Model: %d", tmp);
    sysctlbyname("machdep.cpu.core_count", &tmp, &sz, NULL, 0);
	mvwprintw(w, (*y)++, getbegx(w) + 2, "Core count: %d", tmp);
    sysctlbyname("hw.cpufrequency", &tmp, &sz, NULL, 0);
	mvwprintw(w, (*y)++, getbegx(w) + 2, "Threads: %d", tmp); //this->getOutput().c_str());
    mvwprintw(w, (*y)++, getbegx(w) + 2, "Model: %s", this->exec("sysctl -n machdep.cpu.brand_string").c_str());
    //ifconfig 
    wattroff(w, COLOR_PAIR(1));
    mvwprintw(w, (*y)++, getbegx(w)/2, "  - - - - - - - - - - - - - - - - - - - -  ");

}

CpuModule::CpuModule( void ) : IMonitorModule() //: _foo( 0 )
{
	std::cout << "CpuModule default constructor called\n";
    return;
}


CpuModule::CpuModule( int const n ) //: _foo( n ) 
{
	(void)n;
    std::cout << "CpuModule parametric Constructor called\n";
	return;
}

CpuModule::CpuModule( CpuModule const & src ) //: _foo(src.getFoo()) 
{
	std::cout << "Copy constructor called\n";
	*this = src;
	return;
}

CpuModule& CpuModule::operator=( const CpuModule &rhs_operand )
{
    (void)rhs_operand;
	std::cout << "CpuModule assignment constructor called\n";
	// some assignment ex: this->_fixed_point_val = rhs_operand.getRawBits();
	return (*this);
}

CpuModule::~CpuModule( void ) {

	//std::cout << "CpuModule destructor called\n";
	return;
}


