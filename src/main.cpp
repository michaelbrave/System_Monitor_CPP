/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 20:50:00 by jcruz-y-          #+#    #+#             */
/*   Updated: 2020/01/26 19:50:15 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_gkrellm.h"

int    usage()
{
    std::cout << "usage: [-t | -gui <mode>] [modules ...]\n";
    std::cout << "Modules:\n";
    std::cout << "-h hostname/username module\n";
    std::cout << "-o os info module\n";
    std::cout << "-d Date/Time module\n";
    std::cout << "-c CPU module\n";
    std::cout << "-r RAM module\n";
    std::cout << "-n network throuput module\n";
    std::cout << "-fcat a fcat dances?\n";
    return (1);
}


std::list<std::string>   get_args(int argc, char **argv) //, std::vector<IMonitorModule*>* vec)
{
    int                 i;
    std::list<std::string>   args;

    i = 1;
    while (i < argc)
    {
        if (std::string(argv[i]) == "-t")
            args.push_back("-t");
        else if (std::string(argv[i]) == "-gui")
            args.push_back("-gui");
        else if (std::string(argv[i]) == "-h")
            args.push_back("-h");
        else if (std::string(argv[i]) == "-o")
            args.push_back("-o");
        else if (std::string(argv[i]) == "-d")
            args.push_back("-d");
        else if (std::string(argv[i]) == "-c")
            args.push_back("-c");
        else if (std::string(argv[i]) == "-r")
            args.push_back("-r");
        else if (std::string(argv[i]) == "-n")
            args.push_back("-n");
        else if (std::string(argv[i]) == "-fcat")
            args.push_back("-fcat");
        else
            throw std::exception();
        i++;
    }
    return (args);
}


int     main(int argc, char **argv)
{
    int                                 i; 
    std::list<std::string>              args;


    if (argc < 2)
        return usage();
    i = 1;
    try
    {
        args = get_args(argc, argv);    
        if ((std::find(args.begin(), args.end(), "-t") != args.end()) ||
        std::find(args.begin(), args.end(), "-gui") != args.end())
        {
            TextDisplay text_d(args, argc);
            if (args.size() == 1)
            {
                text_d._modules.push_back(new HostnameModule);
                text_d._modules.push_back(new OsInfoModule);
                text_d._modules.push_back(new CpuModule);
                text_d._modules.push_back(new NewtowrkModule);
                text_d._modules.push_back(new DateTimeModule);
                text_d._modules.push_back(new RamModule);
                text_d._modules.push_back(new FCat);
            }    
            if (std::find(args.begin(), args.end(), "-h") != args.end()) 
                text_d._modules.push_back(new HostnameModule);
            if (std::find(args.begin(), args.end(), "-o") != args.end()) 
                text_d._modules.push_back(new OsInfoModule);
            if (std::find(args.begin(), args.end(), "-d") != args.end()) 
                text_d._modules.push_back(new DateTimeModule);
            if (std::find(args.begin(), args.end(), "-c") != args.end()) 
                text_d._modules.push_back(new CpuModule);
            if (std::find(args.begin(), args.end(), "-r") != args.end()) 
                text_d._modules.push_back(new RamModule);
            if (std::find(args.begin(), args.end(), "-n") != args.end()) 
                text_d._modules.push_back(new NewtowrkModule);
            if (std::find(args.begin(), args.end(), "-fcat") != args.end()) 
                text_d._modules.push_back(new FCat);
            text_d.run();
        }
        else
            throw std::exception();
    }
    catch(std::exception &e)
    {
        e.what();
        usage();
    }
    return (0);
}