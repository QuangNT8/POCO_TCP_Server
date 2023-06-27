# Poco TCP Server Example

This repository contains a simple TCP server implemented in C++ using the POCO library. The server accepts incoming connections on a specified port and reverses a string entered by the client.
## Prerequisites

Before running the TCP server, make sure you have the following dependencies installed:

- POCO library: You can install the POCO library by running the following command in your terminal:

  ```bash
  sudo apt-get install libpoco-dev

## Building the Server

To build the TCP server, follow these steps:

1. Clone the repository or download the source code files.

2. Navigate to the project directory.

3. Run the following command to build the server:

   ```bash
   make
## Running the Server
- To run the TCP server, use the following command:
   ```bash  
   ./telnet <port>
- For example, to run the server on port 28888, use:
   ```bash
   ./telnet 28888
## Connecting to the Server
- To connect to the server and test its functionality, open another terminal and use the 'telnet' command:
   ```bash
   telnet localhost <port>
- For example, to connect to the server on port 28888, use:
   ```bash
   telnet localhost 28888
## Stopping the Server
To stop the server, press 'Ctrl + C' in the terminal where the server is running.

## Cleaning Up
To clean the build artifacts and remove the executable, use the following command:
   ```bash
   make clean