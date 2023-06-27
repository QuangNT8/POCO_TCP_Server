# TCP Server

This repository contains a simple TCP server implemented in C++ using the POCO library. The server accepts incoming connections on a specified port and reverses a string entered by the client.

## Prerequisites

Before running the TCP server, make sure you have the following dependencies installed:

- POCO library: Use the package manager or installation method appropriate for your Linux distribution to install the `libpoco-dev` package.

## Building the Server

To build the TCP server, follow these steps:

1. Clone the repository or download the source code files.

2. Navigate to the project directory.

3. Compile the server code using the following command:

   ```bash
   g++ -o tcp_server tcp_server.cpp -lPocoFoundation -lPocoNet
