/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 03:28:17 by grannou           #+#    #+#             */
/*   Updated: 2023/01/29 06:52:26 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Server.hpp"

// Variable to know server status (if signal interruption)
int    serverIsRunning = 1;

// Function to handle interruption signal
void    interruptServer(int signal)
{
    ssize_t ret = write(1, "\b\b", 2);
    if (ret < 0)
        std::cout << "\b\b" << std::endl;
    std::cout << YELLOW << "Interrupt signal (" << RESET << signal << YELLOW << ") received" << RESET << std::endl;
    serverIsRunning = 0;
}

// Set sigaction to handle interrupting signals
void    handleSignals(void)
{
    struct sigaction sigint_action;
    sigint_action.sa_handler = interruptServer;
    sigemptyset(&sigint_action.sa_mask);
    sigint_action.sa_flags = 0;
    sigaction(SIGINT, &sigint_action, NULL);
    sigaction(SIGTERM, &sigint_action, NULL);
}

int main(int argc, char **argv)
{
    //std::cout << CLEARLINE;

    if (checkArguments(argc, argv))
        return (1);

    handleSignals();

    Server      ircServ = Server(argv[1], argv[2]);

//    ircServ.setFd(initialiseSocket());

    if (ircServ.setup())
        return (printErrorMessage(INIT_SERVER_ERROR), 1);

    // Print Server infos
    std::cout << ircServ << std::endl;

    print_log("The server started successfully");

    while (serverIsRunning)
    {
        ircServ.run();
    }
    print_log("Shutting down server");
    
    // Clean free everything
    cleanExit();
    return (0);
}
