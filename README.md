# ft_irc: Internet Relay Chat Server

## Skills
- Mastery of the C++ 98 standard and features
- Understanding and implementation of network protocols (TCP/IP)
- Handling non-blocking I/O operations
- Experience in concurrent client management
- Implementation of communication protocols and client-server architecture
- Collaborative development using Git

## Project Overview
`ft_irc` is a 42 project centered on developing a fully functional Internet Relay Chat (IRC) server using the C++ 98 standard. The main goal was to ensure compatibility with an official IRC client, providing a reliable and feature-complete experience. For testing and validation, we chose the popular IRC client **irssi** as our reference.
The project involves handling multiple clients simultaneously, maintaining responsiveness and security under various conditions. The server supports essential IRC functionalities, including user authentication, channel management, and private messaging, closely mirroring the behavior of established IRC networks.
Developed collaboratively by [Grannou](https://github.com/Grannou) and [Ejahan](https://github.com/Ejahan) from School 42.

## Features
- **Multi-client support**: The server can handle multiple simultaneous connections.
- **Basic IRC functionalities**:
  - User authentication
  - Setting nicknames and usernames
  - Joining and leaving channels
  - Sending and receiving private messages
  - Broadcasting messages to all clients in a channel

### Supported IRC Commands
The server supports the following IRC commands, implemented according to the IRC protocol specifications:
- **INVITE**: Invites a user to a channel.
- **JOIN**: Joins a specified channel.
- **KICK**: Removes a user from a channel.
- **KILL**: Disconnects a user from the server (admin command).
- **LIST**: Lists all channels or those matching a certain pattern.
- **MODE**: Changes the mode of a user or channel (e.g., setting channel restrictions or user privileges).
- **MOTD**: Retrieves the "Message of the Day" from the server.
- **NAMES**: Lists the users in a channel.
- **NICK**: Changes or sets a user's nickname.
- **NOTICE**: Sends a notice message to a user or channel (similar to PRIVMSG but cannot be responded to).
- **OPER**: Authenticates a user as an IRC operator.
- **PART**: Leaves a specified channel.
- **PASS**: Sets a connection password.
- **PING**: Checks the connection to the server.
- **PRIVMSG**: Sends a private message to a user or channel.
- **QUIT**: Disconnects from the IRC server.
- **TOPIC**: Sets or gets the topic of a channel.
- **USER**: Sets the username and other initial user details upon connecting.

- **Channel Operations**:
  - **Operators and Regular Users**: Differentiation and specific permissions
  - **Commands for Operators**:
    - `KICK`: Eject a client from a channel
    - `INVITE`: Invite a client to a channel
    - `TOPIC`: Change or view the channel topic
    - `MODE`: Modify channel settings (e.g., invite-only, topic restrictions, channel password, operator privileges, user limit)
- **Bonus Feature**:
  - **File Transfer using DCC**: Enables direct client-to-client file transfers.
  - **Chatbot**: Provides automated responses and interactions based on predefined commands or messages.


## Content

The project is organized as follows:
- **Makefile**: Used to compile the project.
- **chatBotMotd.txt**: Message of the Day for the chat bot.
- **dependencies/**: Dependency files for the build.
- **dependenciesBonus/**: Dependency files for bonus features.
- **includes/**: Header files (.hpp) defining the main structures and classes of the project.
- **motd.txt**: Message of the Day displayed to users upon connection.
- **proxy.sh**: Script for testing the server with a proxy.
- **srcs/**: Main source files of the project, including implementations of IRC commands and utility functions.
  - **Commands/**: Implementations of various IRC commands.
  - **Parsing/**: Files related to parsing and associated utilities.
- **srcsBonus/**: Source files for bonus features, such as DCC file transfers and chatBot.


## Usage

1. **Install `irssi`:**
   - Install `irssi` on your system using the following command:
     ```bash
     sudo apt-get install irssi
     ```

2. **Compile and Run the Server:**
   - Navigate to the directory containing the server code and compile it with:
     ```bash
     make
     ```
   - Start the server with:
     ```bash
     ./ircserv <port> <password>
     ```

3. **Set Up Netcat and `irssi`:**
   - Open a new terminal window and set up a Netcat listener with:
     ```bash
     nc -l -p 6667
     ```
   - In another terminal window, start `irssi`:
     ```bash
     irssi
     ```
   - Connect `irssi` to the server:
     ```
     /connect localhost 6667
     ```

4. **Testing with Commands:**
   - **Using Netcat:**
     - Set your nickname:
       ```
       NICK mynick
       ```
     - Join a channel:
       ```
       JOIN #testchannel
       ```
     - Send a message to the channel:
       ```
       PRIVMSG #testchannel :Hello, this is a test message.
       ```
     - List all channels:
       ```
       LIST
       ```
     - Quit the session:
       ```
       QUIT :Goodbye!
       ```
   - **Using `irssi`:**
     - Set your nickname:
       ```
       /nick mynick
       ```
     - Join a channel:
       ```
       /join #testchannel
       ```
     - Send a message to the channel:
       ```
       /msg #testchannel Hello, this is a test message.
       ```
     - List all channels:
       ```
       /list
       ```
     - Quit the session:
       ```
       /quit Goodbye!
       ```


## Links

- [How to Build a Simple HTTP Server from Scratch](https://medium.com/from-the-scratch/http-server-what-do-you-need-to-know-to-build-a-simple-http-server-from-scratch-d1ef8945e4fa)
- [Building an IRC Server: Part 1](https://ircgod.com/posts/ircserver1/building-an-irc-server-1/)
- [Nonblocking I/O and the select Function](https://www.ibm.com/docs/en/i/7.3?topic=designs-example-nonblocking-io-select)
- [RFC 2812: Internet Relay Chat (IRC)](https://datatracker.ietf.org/doc/html/rfc2812)
- [Wikipedia: Internet Relay Chat](https://fr.wikipedia.org/wiki/Internet_Relay_Chat)
- [YouTube: How to Build an IRC Server](https://www.youtube.com/watch?v=9J1nJOivdyw)
- [YouTube: Another IRC Server Tutorial](https://www.youtube.com/watch?v=xfRdYrQUQeQ)
- [SDZ: Les Sockets](http://sdz.tdct.org/sdz/les-sockets.html)
- [Oramind: How to Make an IRC Server Connection](https://oramind.com/tutorial-how-to-make-an-irc-server-connection/)
- [Microsoft Documentation: Winsock recv Function](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-recv)

