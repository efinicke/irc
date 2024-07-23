# ft_irc: Internet Relay Chat Server

## Skills

- **Network Programming**: Gained proficiency in socket programming and TCP/IP communication.
- **Concurrency**: Developed the ability to manage multiple clients simultaneously without using forking, ensuring non-blocking I/O operations.
- **Error Handling**: Enhanced skills in robust error checking and handling to prevent crashes and unexpected quits.
- **C++ 98 Standard**: Strengthened knowledge of C++ 98, including the use of standard libraries and features.
- **Team Collaboration**: Improved teamwork and collaboration skills through group work with peers from 42 School.

## Project Overview

This 42 project, ft_irc, is a group endeavor undertaken at 42 School alongside my colleagues Ejahan and Grannou. We collaborated to create an IRC server in C++ 98. Our goal was to implement a server that could handle multiple clients, facilitate real-time messaging, and support essential IRC functionalities such as authentication, nickname management, channel joining, and private messaging.

One of the significant challenges we faced was ensuring that our server could manage concurrent connections without hanging and without using forking. We utilized non-blocking I/O operations and a single `poll()` call to handle all read, write, and listen operations efficiently. Our implementation had to be robust enough to handle partial data, low bandwidth, and other common issues without crashing.

## Features

- **Multi-client Handling**: Supports multiple clients simultaneously without blocking or hanging.
- **Authentication**: Requires a password for clients to connect.
- **Nickname and Username Management**: Allows users to set their nicknames and usernames.
- **Channel Operations**: Clients can join and communicate in channels.
- **Private Messaging**: Supports private messages between users.
- **Operator Commands**:
  - **KICK**: Eject a client from a channel.
  - **INVITE**: Invite a client to a channel.
  - **TOPIC**: Change or view the channel topic.
  - **MODE**: Change the channel's mode with subcommands:
    - **i**: Invite-only channel.
    - **t**: Restrict topic changes to operators.
    - **k**: Set/remove channel key (password).
    - **o**: Grant/take channel operator privilege.
    - **l**: Set/remove user limit to channel.

## Content

- **Makefile**: The makefile to compile the source files with the rules `$(NAME)`, `all`, `clean`, `fclean`, and `re`.
- **Source Files**: 
  - **Header Files**: (`*.h`, `*.hpp`)
  - **Source Files**: (`*.cpp`, `*.tpp`, `*.ipp`)
- **Configuration File**: An optional configuration file for server settings.

## Usage

To run the IRC server, use the following command:

```sh
./ircserv <port> <password>

## Links 

- [Building IRC server](https://ircgod.com/posts/ircserver1/building-an-irc-server-1/)
- [HTTP Server: Everything you need to know to Build a simple HTTP server from scratch](https://medium.com/from-the-scratch/http-server-what-do-you-need-to-know-to-build-a-simple-http-server-from-scratch-d1ef8945e4fa)
- 